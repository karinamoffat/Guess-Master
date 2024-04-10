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

<body>

<?php
include 'connectdb.php';
?>

<h1 class="update-preferences">Update Preferences</h1>

<h3 class="preferences-list">Select which preference you would like to update: </h3> <!--add to stylesheet-->

<p class="update-preferences"><form action="addnewpreferences.php" method="post">

Rental Group Code: <input type="text" name="groupcode"><br>
<input type="radio" name="preferencetype" value="typepreference">Accommodation Preference<br>
<input type="radio" name="preferencetype" value="rentpreference">Max Rent Preference<br>
<input type="radio" name="preferencetype" value="otherpreferences">Other Preferences<br>

Update preference here: <input type="text" name="updatepreference"><br>

<input type="submit" value="Update Preference"></p>

<h4><a href="rental.html"><h4>Return Home</a></h4>

</form>

<?php
$connection =- NULL;
?>

</body>