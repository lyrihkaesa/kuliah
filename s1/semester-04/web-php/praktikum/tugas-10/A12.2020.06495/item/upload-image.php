<?php
if (!isset($_SESSION['id'])) {
    header("Location: ../login.php");
    exit();
}

function uploadImageItem($image)
{
    $dirFileImages = __DIR__ . "/images/";
    $imageTypeRequire = ["image/jpg", "image/png", "image/jpeg", "image/gif"];
    $uploadImage = [
        "status" => true,
        "message" => "Berhasil mengupload gambar " . $image["name"],
        "arrayMessage" => [],
        "name" => time() . "-" . $image["name"],
    ];

    if ($image["size"] > 0) {
        if ($image["size"] > 1000000) {
            $uploadImage["status"] = false;
            $msg = "Maaf, ukuran file harus kurang dari 1MB";
            $uploadImage["message"] = $msg;
            array_push($uploadImage["arrayMessage"], $msg);
        }

        if (!in_array($image["type"], $imageTypeRequire)) {
            $uploadImage["status"] = false;
            $msg = "Maaf, hanya file JPG, JPEG, PNG, dan GIF yang diperbolehkan";
            $uploadImage["message"] = $msg;
            array_push($uploadImage["arrayMessage"], $msg);
        }

        if ($uploadImage["status"]) {
            if (move_uploaded_file($image["tmp_name"], $dirFileImages . $uploadImage["name"])) {
                $msg = "Berhasil mengupload gambar" . $image["name"];
                $uploadImage["message"] = $msg;
                array_push($uploadImage["arrayMessage"], $msg);
            } else {
                $uploadImage["status"] = false;
                $msg = "Kesalahan terjadi saat upload gambar";
                $uploadImage["message"] = $msg;
                array_push($uploadImage["arrayMessage"], $msg);
            }
        } else {
            $msg = "Maaf, file tidak dapat diupload";
            $uploadImage["message"] = $msg;
            array_push($uploadImage["arrayMessage"], $msg);
        }
    } else {
        $uploadImage["name"] = "";
    }

    return $uploadImage;
}
