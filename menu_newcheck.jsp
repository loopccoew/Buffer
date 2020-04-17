<%@page import="java.sql.*"%>
<%@page import="javax.swing.JOptionPane" %>

<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
	<%@page import="com.DB" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
<%
	String day=request.getParameter("day");	
	String gravy=request.getParameter("gravy");
	String dry_veg=request.getParameter("dryveg");
	String chapati=request.getParameter("chapati");
	String sides=request.getParameter("sides");
	String rice=request.getParameter("rice");
	String special=request.getParameter("special");
	int clicks;
	HttpSession sess=request.getSession(false);
	
	int pno2=Integer.parseInt(sess.getAttribute("pno2").toString());
	String query="insert into menu values("+pno2+",'"+day+"','"+gravy+"','"+dry_veg+"','"+chapati+"','"+sides+"','"+rice+"','"+special+"')";
	Connection con=DB.conc();
	Statement stmt=con.createStatement();
	int r=stmt.executeUpdate(query);
	if(r!=0)
	{
		JOptionPane.showMessageDialog(null,"success");
		response.sendRedirect("menu_new.jsp");
	}
	else
	{
		JOptionPane.showMessageDialog(null,"failed");
		response.sendRedirect("reg.jsp");
	}
%>
</body>
</html>