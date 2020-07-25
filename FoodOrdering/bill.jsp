<!DOCTYPE html>
<%@page import="java.sql.DriverManager"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.Statement"%>
<%@page import="java.sql.Connection"%>
<%@page import="com.DB"%>

<html>
<head>
<title>BILL</title>
</head>
<body>
	<p><strong>BILL</strong></p>
	<p>---------------------------------</p>
	<script type="text/javascript">
		var dt = new Date();
		var year = dt.getYear();
		if (year < 1000) {
			year = year + 1900;
		}
		var myDay = dt.getDay();
		var daym = dt.getDate();
		var month = dt.getMonth();
		// Array of days. 
		var weekday = [ 'Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday',
				'Friday', 'Saturday' ];
		var montharr = [ 'January', 'February', 'March', 'April', 'May',
				'June', 'July', 'August', 'September', 'October', 'November',
				'December' ];
		document.write(daym);
		document.write(montharr[month]);
		document.write(year);
		document.write("<br/>");
		document.write(weekday[myDay]);
	</script>

	<p>----------------------------------</p>


	<table border="1" cellpadding="5" cellspacing="5">

		<th>Provider</th>
		<th>Item name</th>
		<th>Quantity</th>
		<th>Cost / Item</th>
		<th>Sub Amount</th>

		<%
			String driverName = "com.mysql.jdbc.Driver";
			String connectionUrl = "jdbc:mysql://localhost/Dabewala";
			try {
				Class.forName(driverName);
			} catch (ClassNotFoundException e) {
				e.printStackTrace();
			}
			Statement stmt = null;
			ResultSet rs = null;
			Connection con = DB.conc();
			stmt = con.createStatement();
			HttpSession sess=request.getSession(false);
			int provno = Integer.parseInt(sess.getAttribute("pno").toString());
		
			int regno1 = Integer.parseInt(sess.getAttribute("regno").toString());
			//String name=sess.getAttribute("name1").toString();
			String choice=sess.getAttribute("tiff").toString();
			int quantity = Integer.parseInt(sess.getAttribute("quant").toString());
			String q;
			String tiff = "none";
			if (choice.compareTo("Single Tiffin")==0) {
				q = "select business , scost from provdetails where pno =" + provno;
				tiff = "Single tiffin";
			} else {
				q = "select business , mcost from provdetails where pno =" + provno;
				tiff = "Monthly tiffin";
			}
			rs = stmt.executeQuery(q);
			double fin=0;
			fin = 10 * quantity;
			while (rs.next()) {
				double price = rs.getDouble(2);
				double sub = price * quantity;
				fin = fin + sub;
		%>
		<tr>
			<td><%=rs.getString(1)%></td>
			<td><%=tiff%></td>
			<td><%=quantity%></td>
			<td><%=price%></td>
			<td><%=sub%></td>




		</tr>
		<%
			}
			
			stmt.executeUpdate("insert into provcust values("+regno1+","+provno+",'"+tiff+"',"+quantity+")");
		%>




	</table>




	</table>
<table border="1" cellspacing="5" cellpadding="5">
	<tr>
		<td width="470">Service charges / Item</td>
		<td width="80">10</td>
		
	</tr>
	<tr>
		<td><strong>Total Amount</strong></td>
		<td><strong><%=fin%></strong></td>
	</tr>
</table>
<p align="center"><strong>THANK YOU!</strong></p>
<center>
<p ><strong>How would you rate this provider?</strong></p>


<form name="rate" action="rating.jsp">
<input type="radio" name="rating" value="1">1
<input type="radio" name="rating" value="2">2
<input type="radio" name="rating" value="3">3
<input type="radio" name="rating" value="4">4
<input type="radio" name="rating" value="5">5
<br>
<br>
<button type="submit" style="background-color: blue;color: white;width: 75px;height: 40px">Rate Now!</button>
</form>

<center>
<br><br></br></br>
<button  type="submit" onclick="myFunctions()" style="background-color:blue;color: white;width: 150px;height: 50px">Logout</button><br><br>
<script>
function myFunctions() {
  window.location.href = "index.html";
}
</script>
</button>
<button  type="submit" onclick="myFunctionn()" style="background-color:blue;color: white;width: 150px;height: 50px">Place Another Order</button><br><br>
<script>
function myFunctionn() {
  window.location.href = "displayprovider.jsp";
}
</script>
</center>

</button>
</body>
</html>
