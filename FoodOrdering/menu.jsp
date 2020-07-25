<%@page import="java.sql.*" %>
<%@page import="com.DB" %>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>

<body bgcolor=aqua>
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
HttpSession sess=request.getSession(false);
int pno2=Integer.parseInt(sess.getAttribute("pno2").toString());
String qry = "select * from menu where pno="+pno2;
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
<br></br>

<button  type="submit" onclick="myFunction()" style="background-color:blue;color: white;width: 200px;height: 50px">Back</button><br><br>
<script>
function myFunction() {
  window.location.href = "aed.jsp";
}
</script>
</center>
</table>
</body>
</html>
