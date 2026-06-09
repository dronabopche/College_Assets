<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Processing Cookie...</title>
    </head>
    <body>
        <%
            // Retrieve the username from the request
            String user = request.getParameter("username");
            
            if (user != null && !user.trim().isEmpty()) {
                // Create a cookie (Key: "user", Value: user)
                Cookie userCookie = new Cookie("user", user);
                
                // Set cookie expiry time (e.g., 24 hours)
                userCookie.setMaxAge(60 * 60 * 24); 
                
                // Add the cookie to the response header
                response.addCookie(userCookie);
                
                out.println("<h3>Login Successful! Cookie has been stored for: " + user + "</h3>");
            } else {
                out.println("<h3>Error: Username cannot be empty.</h3>");
            }
        %>
        <br/>
        <a href="index.html">Go Back to Login Page</a>
    </body>
</html>