<!DOCTYPE html>
<html lang="en">
<head>

    <title>Rental Properties</title>
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Carter+One&family=Lalezar&display=swap" rel="stylesheet">
    <link rel="stylesheet" type="text/css" href="styles.css">
    <base href="http://localhost/">
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

    <?php

    $query = 'SELECT ROUND(AVG(MonthCost), 2) AS average_apartment_cost FROM Property
    INNER JOIN Apartment ON Property.ID = Apartment.ApartmentID' ;
    $result = $connection->query($query);

    echo "<table>";

    while($row = $result->fetch()) {
    echo "<tr><td class='average-rents'> Apartment Average Rent: " . $row["average_apartment_cost"] . "</td><td>";
    }

    $query = 'SELECT ROUND(AVG(MonthCost), 2) AS average_room_cost FROM Property
                INNER JOIN Room ON Property.ID = Room.RoomID' ;
    $result = $connection->query($query);
    
    while($row = $result->fetch()) {
        echo "<tr><td class='average-rents'> Room Average Rent: " . $row["average_room_cost"] . "</td><td>";
    }

   $query = 'SELECT ROUND(AVG(MonthCost), 2) AS average_house_cost FROM Property
                INNER JOIN House ON Property.ID = House.HouseID' ;
    $result = $connection->query($query);
    while($row = $result->fetch()) {
        echo "<tr><td class='average-rents'> House Average Rent: " . $row["average_house_cost"] . "</td><td>";
    }

    echo "</table>";

    ?>

</body>
</html>
