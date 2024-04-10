<!DOCTYPE html>
<html lang="en">

<!--this is the code used to display values for the selected rental group!-->
<head>

    <meta charset="utf-8">
    <title>Rental Groups</title>
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
 //Match selected code to code in renter (so we match students to their group)
    $whichCode = $_POST["groupcode"];

    //get renters in rental group
    $query = 'SELECT * FROM People INNER JOIN Renter ON People.ID = Renter.RID INNER JOIN RentalGroup ON Renter.RGCode = RentalGroup.Code WHERE RentalGroup.Code = ' . $whichCode .'';
    
    $result=$connection->query($query);

    echo "<table>";
    if ($row = $result->fetch())
        echo "<h3 class='preferences-list'><strong>Preferences: " . $row["TypePreference"] . ", " . $row["RentPreference"] . ", " . $row["OtherPreferences"] . "</strong></h3><br>";
    
    echo "<tr><th class='property-list'>Renters</th></tr>";

    while($row=$result->fetch()) {
        echo "<tr><td class='property-list'>" . $row["FName"] . " " . $row["LName"] . "</td><td>";
    }
    echo "</table>";
?>

<!--format this to look like a button when it is actually just a link at bottom of the page-->
<h2 class='average-rents'><a href="updatepreferences.php"><h2>Update Group Preferences</a></h2>



</table>
<?php
    $connection=NULL;
?>

</body>
</html>
