<!DOCTYPE html>
<html>
<head>
<style type="text/css">
body{
background-size:cover
}
</style>
	<title>Register page</title>
	<link rel="stylesheet" type="text/css" href="style1.css">
</head>
<body background="C:\Users\User\workspace\test1\Test1\WebContent\pic.jpg">
<div class="hero">
	<div class="form-box">
		<form action="regcheck.jsp" method="post" class="input_grp">
<br></br>
<center>
<h1>Register page</h1>
</center>
<br></br>
<h3>User Name 
<p><input type="text" class = "field" name="username"  placeholder="enter name" required=""></p>
Company Name
<p><input type="text" class = "field" name="cmp" placeholder="enter company name" required="">
Address
<p><input type="text" class = "field" name="addr" placeholder="Enter address" required="">
Contact no
<p><input type="tel" class = "field" name="tele" placeholder="enter contact number" minlength="10" required="" >
Password
<p><input type="password" class = "field" name="pwd" placeholder="Enter password" required="">
</h3>
<br></br>
<p><input type="submit" class="btn" value="submit">

</form>
		



	</div>


</div>
</body>
</html>