-- Masuk ke SQL
mysql -u root

-- membuat database
CREATE DATABASE dbMARKETxxxxx;

-- menggunakan database
USE dbMARKETxxxxx;

-- membuat tabel barang
CREATE TABLE barangxxxxx (
    kode CHAR(5) PRIMARY KEY,
    nama VARCHAR(30) NOT NULL,
    stock INT(11),
    satuan VARCHAR(15),
    harga INT(11),
    tgl_kadaluarsa DATE,
    pemasok VARCHAR(20)
);

CREATE TABLE barangxxxxx (
    kode CHAR(5),
    nama VARCHAR(30) NOT NULL,
    stock INT(11),
    satuan VARCHAR(15),
    harga INT(11),
    tgl_kadaluarsa DATE,
    pemasok VARCHAR(20),
    PRIMARY KEY (kode)
);

-- membuat table barang tanpa PRIMARY KEY
CREATE TABLE barangxxxxx (
    kode CHAR(5),
    nama VARCHAR(30) NOT NULL,
    stock INT,
    satuan VARCHAR(15),
    harga INT,
    tgl_kadaluarsa DATE,
    pemasok VARCHAR(20)
);

-- mengubah table barang dan menambahkan PRIMARY KEY untuk field kode.
ALTER TABLE barangxxxxx ADD PRIMARY KEY (kode);

-- [Tambahan] menghapus table barang
DROP TABLE barangxxxxx;

-- memasukan data ke table barang semuanya
INSERT INTO barangxxxxx VALUES
    ('11111','Mixer Yamoha A12X',20,'Buah',550000,'2025-01-01','PT. Mulia'),
    ('22222','Lampu LED 4 W',50,'Buah',5000,'2024-05-05','PT. Maju'),
    ('33333','Pensil HBC',100,'Buah',1000,'2023-04-08','CV. Jaya'),
    ('44444','Buku Swan 50',200,'Buah',5500,'2024-11-22','CV. Jaya'),
    ('55555','Sprite 1,5 L',35,'Botol',10000,'2021-05-01','CV. Segar'),
    ('66666','Aqua 1,5 L',2,'Botol',5000,'2020-12-20','CV. Segar'),
    ('77777','Gula XYZ 1 Kg',1,'Sak',12500,'2020-10-15','PT. Hang Kuan'),
    ('88888','Kopi 200 gr',5,'Bungkus',5000,'2020-01-25','PT. Hang Kuan'),
    ('99999','Songkok Turki',50,'Buah',45000,'2025-01-20','CV. Murni');

-- [Tambahan] melihat struktur pembuatan table
SHOW CREATE TABLE barangxxxxx;

-- [Tambahan] melihat seluruh daftar table
SHOW TABLES;

-- [Tambahan] melihat deskripsi table
DESC barangxxxxx;

-- menampilkan data barang yang namanya mengandung huruf "o"
SELECT * FROM barangxxxxx WHERE nama LIKE "%o%";

-- mengubah field harga menjadi hargajual;
ALTER TABLE barangxxxxx CHANGE harga harga_jual INT;
ALTER TABLE barangxxxxx CHANGE harga_jual harga INT;
-- [Tidak Bisa] RENAME COLUMN hanya untuk ORACLE SQL
ALTER TABLE barangxxxxx RENAME COLUMN harga TO harga_jual;

-- [Tambahan] melihat semua data pada table barang
SELECT * FROM barangxxxxx;

-- [Tambahan] melihat data pada table barang dengan kode "55555 & 77777"
SELECT * FROM barangxxxxx WHERE kode = '55555' OR kode = '77777';
-- mengubah data tgl_kadaluarsa
UPDATE barangxxxxx SET tgl_kadaluarsa = '2021-12-30' WHERE kode = '55555' OR kode = '77777';

-- menampilkan data barang dengan field kode, nama, stok, hargajual, dan jumlah = stok * hargajual.
SELECT kode, nama, stock, harga_jual, stock * harga_jual AS jumlah FROM barangxxxxx;

-- menampilkan data barang yang akan kadaluarsa paling lama 100 hari dari sekarang
SELECT * FROM barangxxxxx WHERE tgl_kadaluarsa >= CURRENT_DATE() AND tgl_kadaluarsa <= DATE_ADD(CURRENT_DATE(), INTERVAL 100 DAY);
SELECT * FROM barangxxxxx WHERE tgl_kadaluarsa >= CURRENT_DATE() AND tgl_kadaluarsa <= DATE_SUB(CURRENT_DATE(), INTERVAL -100 DAY);
SELECT * FROM barangxxxxx WHERE tgl_kadaluarsa >= CURRENT_DATE() AND tgl_kadaluarsa <= FROM_DAYS(TO_DAYS(Current_date())+100);

-- menampilkan field kode, nama, stock dipasok "CV. Segar" stok kurang dari 10.
SELECT kode, nama, stock FROM barangxxxxx WHERE pemasok = 'CV. Segar' AND stock < 10;

-- menampilkan total stock barang dari masing-masing pemasok
SELECT pemasok, SUM(stock) FROM barangxxxxx GROUP BY pemasok;