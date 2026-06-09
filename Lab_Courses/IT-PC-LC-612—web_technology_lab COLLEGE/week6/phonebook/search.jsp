<%@ page import="java.sql.*" %>
<%@ page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <title>Search Phone Number</title>
</head>
<body>
    <h2>Search Directory</h2>
    <form method="post" action="search.jsp">
        Enter Name: <input type="text" name="searchName" required>
        <input type="submit" value="Search">
    </form>
    <br>
    
    <%
        String searchName = request.getParameter("searchName");
        if(searchName != null && !searchName.trim().isEmpty()){
            Connection conn = null;
            PreparedStatement pstmt = null;
            ResultSet rs = null;
            try {
                Class.forName("oracle.jdbc.driver.OracleDriver");
                conn = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE", "system", "manager");
                
               
                String sql = "SELECT PHONE_NUMBER FROM phone_dir1 WHERE NAME = ?";
                pstmt = conn.prepareStatement(sql);
                pstmt.setString(1, searchName);
                rs = pstmt.executeQuery();
                
                if(rs.next()){
                    out.println("<h3>Phone Number for " + searchName + " is: " + rs.getString("PHONE_NUMBER") + "</h3>");
                } else {
                    out.println("<h3>No record found for " + searchName + "</h3>");
                }
            } catch(Exception e) {
                out.println("Error: " + e.getMessage());
            } finally {
                if(rs != null) rs.close();
                if(pstmt != null) pstmt.close();
                if(conn != null) conn.close();
            }
        }
    %>
    <br><a href="index.html">Back to Home</a>
</body>
</html>