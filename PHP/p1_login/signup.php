<?php
	/* Sign up page */
	
	include("verify.php");
?>

<!DOCTYPE html>
<html>
	<head>
		<link rel="stylesheet" href="assets/style.css">
	</head>
	<body>
		<div id="container">
			<div class="form-container">
				<form name="signup" method="POST" action="signup.php">
					<h2>Sign Up</h2>
					<label for="username">Username:</label><br/>
					<input name="username" type="text">
					<br/>

          <label for="name">Name:</label><br/>
					<input name="name" type="text">
          <br/>
                    
					<label for="email">Email:</label><br/>
					<input name="email" type="text">
					<br/>

					<label for="password">Password:</label><br/>
					<input name="password" type="password">
          <br/>

          <label for="age">Age:</label><br/>
          <input name="age" type="number" max="115">
          <br/>

          <label for="address">Address:</label><br/>
          <textarea name="address"></textarea><br/>

          <label for="city">City:</label><br/>
					<input name="city" type="text">
          <br/>

          <label for="zip">Zip code:</label><br/>
					<input name="zip" type="number">
          <br/>

					<button type="submit" name="signup-submit">Sign Up</button>
					<br/>
						
					<a href="index.php">Log in</a> to your account
				</form>
			</div>

		</div>
	</body>

</html>