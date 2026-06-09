<%@ page import="java.sql.*" %>
<%@ page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <title>Delete Record</title>
</head>
<body>
    <h2>Delete a Record</h2>
    <form method="post" action="delete.jsp">
        Enter Name to Delete: <input type="text" name="deleteName" required>
        <input type="submit" value="Delete">
    </form>
    <br>

    <%
        String deleteName = request.getParameter("deleteName");
        if(deleteName != null && !deleteName.trim().isEmpty()){
            Connection conn = null;
            PreparedStatement pstmt = null;
            try {
                Class.forName("oracle.jdbc.driver.OracleDriver");
                conn = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE", "system", "manager");
                
                String sql = "DELETE FROM phone_dir1 WHERE NAME = ?";
                pstmt = conn.prepareStatement(sql);
                pstmt.setString(1, deleteName);
                
                int rowsAffected = pstmt.executeUpdate();
                if(rowsAffected > 0){
                    out.println("<h3 style='color:green;'>Record for " + deleteName + " deleted successfully.</h3>");
                } else {
                    out.println("<h3 style='color:red;'>Record not found.</h3>");
                }
            } catch(Exception e) {
                out.println("Error: " + e.getMessage());
            } finally {
                if(pstmt != null) pstmt.close();
                if(conn != null) conn.close();
            }
        }
    %>
    <br><a href="index.html">Back to Home</a>
</body>
</html>