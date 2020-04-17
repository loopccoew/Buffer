<%@page import="java.sql.*"%>
	<%@page import="com.DB" %>
<%@page import="javax.swing.JOptionPane" %>

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
String pno=request.getParameter("pno");
String day=request.getParameter("day");
String gravy=request.getParameter("gravy");
String dryveg=request.getParameter("dryveg");
String chapati=request.getParameter("chapati");
String sides=request.getParameter("sides");
String rice=request.getParameter("rice");
String special=request.getParameter("special");
Connection con=DB.conc();
String query="update menu set day='"+day+"',gravy='"+gravy+"',dryveg='"+dryveg+"',chapati='"+chapati+"',sides='"+sides+"',rice='"+rice+"',special='"+special+"' where pno="+pno+" and day='"+day+"'";
Statement stmt=con.createStatement();
int r=stmt.executeUpdate(query);
if(r!=0)
{
	JOptionPane.showMessageDialog(null,"success");
	response.sendRedirect("menu.jsp");
}
else
{
	JOptionPane.showMessageDialog(null,"failed");
	response.sendRedirect("reg.jsp");
}
%>
</body>
</html>