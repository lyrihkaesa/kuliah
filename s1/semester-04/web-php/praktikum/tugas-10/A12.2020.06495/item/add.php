<?php
session_start();

if (!isset($_SESSION['id'])) {
    header("Location: ../login.php");
    exit();
}
require dirname(__DIR__) . "/util/function.php";
require dirname(__DIR__) . "/item/upload-image.php";

$modal = false;
$message = "Gagal ditambahkan!";
$namaBarang = "";
$hargaBarang = "";
$gambarBarang = "";

if (isset($_FILES["gambar-barang"])) {
    $uploadImage = uploadImageItem($_FILES["gambar-barang"]);
}


if (isset($_POST["add-item"])) {
    $modal = true;
    $request = [
        "kodeBarang" => $_POST["kode-barang"],
        "namaBarang" => $_POST["nama-barang"],
        "hargaBarang" => $_POST["harga-barang"],
        "gambarBarang" => $uploadImage["name"]
    ];
    if (insert($request) > 0) {
        $message = "Berhasil ditambahkan!";
    } else {
        $namaBarang = $_POST["nama-barang"];
        $hargaBarang = $_POST["harga-barang"];
        $gambarBarang = $_FILES["gambar-barang"]['name'];
    }
};
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <!-- Bootstrap CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <link rel="stylesheet" href="../css/mystyle.css">

    <title>Tambah Barang</title>
</head>

<body>
    <div class="flex-box">
        <?php require "sidebar.php" ?>
        <div class="main-content">
            <div class="my-4">
                <h1>Tambah Barang</h1>
            </div>
            <div>
                <form action="" method="post" enctype="multipart/form-data">
                    <div class="mb-3">
                        <label for="kode-barang" class="form-label">Kode</label>
                        <input type="text" name="kode-barang" class="form-control" id="kode-barang" autocomplete="off">
                    </div>
                    <div class=" mb-3">
                        <label for="nama-barang" class="form-label">Nama</label>
                        <input type="text" name="nama-barang" class="form-control" id="nama-barang" autocomplete="off" value="<?= $namaBarang ?>">
                    </div>
                    <div class=" mb-3">
                        <label for="harga-barang" class="form-label">Harga</label>
                        <input type="text" name="harga-barang" class="form-control" id="harga-barang" autocomplete="off" value="<?= $hargaBarang ?>">
                    </div>
                    <div class=" mb-3">
                        <label for="gambar-barang" class="form-label">Gambar</label>
                        <input type="file" name="gambar-barang" class="form-control" id="gambar-barang" autocomplete="off">
                    </div>
                    <button type="submit" name="add-item" class="btn btn-success">Tambah Barang</button>
                </form>
            </div>
        </div>
    </div>

    <?php

    if ($modal) { ?>
        <!-- Modal -->
        <div class="modal fade" id="add-item-modal" tabindex="-1" aria-labelledby="add-item-modal-label" aria-hidden="true">
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-header">
                        <h5 class="modal-title" id="add-item-modal-label">Konfirmasi</h5>
                        <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                    </div>
                    <div class="modal-body">
                        <?= $message ?>
                    </div>
                    <div class="modal-footer">
                        <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Tutup</button>
                        <a href="index.php" type="button" class="btn btn-primary">Daftar Barang</a>
                    </div>
                </div>
            </div>
        </div>
    <?php } ?>

    <!-- Optional JavaScript; choose one of the two! -->

    <!-- Option 1: Bootstrap Bundle with Popper -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>

    <script>
        function showModal() {
            let itemAddModal = new bootstrap.Modal(document.getElementById("add-item-modal"));
            itemAddModal.show();
        }
    </script>

    <?php
    if ($modal) {
        echo "<script> showModal(); </script>";
    };
    ?>

    <!-- Option 2: Separate Popper and Bootstrap JS -->
    <!--
    <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.9.2/dist/umd/popper.min.js" integrity="sha384-IQsoLXl5PILFhosVNubq5LC7Qb9DXgDA9i+tQ8Zj3iwWAwPtgFTxbJ8NT4GN1R8p" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.min.js" integrity="sha384-cVKIPhGWiC2Al4u+LWgxfKTRIcfu0JTxR+EQDz/bgldoEyl4H0zUF0QKbrJ0EcQF" crossorigin="anonymous"></script>
    -->
</body>

</html>