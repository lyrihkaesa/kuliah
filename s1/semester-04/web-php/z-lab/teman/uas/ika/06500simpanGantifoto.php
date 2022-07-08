<?php
//panggil file fungsi
require "06500fungsi.php";

$id = $_POST['id'];
//Set lokasi dan nama file foto
$folderupload = "foto/";
$fileupload = $folderupload . basename($_FILES['foto']['name']);
$filefoto = basename($_FILES['foto']['name']);
$uploadOk = 1;

//ambil jenis file
$jenisfilefoto = strtolower(pathinfo($fileupload, PATHINFO_EXTENSION));

// Check jika file foto sudah ada
if (file_exists($fileupload)) {
	echo "Maaf, file foto sudah ada<br>";
	$uploadOk = 0;
}

// Check ukuran file
if ($_FILES["foto"]["size"] > 1000000) {
	echo "Maaf, ukuran file foto harus kurang dari 1 MB<br>";
	$uploadOk = 0;
}

// Hanya file tertentu yang dapat digunakan
if (
	$jenisfilefoto != "jpg" && $jenisfilefoto != "png" && $jenisfilefoto != "jpeg"
	&& $jenisfilefoto != "gif"
) {
	echo "Maaf, hanya file JPG, JPEG, PNG & GIF yang diperbolehkan<br>";
	$uploadOk = 0;
}

// Check jika terjadi kesalahan
if ($uploadOk == 0) {
	echo "Maaf, file tidak dapat terupload<br>";
	// jika semua berjalan lancar
} else {
	if (move_uploaded_file($_FILES["foto"]["tmp_name"], $fileupload)) {
		//membuat query
		//echo $id." - ".$fileupload;exit;
		$sql = "update mhs set foto='$filefoto' where id='$id'";
		mysqli_query($koneksi, $sql) or die(mysqli_error($koneksi));
		header("location:06500updateMhs.php");
	} else {
		echo "Maaf, terjadi kesalahan saat mengupload file foto<br>";
	}
}
