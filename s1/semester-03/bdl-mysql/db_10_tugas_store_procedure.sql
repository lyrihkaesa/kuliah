--membuat database baru (opsional)
CREATE DATABASE db_10_tugas_store_procedure;

--membuat tabel barang
CREATE TABLE barang (
    kode CHAR(6),
    nama VARCHAR(20) NOT NULL,
    jenis VARCHAR(15) NOT NULL,
    harga INT,
    jumlah INT,
    pemasok CHAR(3) NOT NULL,
    PRIMARY KEY (kode)
);

--membuat tabel pemasok
CREATE TABLE pemasok ( 
    kode CHAR(3), 
    nama VARCHAR(20), 
    kota VARCHAR(15), 
    PRIMARY KEY (kode) 
);

-- memasukkan values tabel barang
INSERT INTO barang VALUES 
    ('10001','Buku123','ATK',5000,100,'101'),
    ('10002','Buku007','ATK',5500,200,'505'),
    ('10003','Pensil Panjang','ATK',1000,250,'101'),
    ('10004','Indomie Udang','Makanan',2500,10,'201'),
    ('10005','Indomie Kentang','Makanan',3000,100,'201'),
    ('10006','Sari Seger S','Minuman',5500,20,'202'),
    ('10007','Temulawak Merah','Minuman',500,50,'202'),
    ('10008','Jahe Manis','Minuman',5000,8,'208'),
    ('10009','Paku Baja 2inch','Pertukangan',500,100,'401'),
    ('10010','Semen 3 0','Pertukangan',50000,20,'401');

-- memasukkan values pemasok
INSERT INTO pemasok VALUES
    ('100','Wahyu Pratama','Semarang'),
    ('101','Makmur','Semarang'),
    ('102','Wahyu Makmur','Sumedang'),
    ('201','Maju gagah Jaya','Jakarta'),
    ('202','AB','Semarang'),
    ('203','OK Sukses','Jakarta'),
    ('208','Nugroho Primadona','Surabaya'),
    ('401','Garuda Muda','Surabaya'),
    ('504','Pratama Sejati','Semarang'),
    ('505','Podang Kuning','Semarang');

-- 1. buatlah store procedure untuk menampilkan data barang
-- procedure barang
DELIMITER //
CREATE PROCEDURE cetakBarang()
BEGIN 
    SELECT * FROM barang; 
END //
DELIMITER ;

-- 2. procedure pemasok
DELIMITER //
CREATE PROCEDURE cetakPemasok()
BEGIN
    SELECT nama FROM pemasok WHERE EXISTS (SELECT * FROM barang WHERE pemasok.kode = barang.pemasok);
    
    SELECT nama FROM pemasok WHERE NOT EXISTS (SELECT * FROM barang WHERE pemasok.kode = barang.pemasok);
END //
DELIMITER ;

-- 3. menampilkan produk pemasok (nama berupa input). (BENAR)
DELIMITER //
CREATE PROCEDURE cetakProdukPemasok(IN xpemasok VARCHAR(15))
BEGIN 
    SELECT a.nama FROM barang a, pemasok b WHERE a.pemasok = b.kode AND b.nama = xpemasok;
END //
DELIMITER ;

-- 4. menampilkan suatu jenis barang dan dipasok dari kota tertentu
DELIMITER //
CREATE PROCEDURE cetakJenisKota(IN xjenis VARCHAR(20), xkota VARCHAR(15))
BEGIN
    SELECT * FROM barang, pemasok WHERE barang.pemasok = pemasok.kode AND barang.jenis = xjenis AND pemasok.kota = xkota;
END //
DELIMITER ;

-- 5. mengetahui jumlah pemasok dari suatu kota
DELIMITER //
CREATE PROCEDURE jumlahPemasokKota(IN xkota VARCHAR(15))
BEGIN
    SELECT COUNT(DISTINCT pemasok.nama) FROM pemasok, barang WHERE pemasok.kode = barang.pemasok AND pemasok.kota = xkota;
END //
DELIMITER ;

