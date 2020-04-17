 <%@page import="java.sql.*" %>
<%@page import="com.DB" %>


<%@ page language="java" contentType="text/html; charset=ISO-8859-1"

    pageEncoding="ISO-8859-1"%>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html> 

<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<head> 
<style type="text/css">
body{
background-size:cover
}
</style>

    <title> 

         Menu and Quantity 

    </title> 

</head> 
<body background="C:\Users\User\workspace\test1\Test1\WebContent\food.jpg"> 

<center>
<table border="1" >

<tr bgcolor=pink>

<td>pno</td>

<td>day</td>

<td>gravy</td>

<td>dryveg</td>

<td>chapati</td>

<td>sides</td>

<td>rice</td>

<td>special</td>

</tr>



<%

try{

ResultSet rs=null;

Connection con=DB.conc();

Statement stmt=con.createStatement();
HttpSession sess = request.getSession(false);

int pno=Integer.parseInt(sess.getAttribute("pno").toString());
String qry = "select * from menu where pno="+pno;

rs = stmt.executeQuery(qry);

while(rs.next())

{

%>

<tr bgcolor=pink>

<td><%=rs.getString(1)%></td>

<td><%=rs.getString(2)%></td>

<td><%=rs.getString(3)%></td>

<td><%=rs.getString(4)%></td>

<td><%=rs.getString(5)%></td>

<td><%=rs.getString(6)%></td>



<td><%=rs.getString(7)%></td>

<td><%=rs.getString(8)%></td>

</tr>



<%

}

}

catch(Exception ex)

{

System.out.println(ex);

}

%>
</table>
	<form name="frmQ" action="quantitycheck.jsp">
<br><br><br>
<br><br><br>
	<h2><label style="background-color:orange">Enter the quantity of tiffin</label></h2>
		<br><br><br>
		<input type="text" name="quantity"><br>
		<br><br><br><br>
	<h2><input type="radio" name="tiffin" value="Single Tiffin" style="background-color:orange"><label style="background-color:orange">Single Tiffin</label></h2>
    <h2><input type="radio" name="tiffin" value="Monthly Tiffin" style="background-color:orange"><label style="background-color:orange">Monthly Tiffin</label></h2>
<br><br><h1>
    <button type="submit">PLACE ORDER</button>
    </h1>

	</form>
    <br> 
</center>
  </body> 
</html>