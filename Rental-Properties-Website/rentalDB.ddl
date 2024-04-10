drop database if exists rentalDB;
create database rentalDB;

create table People(
    ID char(6) not null primary key,
    FName varchar(20) not null,
    LName varchar(20) not null,
    Phone char(10) not null);

create table Property(
    ID int not null primary key,
    Accessibility varchar(3),
    Street varchar(60),
    City varchar(60),
    Province varchar(2),
    PC varchar(7),
    ApartmentNum int,
    NumBedroom int,
    NumBathroom int,
    Parking varchar(3),
    LaundryType varchar(20),
    MonthCost decimal(6,2),
    ListDate date);

create table PropertyManager(
    PMID char(6) not null,
    PropertyID int not null,
    ManagerStartYear int,
    primary key(PMID, PropertyID),
    foreign key(PropertyID) references Property(ID) on delete cascade,
    foreign key(PMID) references People(ID) on delete cascade);

create table RentalGroup(
    Code int not null primary key,
    TypePreference varchar(10),
    RentPreference decimal(6,2),
    OtherPreferences varchar(50),
    PropertyID int,
    LeaseSignDate date,
    LeaseEndDate date,
    MonthlyCost decimal(6,2),
    foreign key(PropertyID) references Property(ID));

create table Owner(
    OID char(6) not null primary key,
    foreign key(OID) references People(ID) on delete cascade);

create table Renter(
    RID char(6) not null primary key,
    GradYear int,
    StuID int,
    Program varchar(20),
    RGCode int not null,
    foreign key(RGCode) references RentalGroup(Code),
    foreign key(RID) references People(ID) on delete cascade);

create table Room(
    RoomID int not null primary key,
    KitchenPrivileges varchar(3),
    NumOccupants int,
    foreign key(RoomID) references Property(ID) on delete cascade);

create table RoomFurnishings(
    FurnishRoomID int not null primary key,
    Furnishings varchar(255),
    foreign key(FurnishRoomID) references Room(RoomID) on delete cascade);

create table Apartment(
    ApartmentID int not null primary key,
    Elevator varchar(3),
    FloorNum integer,
    foreign key(ApartmentID) references Property(ID) on delete cascade);

create table House(
    HouseID int not null primary key,
    AttachmentType varchar(10),
    FencedYard varchar(3),
    foreign key(HouseID) references Property(ID) on delete cascade);

create table Owns(
    PropertyID int not null,
    OwnerID char(6) not null,
    primary key (PropertyID, OwnerID),
    foreign key(PropertyID) references Property(ID) on delete cascade,
    foreign key(OwnerID) references Owner(OID));

insert into People values
('AB123','John','Smith','4161234567'),
('CD345','Evan','Cunningham','9058873393'),
('EF456','Sahanya','Viswasm','2193394857'),
('GH567','Hannah','Morris','4167193498'),
('IJ678','Jake','Reid','9054871945'),
('KL789','Bradley','Cooper','6472294312'),
('MN901','Jason','Vickery','4167809987'),
('OP012','Sophia','Viola','9053128845'),
('QR234','Ivan','Deborgsky','4168903459'),
('ST345','Max','McCormick','9057210946'),
('UV456','Aidan','Lanoue','4167340957'),
('WX567','Emily','Basil','9058934502'),
('ID938','Claire','Mooney','4168370938'),
('EK038','Audrey','Watson','9057839448'),
('KJ384','Kelsey','Chung','4167290047'),
('EM830','Maya','Tsipe','2093335839'),
('DM938','Brayden','Makowich','6475298847'),
('JM338','Payten','Travers','9052938822'),
('FI324','Cole','Patrick','4163240044'),
('IK390','Spencer','Smith','9056632244'),
('WD903','Michael','Dennis','4165593302'),
('MN384','Dylan','Gust','9053340275'),
('RJ485','Jordan','Raftis','4165439944'),
('YZ789','Caroline','Sylvester','9052593602'),
('JS098','Jasmine','Taylor','4167859034'),
('IJ489','Paige','Babb','9057893409'),
('FH909','Nigel','Piotrowski','4167923095'),
('EJ138','Sagaana','Sheth','9057451009'),
('MY984','Alexander','Lamana','4163337777')
;

insert into Property values
(1234,'yes','Johnson Street','Kingston','ON','K8M 2N9',null,6,2,'yes','ensuite',865.00,'2023-01-20'),
(1235,'yes','Brock Street','Kingston','ON','K7L 2Y4',null,5,2,'yes','shared',799.00,'2023-07-19'),
(1249,'no','Earl Street','Kinsgton','ON','K7L 3M6',3,2,1,'no','ensuite',650.00,'2023-02-09'),
(1259,'yes','University Avenue','Kingston','ON','K7L 4K9',2,4,1,'yes','shared',1024.00,'2023-04-20'),
(3290,'no','Barrie Street','Kingston','ON','K7M 1I8',null,5,2,'yes','ensuite',520.00,'2023-10-10'),
(3280,'yes','Frontenac Street','Kingston','ON','K7L 1Z9',null,7,2,'no','ensuite',829.00,'2023-03-10'),
(2834,'yes','Johnson Street','Kingston','ON','K7L 2M8',null,7,2,'yes','shared',1024.50,'2023-04-07'),
(2543,'no','Union Street','Kingston','ON','K7M 3M2',null,5,2,'no','shared',626.00,'2023-05-25'),
(1435,'yes','Napier Street','Kingston','ON','L9R 3I9',3,2,1,'no','shared',400.00,'2023-06-27'),
(3209,'no','Victoria Street','Kingston','ON','L3M 4M0',null,6,3,'no','ensuite',945.00,'2023-04-20'),
(1598,'yes','Earl Street','Kingston','ON','L4I 5N9',null,6,3,'yes','ensuite',854.00,'2023-08-05'),
(2985,'yes','Brock Street','Kingston','ON','L4M 9R0',5,2,1,'yes','shared',650.00,'2023-10-15'),
(3928,'yes','Beverly Street','Kingston','ON','J4M 8N4',null,5,2,'no','shared',720.50,'2023-01-09'),
(1983,'no','Princess Street','Kingston','ON','K8M 9R4',9,4,2,'yes','ensuite',999.99,'2023-03-15'),
(1538,'yes','Albert Street','Kingston','ON','K9M 4N2',null,6,2,'yes','shared',828.49,'2023-09-11'),
(1540,'no','Alfred Street','Kingston','ON','L4M 7N4',4,3,1,'no','ensuite',500.00,'2023-06-20'),
(1620,'yes','Collingwood Street','Kingston','ON','L5X 4S8',null,8,3,'yes','ensuite',950.00,'2023-05-13'),
(3286,'no','Division Street','Kingston','ON','L4N 8E4',null,4,2,'no','shared',759.00,'2023-02-28')
;

insert into PropertyManager values
('AB123',1234,2020),
('AB123',1235,2020),
('AB123',1983,2020),
('AB123',1540,2020),
('CD345',1249,2022),
('CD345',1259,2022),
('CD345',1598,2022),
('EF456',3290,2019),
('EF456',2543,2019),
('EF456',1435,2019),
('EF456',1538,2019),
('GH567',2834,2020),
('GH567',3928,2020),
('GH567',3280,2020),
('IJ678',3209,2018),
('IJ678',2985,2018),
('KL789',3286,2019),
('KL789',1620,2019)
;

insert into RentalGroup values
(1987,'House',1000.00,'7 bedrooms, 2 bathrooms',2834,'2023-04-07','2024-04-30',1024.50),
(9876,'Apartment',800.00,'2 bedrooms',2985,'2023-02-09','2024-04-30',650.00),
(8765,'Apartment',500.00,'3 bedrooms, 1 bathroom',1540,'2023-06-20','2025-04-30',500.00),
(7654,'House',500.00,'5 bedrooms, 2 bathrooms',3290,'2023-10-10','2025-04-30',520.00)
;

insert into Owner values
('YZ789'),
('JS098'),
('IJ489'),
('FH909'),
('EJ138'),
('MY984')
;

insert into Renter values
('MN901',2025,20265789,'Computer Science',1987),
('OP012',2025,20265799,'Commerce',1987),
('QR234',2026,20265701,'Chemical Engineering',1987),
('ST345',2026,20265705,'Physics',1987),
('UV456',2025,20265730,'Commerce',1987),
('WX567',2027,20265731,'Mathematics',1987),
('ID938',2026,20265702,'Civil Engineering',1987),
('EK038',2026,20265703,'Life Sciences',9876),
('KJ384',2026,20265704,'Nursing',9876),
('EM830',2026,20265706,'Engineering Physics',8765),
('DM938',2026,20265707,'Commerce',8765),
('JM338',2026,20265708,'Life Sciences',8765),
('FI324',2026,20265709,'Kinesiology',7654),
('IK390',2026,20265710,'Computer Engineering',7654),
('WD903',2026,20265711,'Computer Engineering',7654),
('MN384',2026,20265712,'Music',7654),
('RJ485',2026,20265713,'English',7654)
;

insert into Room values
(1235,'yes',5),
(3280,'yes',7),
(2543,'no',4),
(1538,'yes',6),
(1620,'no',8),
(3286,'yes',4)
;

insert into RoomFurnishings values
(1235,'Lamp, desk, chair, bed'),
(3280,'Bed, desk, chair'),
(2543,'Bed, table, couch'),
(1538,'Bed, desk, lamp, couch'),
(1620,'Bed, desk'),
(3286,'Bed, chair, lamp')
;

insert into Apartment values
(1249,'yes',6),
(1259,'no',2),
(1435,'no',3),
(2985,'yes',5),
(1983,'no',2),
(1540,'yes',9)
;

insert into House values
(1234,'semi','yes'),
(3290,'semi','no'),
(2834,'detached','yes'),
(3209,'semi','no'),
(1598,'detached','yes'),
(3928,'semi','no')
;

insert into Owns values
(1234,'YZ789'),
(1235,'YZ789'),
(1249,'JS098'),
(1259,'JS098'),
(3290,'JS098'),
(3280,'IJ489'),
(2834,'FH909'),
(2543,'EJ138'),
(1435,'EJ138'),
(3209,'EJ138'),
(1598,'IJ489'),
(2985,'MY984'),
(3928,'YZ789'),
(1983,'JS098'),
(1538,'EJ138'),
(1540,'FH909'),
(1620,'IJ489'),
(3286,'MY984')
;