<?php
session_start();

if (!isset($_SESSION['id'])) {
    header("Location: ../login.php");
    exit();
}

require dirname(__DIR__) . "/util/function.php";
require dirname(__DIR__) . "/item/upload-image.php";

if (isset($_GET["kode-barang"])) {
    $kodeBarang = $_GET["kode-barang"];
} else {
    header("Location: index.php");
    exit();
}

$modal = false;
$message = "Gagal ditambahkan!";
$namaBarang = "";
$hargaBarang = "";
$gambarBarang = "";

$barang = query("SELECT * FROM barang WHERE kdbrg = '$kodeBarang'")[0];

$message = "";
if (isset($_FILES["gambar-barang"])) {
    $uploadImage = uploadImageItem($_FILES["gambar-barang"]);
}
$productImage = [
    "name" => $barang["filegbr"],
    "link" => dirname($_SERVER['PHP_SELF']) . "/images/" . $barang["filegbr"],
];


if (isset($_POST["update-item"])) {
    $request = [
        "kodeBarang" => $_POST["kode-barang"],
        "namaBarang" => $_POST["nama-barang"],
        "hargaBarang" => $_POST["harga-barang"],
        "gambarBarang" => $uploadImage["name"] == "" ? $barang["filegbr"] : $uploadImage["name"]
    ];
    if (update($request) > 0) {
        $kodeBarang = $_POST["kode-barang"];
        header("Location: index.php?update=true&kode-barang='{$kodeBarang}'");
    } else {
        $alertType = "alert-danger";
        $message = "Gagal diupdate <br>" . join("<br>", $uploadImage["arrayMessage"]);
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

    <title>Update Barang</title>
</head>

<body>
    <div class="flex-box">
        <?php require "sidebar.php" ?>
        <div class="main-content">
            <div class="my-4">
                <h1>Ubah Barang</h1>
                <?php if ($message) { ?>
                    <div class="alert <?= $alertType ?> alert-dismissible fade show" role="alert">
                        <?= $message ?>
                        <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
                    </div>
                <?php } ?>
            </div>
            <div>
                <form action="" method="post" enctype="multipart/form-data">
                    <div class="mb-3">
                        <label for="kode-barang" class="form-label">Kode</label>
                        <input type="text" name="kode-barang" class="form-control" id="kode-barang" autocomplete="off" value="<?= $barang["kdbrg"] ?>" readonly>
                    </div>
                    <div class="mb-3">
                        <label for="nama-barang" class="form-label">Nama</label>
                        <input type="text" name="nama-barang" class="form-control" id="nama-barang" autocomplete="off" value="<?= $barang["nmbrg"] ?>">
                    </div>
                    <div class=" mb-3">
                        <label for="harga-barang" class="form-label">Harga</label>
                        <input type="text" name="harga-barang" class="form-control" id="harga-barang" autocomplete="off" value="<?= $barang["hrgbrg"] ?>">
                    </div>
                    <div class=" mb-3">
                        <label for="gambar-barang" class="form-label">Gambar</label>
                        <br>
                        <img style="max-width: 100px;" src="<?= $productImage["link"] ?>" alt="<?= $productImage["name"] ?>" srcset="" class="img-thumbnail">
                        <input type="file" name="gambar-barang" class="form-control" id="gambar-barang" autocomplete="off" value="<?= $barang["filegbr"] ?>">
                    </div>
                    <button type=" submit" name="update-item" class="btn btn-success">Update Barang</button>
                </form>
            </div>
        </div>
    </div>

    <!-- Optional JavaScript; choose one of the two! -->

    <!-- Option 1: Bootstrap Bundle with Popper -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>

    <!-- Option 2: Separate Popper and Bootstrap JS -->
    <!--
    <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.9.2/dist/umd/popper.min.js" integrity="sha384-IQsoLXl5PILFhosVNubq5LC7Qb9DXgDA9i+tQ8Zj3iwWAwPtgFTxbJ8NT4GN1R8p" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.min.js" integrity="sha384-cVKIPhGWiC2Al4u+LWgxfKTRIcfu0JTxR+EQDz/bgldoEyl4H0zUF0QKbrJ0EcQF" crossorigin="anonymous"></script>
    -->
</body>

</html>