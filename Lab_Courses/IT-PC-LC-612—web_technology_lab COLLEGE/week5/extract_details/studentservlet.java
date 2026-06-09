package com.myapp; // Ensure this matches the package you created

import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.ServletException; // Use javax.servlet.* if on an older Java EE version
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

@WebServlet(name = "DisplayServlet", urlPatterns = {"/DisplayServlet"})
public class DisplayServlet extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
        // 1. Set the response content type
        response.setContentType("text/html;charset=UTF-8");
        
        // 2. Extract data from the HTML form using the 'name' attributes
        String name = request.getParameter("name");
        String roll = request.getParameter("roll");
        String gender = request.getParameter("gender");
        
        // Use getParameterValues for checkboxes, since multiple can be selected
        String[] skills = request.getParameterValues("skills");

        // 3. Generate the HTML response to display the data
        try (PrintWriter out = response.getWriter()) {
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Submitted Information</title>");            
            out.println("</head>");
            out.println("<body>");
            out.println("<h2>Here is the information you submitted:</h2>");
            
            out.println("<p><strong>Name:</strong> " + name + "</p>");
            out.println("<p><strong>Roll Number:</strong> " + roll + "</p>");
            out.println("<p><strong>Gender:</strong> " + gender + "</p>");
            
            // Check if any skills were selected, then loop through them
            out.println("<p><strong>Programming Skills:</strong> ");
            if (skills != null && skills.length > 0) {
                for (int i = 0; i < skills.length; i++) {
                    out.print(skills[i]);
                    if (i < skills.length - 1) {
                        out.print(", "); // Add a comma between skills
                    }
                }
            } else {
                out.print("None selected");
            }
            out.println("</p>");
            
            out.println("<br><a href='index.html'>Go Back</a>");
            out.println("</body>");
            out.println("</html>");
        }
    }
    
    // Allow GET requests to route to POST just in case
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        doPost(request, response);
    }
}