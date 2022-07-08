<?php
//memanggil file pustaka fungsi
require "06500fungsi.php";

//memindahkan data kiriman dari form ke var biasa
$id = $_POST["id"];
$nama = $_POST["nama"];
$email = $_POST["email"];
$nohp = $_POST["nohp"];
$uploadOk = 1;

//membuat query
$sql = "update mhs set nama='$nama',
					 email='$email',
					 nohp='$nohp',
					 where id='$id'";
mysqli_query($koneksi, $sql) or die(mysqli_error($koneksi));
header("location:06500homeadmin.php");
