<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>Rental Groups - Update Preferences</title>
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Carter+One&family=Lalezar&display=swap" rel="stylesheet">
    <link rel="stylesheet" type="text/css" href="styles.css">
    <base href="http://localhost/">
</head>


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

<body>
<?php
   include 'connectdb.php';
?>
<ol>
<?php

   $whichCode = $_POST["groupcode"];
   $whichPreference = $_POST["preferencetype"];
   $newPreference = $_POST["updatepreference"];

   //need to match the group code, then the proper preference, and then repalce what is there with the user input

   $query = 'UPDATE RentalGroup SET ' . $whichPreference . ' = "' . $newPreference . '" WHERE RentalGroup.Code = ' . $whichCode . '';

   //$result= $connection->query($query); //a query is only used to execute sql
   $numRows = $connection->exec($query);
   echo "Your preference was updated!";
   $connection = NULL;

?>
</ol>

<h4><a href="rental.html"><h4>Return Home</a></h4>

</body>
</html>