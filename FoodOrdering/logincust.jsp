<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<link rel="stylesheet" type="text/css" href="style2.css">
<title>Login</title>

</head>
<body>
<div class="loginbox">
<img src="avatar.png" class="avatar" align="center">
<form action="logincustcheck.jsp" method="post">
<br><br></br></br>
<h1><font color="white">Login page</h1>
<h2><font color="white" align="center"><p>User Name </p></h2>
<p><input type="text" name="username"  placeholder="enter name" required=""></p>

<h2><font color="white"><p>Password</p></h2>
<p><input type="password" name="pwd" placeholder="Enter password" required=""></p>

<h2><font color="white" align="center"><p> Contact number </p></h2>
<p><input  type="tel" name="tele" placeholder="Enter contact number" required="" minlength="10"></p>

<p><input type="submit" value="submit"></p>
</form>

<p>Don't have an account?</p>
<p><h2><a href="regcust.jsp" >Register now</a></p></h2>
</div>
</body>
</html>
