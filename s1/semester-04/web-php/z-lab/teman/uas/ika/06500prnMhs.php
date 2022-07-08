<?php
// memanggil file berisi fungsi2 yang sering dipakai
require "06500fungsi.php";

$sql = "select * from mhs";
//Ambil data untuk ditampilkan
$hasil = mysqli_query($koneksi, $sql) or die(mysqli_error($koneksi));

?>


<!DOCTYPE html>
<html>

<head>
    <title>Sistem Informasi Akademik::Daftar Mahasiswa</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" href="bootstrap4/css/bootstrap.css">
    <link rel="stylesheet" type="text/css" href="css/styleku.css">
    <script src="bootstrap4/jquery/3.3.1/jquery-3.3.1.js"></script>
    <script src="bootstrap4/js/bootstrap.js"></script>
    <!-- Use fontawesome 5-->
    <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.0/css/all.css" integrity="sha384-lZN37f5QGtY3VHgisS14W3ExzMWZxybE1SJSEsQp9S+oqd12jhcu+A56Ebc1zFSJ" crossorigin="anonymous">
    <script>
        /*function cetak(hal) {
		  var xhttp;
		  var dtcetak;	
		  xhttp = new XMLHttpRequest();
		  xhttp.onreadystatechange = function() {
			if (this.readyState == 4 && this.status == 200) {
			  dtcetak= this.responseText;
			}
		  };
		  xhttp.open("GET", "ajaxUpdateMhs.php?hal="+hal, true);
		  xhttp.send();
		}*/
    </script>
</head>

<body>
    <div class="container-fluid">
        <div class="text-center mb-4">
            <h1>Daftar Mahasiswa</h1>
            <h2>By Ika Arum Maywulan Saputri - A12.2020.06500</h2>
            <a href="06500updateMhs.php" class="btn btn-success">Kembali</a>
        </div>
        <!-- Cetak data dengan tampilan tabel -->
        <table class="table table-hover">
            <thead class="">
                <tr>
                    <th>No.</th>
                    <th>NIM</th>
                    <th>Nama</th>
                    <th>Email</th>
                    <th>No HP</th>
                    <th>Foto</th>
                </tr>
            </thead>
            <tbody>
                <?php
                $no = 1;
                while ($row = mysqli_fetch_assoc($hasil)) {
                ?>
                    <tr>
                        <td><?php echo $no ?></td>
                        <td><?php echo $row["nim"] ?></td>
                        <td><?php echo $row["nama"] ?></td>
                        <td><?php echo $row["email"] ?></td>
                        <td><?php echo $row["nohp"] ?></td>
                        <td><img src="<?php echo "foto/" . $row["foto"] ?>" height="50"></td>
                    </tr>
                <?php
                    $no++;
                }
                ?>
            </tbody>
        </table>
    </div>
</body>

</html>