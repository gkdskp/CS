<?php
    /* Database configuration file */
    
    session_start();
    
    $host = "localhost";
    $user = "gokul";
    $passwd = "1821";
    $db = "Users";

    $con = mysqli_connect($host, $user, $passwd, $db);
    if(!$con){
        echo "<div class=\"error notif\">Database not found</div>";
    }
?>