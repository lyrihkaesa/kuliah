CREATE DATABASE db_12_praktek_view;

CREATE TABLE barang (
    kode CHAR(5),
    nama VARCHAR(20),
    jenis VARCHAR(15),
    harga INT,
    jumlah INT,
    pemasok CHAR(5)
);

INSERT INTO barang VALUES (

);

CREATE TABLE jual (
    notrans CHAR(5),
    tgl DATE,
    kode CHAR(5),
    jumlah INT
);

-- Buatlah View
-- 1. jumlahbarang_minimal
-- 	  view ini digunakan untuk mencetak barang apa saja yang jumlahnya kurang dari  10
--    komponen yang dicetak : kode , nama,  jumlah,  pemasok
CREATE VIEW jumlahbarang_minimal AS
    SELECT kode, nama, jumlah, pemasok FROM barang
    WHERE jumlah < 10;


-- 2. nilai_barang
-- 	  view ini digunakan untuk mencetak data barang disertai dengan perkalian harga * jumlah (sort)
-- 	  komponen yang dicetak : kode , nama, harga, jumlah , (harga * jumlah)
CREATE VIEW nilai_barang AS
    SELECT kode, nama, harga, jumlah, (harga * jumlah) FROM barang
    ;

-- 3. jualbarang_terbanyak
-- 	  vew ini digunakan untuk mencetak data penjualan barang yang jumlahnya paling banyak pada bulan sekarang (sort)
-- 	  komponen yang dicetak : kode , nama,  harga,  jumlah 
CREATE VIEW jualbarang_terbanyak AS
    SELECT kode, nama, harga, jumlah FROM barang
    ;

-- 3. dengan field tanggal

-- 4. jualbarang_nol
--    view ini digunakan untuk mencetak data barang yang tidak terjual pada bulan sekarang (sort)
-- 	  komponen yang dicetak : kode , nama,  harga,  jumlah 
CREATE jualbarang_nol AS
    SELECT kode, nama, harga, jumlah FROM barang
    ;

-- 4. dengan field tanggal

-- 5. totalpenjualan
--    view ini digunakan untuk mencetak total penjualan (total uang penjualan) pada hari ini
CREATE VIEW totalpenjualan AS
    SELECT * FROM jual;