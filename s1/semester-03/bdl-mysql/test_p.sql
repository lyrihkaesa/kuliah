-- PRAKTEK 

-- 1. buatlah database penjualanXXXXX (XXXXX = 5 digit NIM terakhir)
CREATE DATABASE penjualan06495;
USE penjualan06495;
-- a. tabel barangXXXXX
CREATE TABLE barang06495 (
    kode CHAR(5),
    nama VARCHAR(20),
    stock INT,
    satuan CHAR(5),
    harga INT,
    tglkadaluarsa DATE,
    PRIMARY KEY(kode)
);

INSERT INTO barang06495 VALUES
    ('11111','Buku ABC','20','Buah','5000','2025-02-18'),
    ('22222','Buku Batik','20','Buah','7500','2025-01-28'),
    ('33333','Buku Gelatik','20','Buah','15000','2022-10-15'),
    ('44444','Pensil HB','20','Buah','2000','2023-12-08'),
    ('55555','Roti Pisang','20','Buah','4500','2021-01-07'),
    ('66666','Aqua 600','20','Buah','3500','2022-01-10'),
    ('77777','Freshtea 440','20','Buah','40000','2021-06-15');

-- b. tabel jualXXXXX
CREATE TABLE jual06495 (
    notrans CHAR(5),
    tanggal DATE,
    kode CHAR(5),
    jumlah INT
);

INSERT INTO jual06495 VALUES 
    ('21001','2021-01-04','22222','1'),
    ('21001','2021-01-04','44444','2'),
    ('21002','2021-01-04','66666','3'),
    ('21002','2021-01-04','77777','4');

-- buatlah store procedure (nama = StoreProcXXXXX) untuk menampilkan daftar barang
-- yang sudah terjual dengan penjualan kurang dari 3 buah sesuai dengan kondisi
-- tabel diatas.

DELIMITER //

CREATE PROCEDURE StoreProc06495()
    BEGIN
        SELECT * 
        FROM barang06495
        WHERE EXISTS (
            SELECT * 
            FROM jual06495
            WHERE jumlah < 3 AND kode = barang06495.kode
        );
    END //

DELIMITER ;

CALL StoreProc06495;
-- a. capture kode perintah store procedurenya!
-- b. capture output dari store procedure tersebut!

-- 2. buatlah database dengan nama dbUASxxxxx (xxxxx = 5 digit NIM terakhir)
CREATE DATABASE dbUAS06495;
USE dbUAS06495;
-- tabel nilai
CREATE TABLE Nilai (
    NIM CHAR(5),
    Nama VARCHAR(20),
    Matakuliah VARCHAR(20),
    Nilai CHAR(1)
);

-- input data nilai
INSERT INTO Nilai VALUES 
    ('17001','Adi','Agama','A'),
    ('17002','Brond','Matematika','B'),
    ('17003','Coco','Agama','D'),
    ('17004','Didi','Agama','C'),
    ('17004','Didi','Bahasa','C');

-- tabel perbaikan
CREATE TABLE Perbaikan (
    NIM CHAR(5),
    Matakuliah VARCHAR(15),
    Tanggal DATE,
    Nilai CHAR(1)
);

DELIMITER //

-- membuat TRIGGER dengan nama triggerXXXXX (XXXXX = 5 digit NIM terakhir)
CREATE TRIGGER Trigger06495
    BEFORE INSERT
    ON Perbaikan
    FOR EACH ROW
    BEGIN
    
        DECLARE xNilai CHAR(1);
        
        SET xNilai = (
            SELECT Nilai 
            FROM Nilai 
            WHERE NIM = new.NIM AND Matakuliah = new.Matakuliah
        );
        
        IF (xNilai > new.Nilai) THEN
            UPDATE Nilai
            SET Nilai = new.Nilai
            WHERE new.NIM = NIM AND new.Matakuliah = Matakuliah;
        END IF;
    END //

DELIMITER ;

SELECT * FROM Nilai;
SELECT * FROM Perbaikan;

-- input data perbaikan
INSERT INTO Perbaikan VALUES 
    ('17004','Agama','2020-10-11','A'),
    ('17004','Bahasa','2020-10-20','B');

SELECT * FROM Nilai;
SELECT * FROM Perbaikan;
-- a. capture kode perintah triggernya!
-- b. capture perintah input datanya, hasil perubahan data dari tabel Nilai dan perbaikan.

-- 3. buatlah view mysql seperti jawaban pada soal no.3 teori
CREATE DATABASE dbUAST;
USE dbUAST;

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
-- a. capture kode perintah mysqlnya!
-- b. capture tabel dasarnya!
-- c. capture output viewnya!


-- Nama File: UASPraktekKel06BDL06495