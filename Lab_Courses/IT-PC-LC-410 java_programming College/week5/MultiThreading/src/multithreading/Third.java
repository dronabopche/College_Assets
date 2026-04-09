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
public class Third extends Thread{
    
    
    int val2;
    Third(int x)
    {
        val2=x;
        
    }
    
    public void run()
    {
        System.out.println("Cube is : "+ val2*val2*val2);
    }
    
}
