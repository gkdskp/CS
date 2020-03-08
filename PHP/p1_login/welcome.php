<?php
    /* User profile page */
    
    include("config.php");
    $id = $_SESSION["id"];

    if(!$id){
        header("Location: index.php");
    }

    if($_GET["logout"]){
        if(session_destroy()){
            header("Location: index.php");
        }
        echo "<div class=\"success notif\">Logged out successfully/div>";
        sleep(1);
        header("Location: index.php");
    }

    $query = mysqli_query(
        $con,
        "SELECT * FROM Profile WHERE id=$id"
    );

    $row = mysqli_fetch_array($query, MYSQLI_ASSOC);
    $name = $row["lname"];
    $username = $row["uname"];
    $email = $row["email"];
    $age = $row["age"];
    $address = $row["uaddress"];
    $city = $row["city"];
    $zip = $row["zip"];
    $joindate = $row["joindate"];
?>

<!DOCTYPE html>
<html>
	<head>
		<link rel="stylesheet" href="assets/style.css">
    </head>
    
	<body>
		<div id="container">
            <div class="profile-container">
                <h1> Welcome <?php echo $username ?>,</h1>
                <h2>Your details:</h2>

                <div class="table">
                    <div class="trow">
                        <div class="tcell">Name: </div>
                        <div class="tcell"><?php echo $name ?></div>
                    </div>

                    <div class="trow">
                        <div class="tcell">Email: </div>
                        <div class="tcell"><?php echo $email ?></div>
                    </div>

                    <div class="trow">
                        <div class="tcell">Age: </div>
                        <div class="tcell"><?php echo $age ?></div>
                    </div>

                    <div class="trow">
                        <div class="tcell">Address: </div>
                        <div class="tcell"><?php echo $address ?></div>
                    </div>

                    <div class="trow">
                        <div class="tcell">City: </div>
                        <div class="tcell"><?php echo $city ?></div>
                    </div>

                    <div class="trow">
                        <div class="tcell">Zip: </div>
                        <div class="tcell"><?php echo $zip ?></div>
                    </div>
                    
                    <div class="trow">
                        <div class="tcell">Join Date: </div>
                        <div class="tcell"><?php echo $joindate ?></div>
                    </div>
                </div>
                <a href="welcome.php?logout=true">Log out</a> from your account
            </div>
		</div>
	</body>

</html>