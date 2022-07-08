<?php
$klp = $_POST['klp']; //A12.62
?>
<select class="form-control" name="klp" id="klp">
    <?php
    $arrno = array('01','02','03','04','05','06','07','08','09','10',);
    for($i=0;$i<count($arrno);$i++){
        $klpkul=$klp.$arrno[$i];
        echo "<option value=$klpkul>$klpkul";
    }
    ?>
</select>