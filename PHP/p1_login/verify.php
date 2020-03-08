<?php
    /* Script to check the info user typed and verify or add the data to database */

    include("config.php");

    if($_SESSION["id"]){
        header("Location: welcome.php");
    }

    if(isset($_POST["login-submit"])){
        $username = mysqli_real_escape_string($con, $_POST['username']);
        $password = mysqli_real_escape_string($con, $_POST['password']);
        
        $query = mysqli_query(
            $con, 
            "SELECT id FROM Profile WHERE uname='$username' AND passwd='$password'"
        );
        $row = mysqli_fetch_array($query, MYSQLI_ASSOC);
        $found = mysqli_num_rows($query);

        if(!$found){
            echo "<div class=\"error notif\">User not found</div>";
        }

        else{
            echo "<div class=\"success notif\">Succesfully logged in.</div>";
            $_SESSION["id"] = $row["id"];
            sleep(1);
            header("Location: welcome.php");
        }
    }

    if(isset($_POST["signup-submit"])){
        $found = $_POST["username"];

        $username = mysqli_real_escape_string($con, $_POST['username']);
        $name = mysqli_real_escape_string($con, $_POST['name']);
        $email = mysqli_real_escape_string($con, $_POST['email']);
        $password = mysqli_real_escape_string($con, $_POST['password']);
        $age = mysqli_real_escape_string($con, $_POST['age']);
        $address = mysqli_real_escape_string($con, $_POST['address']);
        $city = mysqli_real_escape_string($con, $_POST['city']);
        $zip = mysqli_real_escape_string($con, $_POST['zip']);
        $date = date('Y-m-d H:i:s');

        $query = mysqli_query(
            $con,
            "INSERT INTO 
            Profile (uname, lname, email, passwd, age, uaddress, city, zip, joindate)
            VALUES ('$username', '$name', '$email', '$password', '$age', '$address',
            '$city', '$zip', '$date')"
        );

        if($query){
            $id = mysqli_insert_id($con);
            echo "<div class=\"success notif\">User added successfully</div>";
            $_SESSION["id"] = $id;
            sleep(1);
            header("Location: welcome.php");
        }

        else{
            echo "<div class=\"error notif\">Please insert valid inputs</div>";
        }
    }
?>