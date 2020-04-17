<%@page import="javax.swing.*" %>
<%@page import="java.awt.*" %>
<%@page import="com.DB" %>
<%@page import="java.sql.*"%>
<%@page import="java.util.*"%>
<%@page import="javax.swing.table.*"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>

<style>
	
	.tab-2{margin-left: 50px}
	.tab-2 input{display: block;margin-bottom: 20px}
</style>
</head>
 <body bgcolor=aqua>

<form action="menu_newcheck.jsp" name="menu" id="menu" method="post" >


	<table border="1" align="center" >
	<tr bgcolor=pink>
	<th>Day</th>
	<th>Gravy</th>
	<th>Dryveg</th>
	<th>Chapati</th>
	<th>Sides</th>
	<th>Rice</th>
	<th>Special</th>
	</tr>
	<%
		ResultSet rs=null;
		Connection con=DB.conc();
		Statement stmt=con.createStatement();
		HttpSession sess = request.getSession(false);
		int pno=Integer.parseInt(sess.getAttribute("pno2").toString());
		String qry = "select * from menu where pno="+pno;
		rs = stmt.executeQuery(qry);
		while(rs.next())
		{
		%>
		<tr bgcolor=pink>
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
		%>
	
	</table>
	
	<div class="tab-2" align="left">
Day<input type="text" name="day" id="day" required="">
Gravy<input type="text" name="gravy" id="gravy" required="">
Dry_veg<input type="text" name="dryveg" id="dryveg" required="">
Chapati<input type="text" name="chapati" id="chapati" required="">
Sides<input type="text" name="sides" id="sides" required="">
Rice <input type="text" name="rice" id="rice" required="">
Special<input type="text" name="special" id="special" required="">

 <button onClick="onClick()">Add</button>

</div>
</div>

</form>
<button onClick="myfunc()">Submit</button>
<script>
function myfunc()
{
	window.location.href="menucheck.jsp";
}
</script>

		</body>
</html>
