<!DOCTYPE html>
<html lang="en">
<head>

    <title>Rental Properties</title>
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Carter+One&family=Lalezar&display=swap" rel="stylesheet">
    <link rel="stylesheet" type="text/css" href="styles.css">
    <base href="http://localhost/">
    <PHP> echo '<link rel="stylesheet" type="text/css" href="style.css">'; <PHP>
</head>

<body> 

<?php
include 'connectdb.php';
?>   


<header class="header-main">
        <div class="header-main-logo">
            <img class="header-main-logo" src="img\kingston-condo.jpg" alt="condo">
            <h1 class="header-main-title"><a href="rental.html">KINGSTON RENTAL PROPERTIES</a></h1>
            <nav class="header-main-nav">
                <ul class="header-main-nav">
                    <li class="header-main-nav"><a href="about.html"><strong>ABOUT US</strong></a></li>
                    <li class="header-main-nav"><a href="properties.php"><strong>PROPERTIES</strong></a></li>
                    <li class="header-main-nav"><a href="rental-groups.php"><strong>RENTAL GROUPS</strong></a></li>
                </ul>
            </nav>
        </div>
    </header>

        <h2 class="properties">Kingston Properties</h2>

    <?php
    //first, get information for apartments
    $query1 = 'SELECT * FROM Apartment';
    $query2 = 'SELECT FName, LName FROM People 
                LEFT JOIN Owner ON People.ID = Owner.OID 
                LEFT JOIN Owns ON Owner.OID = Owns.OwnerID 
                INNER JOIN Apartment ON Owns.PropertyID = Apartment.ApartmentID' ;
    $query3 = 'SELECT FName, LName FROM People
                LEFT JOIN PropertyManager ON People.ID = PropertyManager.PMID
                INNER JOIN Apartment ON PropertyManager.PropertyID = Apartment.ApartmentID' ;
    $result1 = $connection->query($query1);
    $result2 = $connection->query($query2);
    $result3 = $connection->query($query3);

    echo "<table><tr><th class='property-list'>Property ID</th><th class='property-list'>Property Type</th><th class='property-list'>Owner</th><th class='property-list'>Manager</th></tr>";
    while($row1=$result1->fetch()) {
        if($row3=$result3->fetch()) {
            if($row2=$result2->fetch()) {
                echo "<tr><td class='property-list'>" . $row1["ApartmentID"] . "</td><td class='property-list'>Apartment</td><td class='property-list'>" . $row2["FName"] . " " . $row2["LName"] . "</td><td class='property-list'>" . $row3["FName"] . " " . $row3["LName"] . "</td>";
            }
        }
    }

    //second, get information for houses
    $query1 = 'SELECT * FROM House';
    $query2 = 'SELECT FName, LName FROM People 
                LEFT JOIN Owner ON People.ID = Owner.OID 
                LEFT JOIN Owns ON Owner.OID = Owns.OwnerID 
                INNER JOIN House ON Owns.PropertyID = House.HouseID' ;
    $query3 = 'SELECT FName, LName FROM People
                LEFT JOIN PropertyManager ON People.ID = PropertyManager.PMID
                INNER JOIN House ON PropertyManager.PropertyID = House.HouseID' ;
    $result1 = $connection->query($query1);
    $result2 = $connection->query($query2);
    $result3 = $connection->query($query3);

    while($row1=$result1->fetch()) {
        if($row3=$result3->fetch()) {
            if($row2=$result2->fetch()) {
                echo "<tr><td class='property-list'>" . $row1["HouseID"] . "</td><td class='property-list'>House</td><td class='property-list'>" . $row2["FName"] . " " . $row2["LName"] . "</td><td class='property-list'>" . $row3["FName"] . " " . $row3["LName"] . "</td>";
            }
        }
    }

    $query1 = 'SELECT * FROM Room';
    $query2 = 'SELECT FName, LName FROM People 
                LEFT JOIN Owner ON People.ID = Owner.OID 
                LEFT JOIN Owns ON Owner.OID = Owns.OwnerID 
                INNER JOIN Room ON Owns.PropertyID = Room.RoomID' ;
    $query3 = 'SELECT FName, LName FROM People
                LEFT JOIN PropertyManager ON People.ID = PropertyManager.PMID
                INNER JOIN Room ON PropertyManager.PropertyID = Room.RoomID' ;
    $result1 = $connection->query($query1);
    $result2 = $connection->query($query2);
    $result3 = $connection->query($query3);

    while($row1=$result1->fetch()) {
        if($row3=$result3->fetch()) {
            if($row2=$result2->fetch()) {
                echo "<tr><td class='property-list'>" . $row1["RoomID"] . "</td><td class='property-list'>Room</td><td class='property-list'>" . $row2["FName"] . " " . $row2["LName"] . "</td><td class='property-list'>" . $row3["FName"] . " " . $row3["LName"] . "</td>";
            }
        }
    }
    echo "</table>";
    ?>

    <h2 class="average-rents"><a href="averagerents.php"><h2>See today's average rents</a></h2>

</body>
</html>
