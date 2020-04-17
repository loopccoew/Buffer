<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@page import="java.sql.*"%>
<%@page import=" com.DB"%>
<%@page import="javax.swing.JOptionPane" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">

<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
<%
	Connection con=DB.conc();
	Statement stmt=con.createStatement();
	HttpSession sess=request.getSession(false);
	int provno=Integer.parseInt(sess.getAttribute("pno2").toString());
	int regno=Integer.parseInt(request.getParameter("custid").toString());
	String str="delete from provcust where regno = "+regno+" and pno = "+provno; 
	//ResultSet rs=null;
	int rs=stmt.executeUpdate(str);
	if(rs!=0)
	{
		JOptionPane.showMessageDialog(null,"success");
		response.sendRedirect("order.jsp");
	}
	else
	{
		JOptionPane.showMessageDialog(null,"failed");
		response.sendRedirect("order.jsp");
	}
%>
</body>
</html>