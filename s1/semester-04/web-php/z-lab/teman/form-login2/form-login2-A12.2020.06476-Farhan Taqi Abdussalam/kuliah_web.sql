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
    password VARCHAR(30) NOT NULL,
    PRIMARY KEY (id)
) ENGINE = InnoDB;

-- menambahkan/memasukan/insert/input users
INSERT INTO
    users (
        username,
        password
    )
VALUES
    ("farhan", "::hash"),
    ("taqi", "123"),
    ("abdussalam", "SUS");