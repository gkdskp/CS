<?php
	/* Running PHP: simple applications like login forms after setting up a 
	LAMP Stack */
	
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
				<form name="login" method="POST" action="index.php">
					<h2>Log In</h2>
					<label for="username">Username:</label><br/>
					<input name="username" type="text">
					<br/>

					<label for="password">Password:</label><br/>
					<input name="password" type="password">
					<br/>

					<button type="submit" name="login-submit">Log In</button>
					<br/>
						
					<a href="signup.php">Sign up</a> for an account
				</form>
			</div>
		</div>
	</body>

</html>