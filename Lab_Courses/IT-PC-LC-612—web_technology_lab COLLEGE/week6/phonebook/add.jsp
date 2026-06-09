<%@ page import="java.sql.*" %>
<%@ page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <title>Add New Record</title>
</head>
<body>
    <h2>Add to Directory</h2>
    <form method="post" action="add.jsp">
        Name: <input type="text" name="newName" required><br><br>
        Phone: <input type="text" name="newPhone" required><br><br>
        <input type="submit" value="Add Record">
    </form>
    <br>

    <%
        String newName = request.getParameter("newName");
        String newPhone = request.getParameter("newPhone");
        
        if(newName != null && newPhone != null){
            Connection conn = null;
            PreparedStatement pstmt = null;
            try {
                Class.forName("oracle.jdbc.driver.OracleDriver");
                conn = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE", "system", "manager");
               
                String sql = "INSERT INTO phone_dir1 (NAME, PHONE_NUMBER) VALUES (?, ?)";
                pstmt = conn.prepareStatement(sql);
                pstmt.setString(1, newName);
                pstmt.setString(2, newPhone);
                
                int rowsAffected = pstmt.executeUpdate();
                if(rowsAffected > 0){
                    out.println("<h3 style='color:green;'>Record added successfully!</h3>");
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