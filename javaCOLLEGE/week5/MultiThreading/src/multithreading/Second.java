/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package multithreading;

/**
 *
 * @author 2025
 */
public class Second extends Thread {
    
    int val1;
    Second(int x)
    {
        val1=x;
        
    }
    
    public void run()
    {
        System.out.println("Square is : "+ val1*val1);
    }
    
}
