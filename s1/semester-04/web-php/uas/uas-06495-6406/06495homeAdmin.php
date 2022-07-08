<?php session_start() ?>
<!DOCTYPE html>
<html>

<head>
	<title>Halaman Home Admin</title>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" type="text/css" href="bootstrap4/css/bootstrap.css">
	<link rel="stylesheet" type="text/css" href="css/styleku.css">
	<script src="bootstrap4/jquery/3.3.1/jquery-3.3.1.js"></script>
	<script src="bootstrap4/js/bootstrap.js"></script>
</head>

<body>
	<?php
	//memanggil file berisi fungsi2 yang sering dipakai
	require "06495fungsi.php";
	require "06495head.html";

	//cek logout
	if (!isset($_SESSION['username'])) {
		header("location:06495index.php");
	}
	?>
	<div class="utama">
		<br><br>
		<h1 class="text-center">Selamat Datang di Halaman Administrator saudara <?php echo strtoupper($_SESSION['username']) ?></h1>
	</div>
</body>

</html>