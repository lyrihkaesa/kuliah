<?php
session_start();

if (!isset($_SESSION['id'])) {
  header("Location: login.php");
  exit();
}
?>

<!DOCTYPE html>
<html lang="en">

<head>
  <!-- Required meta tags -->
  <meta charset="utf-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1" />

  <!-- Bootstrap CSS -->
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous" />
  <title>My Portfolio</title>
</head>

<body>
  <header class="bg-light p-5 rounded-lg m-3 text-center">
    <h1 class="display-4">My Portfolio</h1>
    <p class="lead">Website Statik Portfolio Saya</p>
  </header>
  <!-- Navbar Start -->
  <nav class="navbar navbar-expand-sm navbar-dark bg-dark">
    <div class="mx-auto d-sm-flex d-block flex-sm-nowrap">
      <!-- <a class="navbar-brand" href="#">My Portfolio</a> -->
      <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarsExample11" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
      </button>
      <a href="logout.php" class="btn btn-danger text-white me-2 d-sm-none">Logout</a>
      <div class="collapse navbar-collapse text-center" id="navbarsExample11">
        <ul class="navbar-nav">
          <li class="nav-item">
            <a class="nav-link active" aria-current="page" href="#">Home</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="#">About</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="#">Help</a>
          </li>
        </ul>
      </div>
      <a href="logout.php" class="btn btn-danger text-white ms-2 d-none d-sm-block">Logout</a>
    </div>
  </nav>
  <!-- Navbar End -->

  <!-- Container Start -->
  <div class="container mt-2">
    <div class="row align-items-center">
      <div class="col-md-4 text-center mb-2">
        <img class="img-thumbnail" src="img/A12.2020.06495.jpg" alt="My Photo Profile" />
      </div>
      <div class="col-md-8 rounded-3">
        <table class="table table-dark rounded-3 overflow-hidden table-borderless table-striped text-ce">
          <tbody>
            <tr>
              <th scope="row">NIM</th>
              <td>:</td>
              <td>A12.2020.06495</td>
            </tr>
            <tr>
              <th scope="row">Nama</th>
              <td>:</td>
              <td>Kukuh Setya Arumansyah</td>
            </tr>
            <tr>
              <th scope="row">Jenis Kelamin</th>
              <td>:</td>
              <td>Laki-Laki</td>
            </tr>
            <tr>
              <th scope="row">TTL</th>
              <td>:</td>
              <td>Grobogan, DD Mei 2002</td>
            </tr>
            <tr>
              <th scope="row">Asal Sekolah</th>
              <td>:</td>
              <td>SMK Negeri 2 Purwodadi</td>
            </tr>
            <tr>
              <th scope="row">Alamat</th>
              <td>:</td>
              <td>Dusun Sendangsari, RT05, RW07.</td>
            </tr>
            <tr>
              <th scope="row">Email</th>
              <td>:</td>
              <td>112202006495@mhs.dinus.ac.id</td>
            </tr>
          </tbody>
        </table>
      </div>

    </div>
  </div>
  <!-- Container End -->

  <!-- Footer Start -->
  <footer class="bg-dark text-light text-center">
    <hr />
    <p>??2022 | Pemrograman Web</p>
    <hr />
  </footer>
  <!-- Footer End -->

  <!-- Optional JavaScript; choose one of the two! -->

  <!-- Option 1: Bootstrap Bundle with Popper -->
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>

  <!-- Option 2: Separate Popper and Bootstrap JS -->
  <!--
    <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.10.2/dist/umd/popper.min.js" integrity="sha384-7+zCNj/IqJ95wo16oMtfsKbZ9ccEh31eOz1HGyDuCQ6wgnyJNSYdrPa03rtR1zdB" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.min.js" integrity="sha384-QJHtvGhmr9XOIpI6YVutG+2QOK9T+ZnN4kzFN1RtK3zEFEIsxhlmWl5/YESvpZ13" crossorigin="anonymous"></script>
    -->
</body>

</html>