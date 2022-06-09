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

-- menghapus/delete semua data barang
DELETE FROM
    barang;

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
    ("0001", "Buku Tulis ABC 40", 5500, 5000, 100),
    ("0002", "Buku Tulis Merak 80", 7500, 7000, 120),
    ("0003", "Pensil 2B", 2000, 1500, 50),
    ("0004", "Bolpoin Tecno", 2000, 1700, 50),
    ("0005", "Spidol Hitam", 4000, 3200, 20);

-- membuat tabel jual
CREATE TABLE jual (
    transaction_id VARCHAR(30) DEFAULT NULL,
    id_item VARCHAR(30) DEFAULT NULL,
    price_item INT(12) DEFAULT NULL,
    amount_item INT(8) DEFAULT NULL
) ENGINE = InnoDB;

DELETE FROM
    jual;