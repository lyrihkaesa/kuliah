-- 1. buatlah database penjualan00000 (00000 = 5 digit NIM terakhir)
CREATE DATABASE penjualan00000;

USE penjualan00000;


-- a. tabel barang00000
CREATE TABLE barang00000 (
    kode CHAR(5),
    nama VARCHAR(20),
    stock INT,
    satuan CHAR(4),
    harga INT,
    tglkadaluarsa DATE,
    PRIMARY KEY(kode)
);

INSERT INTO barang00000 VALUES
    ('11111','Buku ABC','20','Buah','5000','2025-02-18'),
    ('22222','Buku Batik','20','Buah','7500','2025-01-28'),
    ('33333','Buku Gelatik','20','Buah','15000','2022-10-15'),
    ('44444','Pensil HB','20','Buah','2000','2023-12-08'),
    ('55555','Roti Pisang','20','Buah','4500','2021-01-07'),
    ('66666','Aqua 600','20','Buah','3500','2022-01-10'),
    ('77777','Freshtea 440','20','Buah','40000','2021-06-15');

-- b. tabel jual00000
CREATE TABLE jual00000 (
    notrans CHAR(5),
    tanggal DATE,
    kode CHAR(5),
    jumlah INT
);

INSERT INTO jual00000 VALUES 
    ('21001','2021-01-04','22222','1'),
    ('21001','2021-01-04','44444','2'),
    ('21002','2021-01-04','66666','3'),
    ('21002','2021-01-04','77777','4');

-- buatlah store procedure (nama = StoreProc00000) untuk menampilkan daftar barang
-- yang sudah terjual dengan penjualan kurang dari 3 buah sesuai dengan kondisi
-- tabel diatas.

-- a. capture kode perintah store procedurenya!
DELIMITER //

CREATE PROCEDURE StoreProc00000()
BEGIN
    SELECT * 
    FROM barang00000
    WHERE EXISTS(SELECT * 
                FROM jual00000 
                WHERE jumlah < 3 AND kode = barang00000.kode);
END //

-- b. capture output dari store procedure tersebut!
DELIMITER ;
CALL StoreProc00000();




-- 2. buatlah database dengan nama dbUAS00000 (00000 = 5 digit NIM terakhir)
CREATE DATABASE dbUAS00000;
USE dbUAS00000;

-- tabel nilai
CREATE TABLE nilai (
    NIM CHAR(5),
    Nama VARCHAR(20),
    Matakuliah VARCHAR(20),
    Nilai CHAR(1)
);

-- input data nilai
INSERT INTO nilai VALUES 
    ('17001','Adi','Agama','A'),
    ('17002','Brond','Matematika','B'),
    ('17003','Coco','Agama','D'),
    ('17004','Didi','Agama','C'),
    ('17004','Didi','Bahasa','C');

-- tabel perbaikan
CREATE TABLE perbaikan (
    NIM CHAR(5),
    Matakuliah VARCHAR(15),
    Tanggal DATE,
    Nilai CHAR(1)
);


-- membuat TRIGGER dengan nama TRIGGER00000 (00000 = 5 digit NIM terakhir)
DELIMITER //
CREATE TRIGGER Trigger00000
    BEFORE INSERT
    ON perbaikan
    FOR EACH ROW
    BEGIN
    DECLARE xnilai CHAR(1);
    SET xnilai = (
        SELECT nilai FROM nilai WHERE NIM = NEW.NIM 
        AND Matakuliah = NEW.Matakuliah
    );
        IF (NEW.nilai < xnilai) THEN
        UPDATE nilai
        SET
            nilai = NEW.nilai
        WHERE NEW.NIM = NIM AND NEW.Matakuliah = Matakuliah;
    END IF;
END //

DELIMITER ;

SELECT * FROM nilai;
SELECT * FROM perbaikan; -- empety (kosong) karena belum di insert (input/masukan)
-- input data perbaikan
INSERT INTO perbaikan VALUES 
    ('17004','Agama','2020-10-11','A'),
    ('17004','Bahasa','2020-10-20','B');

SELECT * FROM nilai;
SELECT * FROM perbaikan;
-- a. capture kode perintah triggernya!
-- b. capture perintah input datanya, hasil perubahan data dari tabel Nilai dan perbaikan.

-- 3. buatlah view mysql seperti jawaban pada soal no.3 teori
CREATE TABLE mahasiswa (
    nama VARCHAR(30),
    harga INT,
    tanggal DATE
);

INSERT INTO mahasiswa VALUES 
    ('Sutiyem',10000, '2022-12-22'),
    ('Maling',20000, '2022-12-22'),
    ('Kundang',6000, '2022-12-22'),
    ('Kenter',3000, '2022-12-22');
CREATE VIEW view_mahasiswa AS SELECT nama, tanggal FROM mahasiswa WHERE harga > 10000;
SELECT * FROM mahasiswa;
SELECT * FROM view_mahasiswa;
-- a. capture kode perintah mysqlnya!
-- b. capture tabel dasarnya!
-- c. capture output viewnya!