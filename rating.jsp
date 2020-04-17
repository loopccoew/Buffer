<!DOCTYPE html>
<%@page import="java.sql.DriverManager"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.Statement"%>
<%@page import="java.sql.Connection"%>
<%@page import="com.DB"%>
<html>
<head>
	<title></title>
</head>
<body>

	<%
			
			Statement stmt = null;
			ResultSet rs = null;
			Connection con = DB.conc();
			stmt = con.createStatement();
			String radioRate = request.getParameter("rating");
			int rat = Integer.parseInt(radioRate);
			HttpSession sess=request.getSession(false);
			int pno = Integer.parseInt(sess.getAttribute("pno").toString());
			String q = "update provdetails set rating = "+rat+" where pno="+pno;
			stmt.executeUpdate(q);
			response.sendRedirect("bill.jsp");
	%>

</body>
</html>