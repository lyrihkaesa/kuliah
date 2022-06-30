<?php
require "connection.php";

function query($query)
{
    global $conn;
    $result = mysqli_query($conn, $query);
    $rows = [];
    while ($row = mysqli_fetch_assoc($result)) {
        $rows[] = $row;
    }
    // mysqli_close($conn);
    return $rows;
}

function insert($val)
{
    global $conn;
    $kodeBarang = $val["kodeBarang"];
    $namaBarang = $val["namaBarang"];
    $hargaBarang = $val["hargaBarang"];
    $gambarBarang =  $val["gambarBarang"];


    $query = "INSERT INTO barang VALUES ('$kodeBarang', '$namaBarang', '$hargaBarang', '$gambarBarang' )";

    mysqli_query($conn, $query);


    $rowAffected = mysqli_affected_rows($conn);
    mysqli_close($conn);

    return $rowAffected;
}

function delete($kodeBarang)
{
    global $conn;
    mysqli_query($conn, "DELETE FROM barang WHERE kdbrg = '$kodeBarang'");

    $rowAffected = mysqli_affected_rows($conn);
    mysqli_close($conn);

    return $rowAffected;
}

function update($val)
{
    global $conn;
    $kodeBarang = $val["kodeBarang"];
    $namaBarang = $val["namaBarang"];
    $hargaBarang = $val["hargaBarang"];
    $gambarBarang =  $val["gambarBarang"];

    $query = "UPDATE barang SET nmbrg = '$namaBarang', hrgbrg = '$hargaBarang', filegbr = '$gambarBarang' WHERE kdbrg = '$kodeBarang'";

    mysqli_query($conn, $query);
    $rowAffected = mysqli_affected_rows($conn);
    mysqli_close($conn);

    return $rowAffected;
}
function search($keyword)
{
    $query = "SELECT * FROM barang WHERE kdbrg LIKE '%$keyword%' OR nmbrg LIKE '%$keyword%' OR hrgbrg LIKE '%$keyword%'";
    return query($query);
}
