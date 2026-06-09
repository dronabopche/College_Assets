<%@ page import="java.sql.*" %>
<%@ page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <title>Display All Records</title>
</head>
<body>
    <h2>All Phone Directory Records</h2>
    <table border="1" cellpadding="10">
        <tr>
            <th>Name</th>
            <th>Phone Number</th>
        </tr>
        <%
            Connection conn = null;
            Statement stmt = null;
            ResultSet rs = null;
            try {
                Class.forName("oracle.jdbc.driver.OracleDriver");
                conn = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE", "system", "manager");
                stmt = conn.createStatement();
                
                
                rs = stmt.executeQuery("SELECT * FROM phone_dir1");

                while(rs.next()){
        %>
                    <tr>
                        <td><%= rs.getString("NAME") %></td>
                        <td><%= rs.getString("PHONE_NUMBER") %></td>
                    </tr>
        <%
                }
            } catch(Exception e) {
                out.println("Error: " + e.getMessage());
            } finally {
                if(rs != null) rs.close();
                if(stmt != null) stmt.close();
                if(conn != null) conn.close();
            }
        %>
    </table>
    <br><a href="index.html">Back to Home</a>
</body>
</html>