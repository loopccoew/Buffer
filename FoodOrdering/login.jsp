<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<style type="text/css">
.body{
background-size:cover
}
</style>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<link rel="stylesheet" type="text/css" href="style2.css">
<title>Provider Login</title>

</head>
<body background="C:\Users\User\workspace\test1\Test1\WebContent\pic.jpg">
<div class="loginbox">
 
<img src="C:\Users\User\workspace\test1\Test1\WebContent\avatar.png" class="avatar" align="center">
</img>
<form action="logincheck.jsp"  name="login" id="login" method="login"  onsubmit="return validateForm();">
<script>
window.onload = function(){
    var form = document.getElementById("login");
    form.onsubmit = function(){
        var inputs = form.getElementsByTagName("input"), input = null, flag = true;
        for(var i = 0, len = inputs.length; i < len; i++) {
            input = inputs[i];
            if(!input.value) {
                flag = false;
                input.focus();
                alert("Please fill all the inputs");
				clicks=clicks-1;
                break;
            }
        }
        return(flag);
    };
};
</script>
<br><br><br></br></br></br>
<h1><font color="white">Login page</h1>
<h2><font color="white" align="center"><p> Contact number </p></h2>
<p><input  type="tel" name="tele"  placeholder="enter contact number" minlength="10"></p>
<br></br>
<h2><font color="white"><p>Password</p></h2>
<p><input type="password" name="pwd" placeholder="Enter password"></p>
<font color="white">
<p><input type="submit" value="submit"></p>
</form>
<p>Don't have an account?</p>
<a href="reg.jsp"><font color="white"><h2>Register now</a></h2>
</div>


</div>

</body>
</html>
