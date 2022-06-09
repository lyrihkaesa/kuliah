-- Masuk ke SQL
-- mysql - u root 
-- 
-- membuat database
CREATE DATABASE kuliah_web;

-- menggunakan database
USE kuliah_web;

-- membuat tabel users
CREATE TABLE users (
    id INT NOT NULL AUTO_INCREMENT,
    username VARCHAR(50) NOT NULL,
    `password` VARCHAR(50) NOT NULL,
    PRIMARY KEY (id)
)  ENGINE=INNODB;

-- menambahkan/memasukan/insert/input users
INSERT INTO
    users (username, `password`)
VALUES
    ("kukuh", "rahasia"),
    ("setya", "password");

CREATE TABLE mhs (
    Nim CHAR(15) NOT NULL,
    Nama VARCHAR(50),
    jkel CHAR(1),
    prodi CHAR(10),
    IPK DOUBLE
)  ENGINE=INNODB;

SHOW TABLES;

DROP TABLE mhs;

INSERT INTO mhs(NIM, nama, ipk) VALUES ('A12.2020.00800', 'Ani', 4.0);

SELECT * FROM mhs;
    
    
SELECT 
    *
FROM
    users;