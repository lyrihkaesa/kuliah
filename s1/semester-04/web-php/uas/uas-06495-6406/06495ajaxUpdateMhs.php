<?php
//memanggil file berisi fungsi2 yang sering dipakai
require "06495fungsi.php";

//jumlah data per halaman
$jmlDataPerHal = 3;

//cari jumlah data
$sql = "select * from mhs";
$qry = mysqli_query($koneksi, $sql) or die(mysqli_error($koneksi));
$jmlData = mysqli_num_rows($qry);

//cari jumlah halaman
$jmlHal = ceil($jmlData / $jmlDataPerHal);
if (isset($_GET['hal'])) {
	$halAktif = $_GET['hal'];
} else {
	$halAktif = 1;
}

//tentukan data awal setiap halaman
$awalData = ($jmlDataPerHal * $halAktif) - $jmlDataPerHal;

//ambil data untuk dicetak
$sql = "select * from mhs limit $awalData,$jmlDataPerHal";
$hasil = mysqli_query($koneksi, $sql) or die(mysqli_error($koneksi));
