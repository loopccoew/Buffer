<!DOCTYPE html>
<html>
<head>
	<title>PROVIDER : MENU</title>
</head>
<body background="C:\Users\User\workspace\test1\Test1\WebContent\pic.jsp">

	<p align="center"><strong>Provider Menu</strong></p>
		<!--  <div align="center">-->
		<center>
		<form name="disp" action="menu_new.jsp">
		<button  style="background-color: green;color: white;width: 200px;height: 50px">ADD</button><br><br>
	</form>
		<form name="disp" action="menuedit.jsp">
		<button style="background-color: orange;color: white;width: 200px;height: 50px">EDIT</button><br><br>
	</form>
		<form name="disp" action="menu.jsp">
		<button style="background-color: blue;color: white;width: 200px;height: 50px" type="submit">DISPLAY</button><br><br>
		
		</form>
		<form name="disp" action="order.jsp">
		<button  style="background-color: green;color: white;width: 200px;height: 50px">PENDING ORDERS</button><br><br>
		</form>
		<form action="index.html">
		<button name="logout" >LOGOUT</button>
		</form>
		</center>
		

</body>
</html>
