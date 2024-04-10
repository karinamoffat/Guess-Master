<?php

$query = "SELECT * FROM RentalGroup";
$result = $connection->query($query);

echo "<h2 class='properties'>Select your rental group: </h2></br>";

while ($row = $result->fetch()) {
	echo '<div class="group-codes"><input type="radio" name="groupcode" value="' . $row["Code"] . '">';
	echo "<h3 class='group-codes'>" . $row["Code"] . "</h3></div></br>";
}
?>