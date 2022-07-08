<?php
include "06495fungsi.php";
$idmatkul = $_GET['qnim1'] . "." . $_GET['qnim2'];
$sql = "select namamatkul from matkul where idmatkul='$idmatkul'";
$qry = mysqli_query($koneksi, $sql) or die(mysqli_error($koneksi));
$hsl = mysqli_fetch_row($qry);
echo $hsl[0];
