-- Masuk ke SQL
-- mysql - u root 
-- 
-- membuat database
CREATE DATABASE pbo_kukuh06495;

-- menggunakan database
USE pbo_kukuh06495;

-- membuat tabel pegawai
CREATE TABLE pegawai (
    nip VARCHAR(30) NOT NULL,
    nama VARCHAR(50) NOT NULL,
    bagian VARCHAR(30) NOT NULL,
    jenis_kelamin VARCHAR(15) NOT NULL,
    `password` VARCHAR(50) NOT NULL
) ENGINE = InnoDB;

-- membuat tabel barang
CREATE TABLE barang (
    id VARCHAR(30) NOT NULL,
    name VARCHAR(50) DEFAULT NULL,
    selling_price INT(12) DEFAULT NULL,
    purchase_price INT(12) DEFAULT NULL,
    amount INT(8) DEFAULT NULL
) ENGINE = InnoDB;

SELECT
    *
FROM
    pegawai
WHERE
    nip = '2222';

-- menambahkan/memasukan/insert/input barang
INSERT INTO
    barang (
        id,
        name,
        selling_price,
        purchase_price,
        amount
    )
VALUES
    ("00001", "Buku Tulis ABC 40", 5000, 5500, 100),
    ("00002", "Buku Tulis Merak 80", 7000, 7500, 120),
    ("00003", "Pensil 2B", 1500, 2000, 50),
    ("00004", "Bolpoin Tecno", 1200, 2000, 50),
    ("00005", "Spidol Hitam", 3000, 4000, 20);