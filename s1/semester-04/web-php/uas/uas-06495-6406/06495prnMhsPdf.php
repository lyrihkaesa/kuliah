<?php
require_once __DIR__ . '/vendor/autoload.php';
require "06495fungsi.php";

$mpdf = new \Mpdf\Mpdf();

// Write some HTML code:

$mpdf->WriteHTML('
	<!DOCTYPE html>
	<html>
	<head>
	    <title>Sistem Informasi Akademik::Daftar Mahasiswa</title>
	    <meta charset="utf-8">
	    <meta name="viewport" content="width=device-width, initial-scale=1">
		<link rel="stylesheet" type="text/css" href="css/stylepdf.css">
	</head>
	<body>
	<h1>Daftar Mahasiswa<br>
	<sub>Sistem Informasi - Fakultas Ilmu Komputer - Universitas Dian Nuswantoro<sub><br>
	<small>Tahun Akademik 2020-2021</small></h1>
	<table>	
	<tr>
		<th>No.</th>
		<th>NIM</th>
		<th>Nama</th>
		<th>Email</th>
		<th>No HP</th>
	</tr>
	');
$sql = "select * from mhs";
$qry = mysqli_query($koneksi, $sql) or die(mysqli_error($koneksi));
$no = 0;
while ($row = mysqli_fetch_assoc($qry)) {
	$no++;
	$mpdf->WriteHTML('
	<tr>
		<td>' . $no . '</td>
		<td>' . $row["nim"] . '</td>
		<td>' . $row["nama"] . '</td>
		<td>' . $row["email"] . '</td>
		<td>' . $row["nohp"] . '</td>
	</tr>
	');
}
$mpdf->WriteHTML('</table>');
$mpdf->WriteHTML('</body></html>');
// Output a PDF file directly to the browser
$mpdf->Output();
