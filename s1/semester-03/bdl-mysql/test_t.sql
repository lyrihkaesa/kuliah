CREATE DATABASE uji_t;

-- Nomor 1
-- a.
CREATE TABLE barang (
    id CHAR(5),
    nama VARCHAR(30),
    grade CHAR(1),
    harga INT,
    prosen INT,
    jumlah INT,
    pemasok_id CHAR(5),
    kategori VARCHAR(20),
    tempat VARCHAR(30),
    tanggal_up DATE,
    PRIMARY KEY (id)
);

-- b.
INSERT INTO barang VALUES 
    ('00001','Buku','A',5000,25,80,'AP001', 'Alat Tulis', 'Rak Satu', '2022-01-09'),
    ('00002','Pensil','A',2500,25,100,'AP001', 'Alat Tulis', 'Rak Satu', '2022-01-09'),
    ('00003','Penggaris','B',2000,30,50,'AP001', 'Alat Tulis', 'Rak Satu', '2022-01-09'),
    ('00004','Sandal','B',50000,30,25,'AP002', 'Alas Kaki', 'Rak Dua', '2022-01-09'),
    ('00005','Sepatu','A',200000,25,20,'AP002', 'Alas Kaki', 'Rak Dua', '2022-01-09'),
    ('00006','Sarung','B',100000,35,50,'AP003', 'Pakaian', 'Lemari Satu', '2022-01-09'),
    ('00007','Kaos','C',55000,40,50,'AP003', 'Pakaian', 'Lemari Satu', '2022-01-09'),
    ('00008','Topi','A',50000,25,25,'AP004', 'Pakaian', 'Lemari Satu', '2022-01-09'),
    ('00009','Bola','A',25000,30,20,'AP004', 'Mainan', 'Rak Tiga', '2022-01-09'),
    ('00010','Sabun','B',2500,30,45,'AP005', 'Pembersih', 'Rak Empat', '2022-01-09');


-- Nomor 2
CREATE DATABASE dbUAS06495;

CREATE TABLE nilai (
    nim CHAR(5),
    nama VARCHAR(30),
    matakuliah VARCHAR(20),
    nilai CHAR(1)
);

INSERT INTO nilai VALUES 
    ('17001','Adi','Agama','A'),
    ('17002','Brond','Matematika','B'),
    ('17003','Coco','Agama','D'),
    ('17004','Didi','Agama','C'),
    ('17004','Didi','Bahasa','C');

SELECT * FROM nilai;

CREATE TABLE perbaikan (
    nim CHAR(5),
    matakuliah VARCHAR(30),
    tanggal DATE,
    nilai CHAR(1)
);

INSERT INTO perbaikan VALUES 
    ('17004','Agama','2020-10-11','A'),
    ('17004','Bahasa','2020-10-20','B');

SELECT * FROM perbaikan;

DELIMITER //

CREATE TRIGGER trigger01
    BEFORE INSERT
    ON perbaikan
    FOR EACH ROW
    BEGIN
    
        DECLARE xnilai CHAR(1);
        
        SET xnilai = (
            SELECT nilai 
            FROM nilai 
            WHERE nim = new.nim AND matakuliah = new.matakuliah
        );
        
        IF (xnilai > new.nilai) THEN
            UPDATE nilai
            SET nilai = new.nilai
            WHERE new.nim = nim AND new.matakuliah = matakuliah;
        END IF;
    END //

-- Nomor 3
-- 1. Query yang kompleks dapat di sembunyikan sehingga informasi dapat diakses dengan cepat
-- 2. Untuk mengatur data tertentu menjadi tersembunyi bagi pemakai
-- 3. Untuk melindungi data yang bersifat rahasia

CREATE TABLE pengguna (
    id INT AUTO_INCREMENT,
    nama VARCHAR(30),
    kelas CHAR(8),
    saldo INT,
    jenis_kelamin ENUM('Laki-laki', 'Perempuan'),
    whatsapp VARCHAR(20),
    tanggal_lahir DATE,
    PRIMARY KEY (id)
);

INSERT INTO pengguna (nama, kelas, saldo, jenis_kelamin, whatsapp, tanggal_lahir) VALUES 
    ('Agus Wahyu','A12.6305',2000000,'Laki-laki','62123456789','2002-08-12'),
    ('Sari Wijaya','A12.6305',3000000,'Perempuan','621111111111','2001-10-11'),
    ('Lestari','A12.6305',2500000,'Perempuan','6212333333','2002-11-15'),
    ('Dita Niasari','A12.6306',1000000,'Perempuan','62123445566','2002-01-05'),
    ('Kukuh Setya Arumansyah','A12.6306',4000000,'Laki-laki','6282226660205','2002-05-09');

SELECT * FROM pengguna;

CREATE VIEW pengguna_a12_6306 AS
SELECT nama, jenis_kelamin, whatsapp, tanggal_lahir
FROM pengguna WHERE kelas = 'A12.6306';

SELECT * FROM pengguna_a12_6306;

-- Nomor 4
-- Buatlah user dengan nama 'kukuh' yang hostnya adalah '% (semua jaringan)' dengan password 'pemalas100kali'
CREATE USER 'kukuh'@'%' IDENTIFIED BY 'pemalas100kali';
CREATE USER 'setya'@'localhost' IDENTIFIED BY 'pemalas100kali';
CREATE USER 'arum'@'127.0.0.1' IDENTIFIED BY 'pemalas100kali';
-- Berikan 'ALL (semua)' hak ases kepada user 'kukuh' yang hostnya adalah '% (semua jaringan)' pada semua database dan tabel.
GRANT ALL PRIVILEGES ON *.* TO 'kukuh'@'%';
GRANT SELECT PRIVILEGES ON *.* TO 'setya'@'localhost';
GRANT SELECT, INSERT, DELETE PRIVILEGES ON *.* TO 'arum'@'127.0.0.1';


-- Nama File: UASTeoriKel06BDL06495