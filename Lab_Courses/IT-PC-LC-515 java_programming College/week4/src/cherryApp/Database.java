/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cherryapp;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

/**
 *
 * @author EXAM 2025
 */
public class Database {
    Connection con = null;
    Statement stmt;
    ResultSet rs = null;
    
    Database()
    {
        try
        {
            Class.forName("oracle.jdbc.OracleDriver");
            con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE" ,"system","manager");
            stmt = con.createStatement();
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }
    
}
