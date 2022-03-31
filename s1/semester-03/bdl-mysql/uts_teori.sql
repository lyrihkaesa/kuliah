CREATE TABLE barang_lo (kode CHAR(10), nama VARCHAR(30), deskripsi VARCHAR(255), harga INT, stok INT, jenis CHAR(10), diskon INT, tanggal_beli DATE);

INSERT INTO barang_lo VALUES 
    ('0000099991', 'Asolole', 'Barang buangan', 500000000, 10, 'Mainan', 10, '2022-01-10'),
    ('99991', 'Asolole', 'Barang buangan', 500000000, 10, 'Mainan', 10, '2022-01-10'),
    ('99991', 'Asolole', 'Barang buangan', 500000000, 10, 'Mainan', 10, '2022-01-10'),
    ('99991', 'Asolole', 'Barang buangan', 500000000, 10, 'Mainan', 10, '2022-01-10'),
    ('99991', 'Asolole', 'Barang buangan', 500000000, 10, 'Mainan', 10, '2022-01-10'),
    ('99991', 'Asolole', 'Barang buangan', 500000000, 10, 'Mainan', 10, '2022-01-10'),
    ('99991', 'Asolole', 'Barang buangan', 500000000, 10, 'Mainan', 10, '2022-01-10'),
    ('99991', 'Asolole', 'Barang buangan', 500000000, 10, 'Mainan', 10, '2022-01-10'),
    ('99991', 'Asolole', 'Barang buangan', 500000000, 10, 'Mainan', 10, '2022-01-10'),
    ('99991', 'Asolole', 'Barang buangan', 500000000, 10, 'Mainan', 10, '2022-01-10');



CREATE DATABASE dbUASXXXXX;
-- Nomor 2 

DELIMITER //
CREATE TRIGGER Trigger01
    BEFORE INSERT ON Perbaikan FOR EACH ROW
    BEGIN
        --  nilaiLama dibawah bisa diganti ke nama variabel yang lain.
        DECLARE nilaiLama CHAR(1);
        --  nilaiLama dibawah bisa diganti ke nama variabel yang lain.
        SET nilaiLama = (SELECT Nilai FROM Nilai WHERE NIM = new.NIM AND Matakuliah = new.Matakuliah);
        --  nilaiLama dibawah bisa diganti ke nama variabel yang lain.
        IF (nilaiLama > new.Nilai) THEN
            UPDATE Nilai SET Nilai = new.Nilai WHERE new.NIM = NIM AND new.Matakuliah = Matakuliah;
        END IF;
    END //

-- ########################################## Nomor 3
-- Keuntungan view adalah :
-- Query yang kompleks dapat di sembunyikan sehingga informasi dapat diakses dengan cepat
-- Untuk mengatur data tertentu menjadi tersembunyi bagi pemakai
-- Untuk melindungi data yang bersifat rahasia
CREATE TABLE mahasiswa (
    nama VARCHAR(30),
    harga INT,
    tanggal DATE
);

INSERT INTO mahasiswa VALUES 
    ('Sutiyem',10000, '2222-22-22'),
    ('Maling',20000, '2222-22-22'),
    ('Kundang',6000, '2222-22-22'),
    ('Kenter',3000, '2222-22-22');
CREATE VIEW view_mahasiswa as SELECT nama, tanggal FROM mahasiswa WHERE harga > 10000;
SELECT * FROM mahasiswa;
SELECT * FROM view_mahasiswa;

-- ######################################## Nomor 4
CREATE USER 'andre'@'localhost' IDENTIFIED BY 'passwordMilikAnda';
-- membuat user dengan nama 'andre' yang memiliki host 'localhost' dan password 'passwordMilikAnda'

GRANT ALL ON dbUASXXXXX.* TO 'andre'@'localhost';
-- memberikan hak akses ALL (semua) kepada user 'andre' yang memiliki host 'localhost' hanya untuk database dbUASXXXXX dan tabel 
-- pada dbUASXXXX.



