<?php 

$HOST = "localhost";
$USERNAME = "root";
$PASSWORD = "";
$DATABASE = "kuliah_web";

$conn = mysqli_connect($HOST, $USERNAME, $PASSWORD, $DATABASE);

if(!$conn){
    echo "Connection Failed!";
}
