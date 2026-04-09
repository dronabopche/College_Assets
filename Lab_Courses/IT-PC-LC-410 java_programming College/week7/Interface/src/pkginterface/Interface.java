/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkginterface;

/**
 *
 * @author 2025
 */
public class Interface {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Car c = new Car();
        Bike b = new Bike();
        
        c.moveForward();
        c.moveBackward();
        c.turnLeft();
        c.turnRight();
        
        b.moveBackward();
        b.moveForward();
        b.turnLeft();
        b.turnRight();
    }
    
}
