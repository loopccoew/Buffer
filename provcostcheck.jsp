<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
    <%@page import="com.DB" %>
    <%@page import="java.sql.*"%>
    <%@page import="javax.swing.JOptionPane" %>
    
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
<%
	float scost=Float.parseFloat(request.getParameter("scost"));
	float mcost=Float.parseFloat(request.getParameter("mcost"));
	Connection con=DB.conc();
	Statement stmt=con.createStatement();
	
	 HttpSession sess=request.getSession(false);
	int pno=Integer.parseInt(sess.getAttribute("pno2").toString());
	String qq;
	qq="update provdetails set scost="+scost+",mcost="+mcost+" where pno="+pno;
	int r=stmt.executeUpdate(qq);
	if(r!=0)
	{
		JOptionPane.showMessageDialog(null,"success");
		response.sendRedirect("aed.jsp");
	}
	else
	{
		JOptionPane.showMessageDialog(null,"failed");
		response.sendRedirect("reg.jsp");
	}
%>
</body>
</html>