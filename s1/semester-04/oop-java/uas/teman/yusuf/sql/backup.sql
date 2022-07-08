-- Masuk ke SQL
-- mysql - u root
-- membuat database
CREATE DATABASE kuliah_pbo_6498;

-- menggunakan database
USE kuliah_pbo_6498;

-- membuat tabel suplayer
CREATE TABLE suplayer6498 (
    kode VARCHAR(10) NOT NULL,
    nama VARCHAR(40) NOT NULL,
    alamat VARCHAR(50) NOT NULL,
    kota VARCHAR(20) NOT NULL,
    provinsi VARCHAR(25) NOT NULL,
    telepon VARCHAR(30) NOT NULL,
    email VARCHAR(30) NOT NULL
) ENGINE = InnoDB;