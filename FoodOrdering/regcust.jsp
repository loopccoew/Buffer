<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<style type="text/css">
body{
background-size:cover
}
</style>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<link rel="stylesheet" type="text/css" href="style1.css">
<title>Register Customer</title>
</head>
<body background="C:\Users\User\workspace\test1\Test1\WebContent\pic.jpg">
<div class="hero">
	<div class="form-box">

<form action="regcustcheck.jsp" method="post" class="input_grp">
<br></br>
<center>
<h1>Register page</h1>
</center>
<br></br>
<h3>User Name
<p><input type="text" class = "field" name="username"  placeholder="enter name" required=""></p>
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
