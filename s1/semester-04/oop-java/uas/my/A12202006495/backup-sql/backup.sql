-- Masuk ke SQL
-- mysql - u root
-- membuat database
CREATE DATABASE kuliah_pbo_kukuh06495;

-- menggunakan database
USE kuliah_pbo_kukuh06495;

-- drop table
-- DROP TABLE pegawai;
-- DROP TABLE barang;
-- DROP TABLE jual;
-- membuat tabel pegawai
CREATE TABLE pegawai (
    nip VARCHAR(30) NOT NULL,
    name VARCHAR(50) NOT NULL,
    department VARCHAR(30) NOT NULL,
    gender VARCHAR(15) NOT NULL,
    `password` VARCHAR(50) NOT NULL
) ENGINE = InnoDB;

INSERT INTO
    pegawai (nip, name, department, gender, `password`)
VALUES
    (
        "001",
        "Admin 001",
        "Administator",
        "Laki-Laki",
        "001"
    ),
    (
        "A12.2020.06495",
        "Kukuh Setya Arumansyah",
        "Administator Super",
        "Laki-Laki",
        "rahasia"
    );

-- membuat tabel barang
CREATE TABLE barang (
    id VARCHAR(30) NOT NULL,
    name VARCHAR(50) DEFAULT NULL,
    selling_price INT(12) DEFAULT NULL,
    purchase_price INT(12) DEFAULT NULL,
    amount INT(8) DEFAULT NULL
) ENGINE = InnoDB;

-- melihat isi pada tabel pegawai dengan nip "2222"
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
    ("001", "Buku Tulis ABC 40", 5500, 5000, 100),
    ("002", "Buku Tulis Merak 80", 7500, 7000, 120),
    ("003", "Pensil 2B", 2000, 1500, 50),
    ("004", "Bolpoin Tecno", 2000, 1700, 50),
    ("005", "Spidol Hitam", 4000, 3200, 20);

-- membuat tabel jual
CREATE TABLE jual (
    transaction_id VARCHAR(30) DEFAULT NULL,
    id_item VARCHAR(30) DEFAULT NULL,
    price_item INT(12) DEFAULT NULL,
    amount_item INT(8) DEFAULT NULL
) ENGINE = InnoDB;

-- DELETE FROM jual;