<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Display Cookie</title>
    </head>
    <body>
        <h2>Stored Cookie Information</h2>
        <%
            // Retrieve all cookies from the request
            Cookie[] cookies = request.getCookies();
            String usernameStr = null;

            if (cookies != null) {
                // Loop through cookies to find our "user" cookie
                for (Cookie c : cookies) {
                    if (c.getName().equals("user")) {
                        usernameStr = c.getValue();
                        break;
                    }
                }
            }

            // Display the result based on whether the cookie was found
            if (usernameStr != null) {
                out.println("<h3>Current Username stored in Cookie: <span style='color:blue;'>" + usernameStr + "</span></h3>");
            } else {
                out.println("<h3>No active cookie found. Please log in first.</h3>");
            }
        %>
        <br/>
        <a href="index.html">Go Back to Login Page</a>
    </body>
</html>