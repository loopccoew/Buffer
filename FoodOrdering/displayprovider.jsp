<%@page import="java.sql.*"%>
<%@page import="com.DB" %>
<%@page import="java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Provider</title>
</head>
<body background="C:\Users\user\Downloads\online-food-ordering-2.jpg">
<center>

<table border="1" align="center">
<tr bgcolor=pink>
<td><h4>Pno</h4></td>
<td><h4>Name</h4></td>
<td><h4>Business</h4></td>
<td><h4>Rating</h4></td>

</tr>



<%
class Provider 
{
	int id;
	String name;
	String service;
	int rating;
	Provider()
	{		rating=0;
			id=0;
	}
}
class RatingComparator implements Comparator<Provider>
{
	public int compare(Provider p1,Provider p2)
	{
		if(p1.rating<p2.rating)
		{
			return 1;
		}
		else if(p1.rating>p2.rating)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
}
try{
ResultSet rs=null;
Connection con=DB.conc();
Statement stmt=con.createStatement();
String qry = "select pno,name,business,rating from provdetails";
rs = stmt.executeQuery(qry);
RatingComparator c=new RatingComparator();
PriorityQueue<Provider> p=new PriorityQueue<Provider>(2,c);
while(rs.next())
{
	Provider pro=new Provider();
	
	
	pro.id=rs.getInt(1);
	pro.name=rs.getString(2);
	pro.service=rs.getString(3);
	pro.rating=rs.getInt(4);
	p.add(pro);
}
Provider p1=null;
while(!p.isEmpty())
{
	p1=new Provider();
	p1=p.remove();
	System.out.println(p1.id+"\t\t"+p1.name+"\t"+p1.service+"\t\t"+p1.rating);
	
%>

<tr bgcolor=pink>

<td><h4><%=p1.id%></h4></td>

<td><h4><%=p1.name%></h4></td>

<td><h4><%=p1.service%></h4></td>

<td><h4><%=p1.rating%></h4></td>

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
 
  
  <p><h4>Enter pno for the provider selection</h4></p>
	
	<form name="frmQ" action="displayprovidercheck.jsp">
		<input type="text" name="pno">
		<button type="submit"><h5>Select provider number</h5></button>

	</form>
</center>
</body>
</html>
