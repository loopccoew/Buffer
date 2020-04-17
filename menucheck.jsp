<%@page import="com.DB"%>
<%@page import="java.sql.*"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>


<% 
int count=0;
Connection con=DB.conc(); 
ResultSet rs=null; 
Statement stmt=con.createStatement(); 
HttpSession sess = request.getSession(false);
int pno=Integer.parseInt(sess.getAttribute("pno2").toString());
String str="select day from menu where pno="+pno;
rs=stmt.executeQuery(str);
while(rs.next())
{
	count++;
}
System.out.println(count);
if(count==7)
{
	response.sendRedirect("provcost.jsp");
}
else
{
	System.out.println("Else mdhe ala");
	%>
	
	<script>	
		alert("Enter menu for all the days!");
	
	</script>
	
<%
response.sendRedirect("menu_new.jsp");
}
%>
</body>
</html>