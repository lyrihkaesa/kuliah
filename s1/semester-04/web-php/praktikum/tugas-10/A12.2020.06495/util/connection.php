<?php

$HOST = "localhost";
$USERNAME = "root";
$PASSWORD = "";
$DATABASE = "kuliah_web";

// Create connection
$conn = mysqli_connect($HOST, $USERNAME, $PASSWORD, $DATABASE);

// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}
//   echo "Connected successfully";
