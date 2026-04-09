/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package multithreading;
import java.util.Random;


/**
 *
 * @author 2025
 */
public class First extends Thread {
    Thread t2;
    int i;
    public void run()
    {
        for(;;)
        {
            Random r = new Random();
            i = r.nextInt(100)+1;
            System.out.println(i);        
            t2 = new Second(i);
            Thread t3 = new Third(i);
            
            try {
                Thread.sleep(0);
                
                if (i%2==0)
                {
                    t2.start();
                }
                else
                {
                    t3.start();
                }
            }
            catch (Exception e)
            {
                e.printStackTrace();
            }
        }    
    }
    
}
