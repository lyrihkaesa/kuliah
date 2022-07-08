<!DOCTYPE html>
<html>

<head>
	<title>Sistem Informasi Akademik::Mengganti Foto Mahasiswa</title>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" type="text/css" href="bootstrap4/css/bootstrap.css">
	<link rel="stylesheet" type="text/css" href="css/styleku.css">
	<script src="bootstrap4/jquery/3.3.1/jquery-3.3.1.js"></script>
	<script src="bootstrap4/js/bootstrap.js"></script>
</head>

<body>
	<?php
	//panggil file pustaka fungsi
	require "06500fungsi.php";

	//buat query
	$id = $_GET['id'];
	$sql = "select * from mhs where id='$id'";
	$hasil = mysqli_query($koneksi, $sql) or die(mysqli_error($koneksi));
	$row = mysqli_fetch_assoc($hasil);

	//panggil file layout header
	require "06500head.html";
	?>
	<div class="utama">
		<h2 class="mb-5 text-center">GANTI FOTO MAHASISWA</h2>
		<div class="row">
			<div class="col-sm-4">
				<div class="text-center">
					<img class="img-fluid" src="foto/<?php echo $row['foto'] ?>">
					<p><?php echo $row['nim'] . " - " . $row['nama'] ?></p>
				</div>
			</div>
			<div class="col-sm-8">
				<form class="form-inline" method="post" action="06500simpanGantifoto.php" enctype="multipart/form-data">
					<input class="form-control mr-2" type="file" name="foto" id="foto">
					<input type="hidden" name="id" value="<?php echo $id ?>">
					<button class="btn btn-primary" type="submit">Simpan</button>
				</form>
			</div>
		</div>
	</div>
</body>

</html>