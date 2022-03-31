-- Terakhir Diperbarui: 21-12-15

-- [tambahan] membuat database baru
CREATE DATABASE db_10_tugas_trigger;

-- [tambahan] menggunakan database baru
USE db_10_tugas_trigger;

-- [tambahan] melihat table pada database baru
SHOW TABLES;

-- membuat tabel barang
CREATE TABLE barang (
  kode CHAR(5),
  nama VARCHAR(20),
  jenis VARCHAR(15),
  harga INT,
  jumlah INT,
  pemasok CHAR(5)
);

-- memasukkan nilai ke tabel barang
INSERT INTO barang VALUES
  ('10001', 'Buku123', 'ATK', 5000, 100, '101'),
  ('10002', 'Buku007', 'ATK', 5500, 200, '505'),
  ('10003','Pensil Panjang','ATK',1000,250,'101'),
  ('10004','Indomie Udang','Makanan',2500,10,'201'),
  ('10005','Indomie Kentang','Makanan',3000,100,'201');

-- membuat tabel jual
CREATE TABLE jual (
  notrans CHAR(5),
  kode CHAR(5),
  jumlah INT
);

-- membuat tabel beli
CREATE TABLE beli (
  nofaktur CHAR(5),
  kode CHAR(5),
  harga INT,
  jumlah INT
);

-- A
DELIMITER //

-- 1. trigger insert_jual_update_jumlah
CREATE TRIGGER insert_jual_update_jumlah
  BEFORE INSERT
  ON jual
  FOR EACH ROW
  BEGIN
    UPDATE barang SET jumlah = (jumlah - new.jumlah)
    WHERE kode = new.kode;
  END //

-- 2. trigger insert_beli_update_harga
CREATE TRIGGER insert_beli_update_harga
  BEFORE INSERT
  ON beli
  FOR EACH ROW
  BEGIN
    DECLARE xharga INT;
    SET xharga = (
      SELECT harga FROM barang WHERE kode = new.kode
    );

    IF(xharga < new.harga) THEN
      UPDATE barang 
      SET 
        harga = new.harga + (new.harga * 25/100),
        jumlah = (jumlah + new.jumlah)
      WHERE kode = new.kode;
    ELSE
      UPDATE barang
      SET jumlah = (jumlah + new.jumlah)
      WHERE kode = new.kode;
    END IF;
  END //



-- B
DELIMITER ;
DELIMITER //

-- [tambahan] membuat procedure cetakBarangBeli()
CREATE PROCEDURE cetakBarangBeli()
BEGIN
  SELECT * FROM barang;
  SELECT * FROM beli;
END //

-- [tambahan] membuat procedure cetakBarangJual()
CREATE PROCEDURE cetakBarangJual()
BEGIN
  SELECT * FROM barang;
  SELECT * FROM jual;
END //

DELIMITER ;

-- 1. isikan data beli!
-- [tambahan] memanggil procedure cetakBarangBeli()
CALL cetakBarangBeli();
-- [penting] isikan data beli harga lebih besar
INSERT INTO beli VALUES ('P0001', '10001', 10000, 40);
-- [tambahan] memanggil procedure cetakBarangBeli()
CALL cetakBarangBeli();
-- [penting] isikan data beli harga lebih kecil
INSERT INTO beli VALUES ('P0002', '10002', 2500, 20);
-- [tambahan] memanggil procedure cetakBarangBeli()
CALL cetakBarangBeli();

-- 2. isikan data jual!
-- [tambahan] memanggil procedure cetakBarangBeli()
CALL cetakBarangJual();
-- [penting] isikan data jual
INSERT INTO jual VALUES ('J0001', '10004', 2);
-- [tambahan] memanggil procedure cetakBarangBeli()
CALL cetakBarangJual();

-- 3. tugas trigger

-- •	tambahkan sebuah data barang dimana kode barang adalah 
--    5 digit nim terakhir Anda, data lainnya disesuaikan 
INSERT INTO barang VALUES ('06495', 'Kukuh Setya A', 'Mahasiswa SI', 999, 66, '999');
-- •	tampilkan data barang
SELECT * FROM barang;
-- •	tambahkan data pembelian ('P0003', 'kode sesuai nim', 2000, 10)
INSERT INTO beli VALUES ('P0003', '06495', 20000, 10);
-- •	tampilkan data beli
SELECT * FROM beli;
-- •	tampilkan data barang
SELECT * FROM barang;
-- •	tambahkan data penjualan ('J0002', 'kode sesuai nim', 1)
INSERT INTO jual VALUES ('J0002', '06495', 1);
-- •	tampilkan data jual
SELECT * FROM jual;
-- •	tampilkan data barang
SELECT * FROM barang;

