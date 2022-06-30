<?php
require "../util/connection.php";
require "../util/function.php";

$barang = query("SELECT * FROM barang");

// var_dump($barang);
// die();


?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Daftar Barang</title>
</head>

<body>
    <p>Daftar Barang</p>
    <table>
        <tr>
            <td>No</td>
            <td>Kode Barang</td>
            <td>Nama Barang</td>
            <td>Harga Barang</td>
            <td>File Gambar</td>
        </tr>
        <?php $i = 1; ?>
        <?php foreach ($barang as $row) : ?>
            <tr>
                <td><?= $i ?></td>
                <td><?= $row["kdbrg"]; ?></td>
                <td><?= $row["nmbrg"]; ?></td>
                <td><?= $row["hrgbrg"]; ?></td>
                <td>
                    <?php
                    if ($row["filegbr"] != "") {
                        $path = __DIR__ . "/images/" . $row["filegbr"];
                        $type = pathinfo($path, PATHINFO_EXTENSION);
                        $data = file_get_contents($path);
                        $base64 = 'data:image/' . $type . ';base64,' . base64_encode($data);
                    ?>
                        <img style="max-width: 200px;" src="<?= $base64; ?>" alt="<?= $row["filegbr"]; ?>" srcset="">
                    <?php } else { ?>
                        Tidak ada gambar
                    <?php } ?>
                </td>
            </tr>
            <?php $i++; ?>
        <?php endforeach; ?>
    </table>
</body>

</html>