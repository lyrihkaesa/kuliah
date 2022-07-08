<?php session_start() ?>
<!DOCTYPE html>
<html>

<head>
	<title>Login Sistem</title>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" type="text/css" href="bootstrap4/css/bootstrap.css">
	<script src="bootstrap4/js/bootstrap.js"></script>
	<script src="bootstrap4/jquery/3.3.1/jquery-3.3.1.js"></script>
</head>

<body>
	<div class="container">
		<div class="w-25 mx-auto text-center mt-5">
			<div class="card bg-dark text-light">
				<div class="card-body">
					<h2 class="card-title">LOGIN</h2>
					<form method="post" action="">
						<div class="form-group">
							<label for="username">Nama user</label>
							<input class="form-control" type="text" name="username" id="username" autofocus>
						</div>
						<div class="form-group">
							<label for="passw">Password</label>
							<input class="form-control" type="password" name="passw" id="passw">
						</div>
						<div>
							<button class="btn btn-info" type="submit">Login</button>
						</div>
					</form>
				</div>
			</div>
		</div>
	</div>
	<?php
	if (isset($_POST['username'])) {
		require "06500fungsi.php";
		$username = $_POST['username'];
		$passw = md5($_POST['passw']);
		$sql = "select * from user where username='$username' and password='$passw'";
		$hasil = mysqli_query($koneksi, $sql) or die(mysqli_error($koneksi));
		$row = mysqli_fetch_assoc($hasil);
		if (mysqli_affected_rows($koneksi) > 0) {
			$_SESSION['username'] = $username;
			header("location:06500homeadmin.php");
		} else {
			echo "<div class='alert alert-danger w-25 mx-auto text-center mt-1 alert-dismissible'>
			<button type='button' class='close' data-dismiss='alert'>&times;</button>
			Maaf, login gagal. Ulangi login.
			</div>";
		}
	}
	?>
</body>

</html>