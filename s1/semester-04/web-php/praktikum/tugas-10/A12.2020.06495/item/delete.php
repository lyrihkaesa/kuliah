<?php
session_start();

if (!isset($_SESSION['id'])) {
    header("Location: ../login.php");
    exit();
}

require dirname(__DIR__) . "/util/function.php";

if (isset($_GET["kode-barang"])) {
    $kodeBarang = $_GET["kode-barang"];
} else {
    header("Location: index.php");
    exit();
}

$barang = query("SELECT * FROM barang WHERE kdbrg = '$kodeBarang'")[0];
$imageFile = __DIR__ . "/images/" . $barang['filegbr'];

if (delete($kodeBarang) > 0) {
    header("Location: index.php?delete=true&kode-barang=$kodeBarang");
    unlink($imageFile);
} else {
    header("Location: index.php?delete=false&kode-barang=$kodeBarang");
}
exit();
