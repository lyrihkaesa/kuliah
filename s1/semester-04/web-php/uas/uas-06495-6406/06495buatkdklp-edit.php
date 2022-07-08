<?php
$klplama = $_POST['klplama']; //contoh: A12.6203
$kdklplama = substr($_POST['klplama'],0,6); //A12.62
$noklplama = substr($_POST['klplama'],7,2); //03
?>
<select class="form-control" name="klp" id="klp">
    <?php
    $arrno = array('01','02','03','04','05','06','07','08','09','10',);
    for($i=0;$i<count($arrno);$i++){
        if ($noklplama==$arrno[$i]){
            echo "<option value=$klplama selected>$klplama";
        }else{
            $daftklp = $kdklplama.$arrno[$i]; //A12.6201 loop1
            echo "<option value=$daftklp>$daftklp";
        }
    }
    ?>
</select>