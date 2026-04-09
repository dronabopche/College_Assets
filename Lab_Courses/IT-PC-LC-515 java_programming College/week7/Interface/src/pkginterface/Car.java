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
public class Car implements FC {
    public void moveForward()
    {
        System.out.println("\nCar is Accelerating...");
    }
    public void moveBackward()
    {
        System.out.println("\nCar is Decelerating...");
    }
    public void turnRight()
    {
        System.out.println("\nTurning Right ...");
    }
    public void turnLeft()
    {
        System.out.println("\nTurning Left ...");
    }
}
