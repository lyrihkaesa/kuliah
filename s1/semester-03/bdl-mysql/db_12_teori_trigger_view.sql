CREATE DATABASE db_12_teori_trigger;

CREATE TABLE Barang (
  Kode CHAR(5),
  Nama VARCHAR(20),
  Grade CHAR(1),
  Harga INT,
  Prosen INT,
  Jumlah INT,
  KDPemasok CHAR(5)
);

INSERT INTO Barang VALUES
  ('11111','Buku','A','5000','25','80','AP001'),
  ('11112','Pensil','A','2500','25','100','AP001'),
  ('11113','Penggaris','B','2000','30','50','AP001'),
  ('11114','Sandal','B','50000','30','25','AP002'),
  ('11115','Sepatu','A','200000','25','20','AP002'),
  ('11116','Sarung','B','100000','35','50','AP003'),
  ('11117','Peci','C','55000','40','50','AP003'),
  ('11118','Topi','A','50000','25','25','AP020'),
  ('11119','Bola','A','25000','30','20','AP020'),
  ('11120','Sabun','B','2500','30','45','AP550'),
  ('11121','Baterai AA','B','2500','25','90','AP801'),
  ('11122','Roti','C','5000','35','100','AP011');

CREATE TABLE Pemasok (
    KDPemasok CHAR(5),
    Nama VARCHAR(20),
    Kota VARCHAR(16),
    Grade CHAR(1)
  );

INSERT INTO Pemasok VALUES
  ('AP001', 'Cerdas', 'Semarang', 'A'),
  ('AP002', 'Lancar', 'Jogja', 'A'),
  ('AP003', 'Selamat', 'Lumajang', 'B'),
  ('AP011', 'Kuat', 'Surabaya', 'B'),
  ('AP020', 'Sehat', 'Bandung', 'C'),
  ('AP550', 'Segar', 'Bandung', 'B'),
  ('AP801', 'Terang', 'Bandung', 'B');

DELIMITER //

CREATE TRIGGER update_field_grade_pemasok_1
  BEFORE UPDATE
  ON pemasok
  FOR EACH ROW
  BEGIN
    DECLARE xgrade CHAR;
    DECLARE xglvlold INT;
    DECLARE xglvlnew INT;
    SET xgrade = (
      SELECT grade FROM pemasok WHERE KDPemasok = new.KDPemasok
    );

    CALL gantiG(xgrade, xglvlold);
    CALL gantiG(new.grade, xglvlnew);

    IF(new.grade < xgrade) THEN
      UPDATE barang 
      SET 
        grade = new.grade,
        prosen = prosen - 5
      WHERE KDPemasok = new.KDPemasok;
    ELSE
      UPDATE barang
      SET 
        grade = new.grade,
        prosen = prosen + 5
      WHERE KDPemasok = new.KDPemasok;
    END IF;
  END //



-- BARU BUATAN KAESA
CREATE TRIGGER update_field_grade_pemasok_2
  BEFORE UPDATE
  ON pemasok
  FOR EACH ROW
  BEGIN
    DECLARE xgrade CHAR;
    SET xgrade = (
      SELECT grade FROM pemasok WHERE KDPemasok = new.KDPemasok
    );

    IF(new.grade = 'A') THEN
      IF(xgrade = 'B' OR xgrade = 'C') THEN
        UPDATE barang 
        SET 
        grade = new.grade,
        prosen = prosen - 5
        WHERE KDPemasok = new.KDPemasok;
      END IF;
    ELSEIF(new.grade = 'B') THEN
      IF(xgrade = 'A') THEN
        UPDATE barang 
        SET 
        grade = new.grade,
        prosen = prosen + 5
        WHERE KDPemasok = new.KDPemasok;
      ELSEIF(xgrade = 'C') THEN
        UPDATE barang 
        SET 
        grade = new.grade,
        prosen = prosen - 5
        WHERE KDPemasok = new.KDPemasok;
      END IF;
    ELSEIF(new.grade = 'C') THEN
      IF(xgrade = 'A' OR xgrade = 'B') THEN
        UPDATE barang 
        SET 
        grade = new.grade,
        prosen = prosen + 5
        WHERE KDPemasok = new.KDPemasok;
      END IF;
    END IF;
  END //


-- Baru lagi buatan kaesa
CREATE TRIGGER update_field_grade_pemasok_3
  BEFORE UPDATE
  ON pemasok
  FOR EACH ROW
  BEGIN
    DECLARE xgrade CHAR;
    SET xgrade = (
      SELECT grade FROM pemasok WHERE KDPemasok = new.KDPemasok
    );

    IF(new.grade < xgrade) THEN
      UPDATE barang 
        SET 
        grade = new.grade,
        prosen = prosen - 5
        WHERE KDPemasok = new.KDPemasok;      
    ELSEIF(new.grade > xgrade) THEN
      UPDATE barang 
        SET 
        grade = new.grade,
        prosen = prosen + 5
        WHERE KDPemasok = new.KDPemasok;
    END IF;
  END //

-- PROCEDURE 
CREATE PROCEDURE cBP(IN xKDPemasok CHAR(5))
  BEGIN
    SELECT * FROM Barang WHERE KDPemasok = XKDPemasok;
    SELECT * FROM Pemasok WHERE KDPemasok = XKDPemasok;
  END //


CREATE PROCEDURE gantiG(IN xgrade CHAR(1), OUT xlevel INT)
  BEGIN
    IF(xgrade = 'A') THEN
      SET xlevel = 1;
    ELSEIF (xgrade = 'B') THEN
      SET xlevel = 2;
    ELSEIF (xgrade = 'C') THEN
      SET xlevel = 3;
    ELSE 
      SET xlevel = 99;
    END IF;
  END //

DELIMITER ;


CALL cBP("AP003");
UPDATE pemasok SET grade = "B" WHERE KDPemasok = "AP003";