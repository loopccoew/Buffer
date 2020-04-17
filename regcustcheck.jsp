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
	String username=request.getParameter("username");
	String tele=request.getParameter("tele");
	String pwd=request.getParameter("pwd");
	String addr=request.getParameter("addr");
	Connection con=DB.conc();
	String str="regno,'"+username+"',"+tele+",'"+addr+"'";
	Statement stmt=con.createStatement();
	int r=stmt.executeUpdate("insert into custdetails "+"values("+str+")");
	if(r!=0)
	{
		JOptionPane.showMessageDialog(null,"success");
		ResultSet rs=stmt.executeQuery("select regno from custdetails where telno = "+tele);
		if(rs.next())
		{
			int regno1=rs.getInt(1);
			HttpSession sess = request.getSession(false);
			sess.setAttribute("regno",regno1);
			response.sendRedirect("displayprovider.jsp");
		}
	}
	else
	{
		JOptionPane.showMessageDialog(null,"failed");
		response.sendRedirect("regcust.jsp");
	}
%>
</body>
</html>