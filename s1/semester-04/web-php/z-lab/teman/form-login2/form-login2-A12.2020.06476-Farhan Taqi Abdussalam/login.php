<?php 
session_start();

if(isset($_SESSION['id'])){
  header("location: index.php");
  exit();
}
?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link
      href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css"
      rel="stylesheet"
      integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3"
      crossorigin="anonymous"
    />
    <title>Document</title>
  </head>
  <body>
    <?php 
    if(isset($_GET['error'])){
      function alertWindow($message){
        echo "<script type ='text/JavaScript'>";  
        echo "alert('$message')";  
        echo '</script>';
      }
      alertWindow($_GET['error']);
      
    }
    ?>
    <div class="container-fluid d-flex justify-content-center">
      <div class="col-md-3 mt-3">
        <form class="border border-2 p-4" action="session.php" method="post">
          <div class="mb-2">
            <label for="username" class="form-label">Username</label>
            <input
              type="text"
              class="form-control"
              id="username"
              placeholder="Username"
              name="username"
              required
              autofocus
            />
          </div>
          <div class="mb-2">
            <label for="password" class="form-label">Password</label>
            <input
              type="password"
              class="form-control"
              id="password"
              name="password"
              placeholder="Password"
              required
            />
          </div>
          <button type="submit" class="btn btn-primary" name="submit">
            Submit
          </button>
        </form>
      </div>
    </div>
  </body>
</html>
