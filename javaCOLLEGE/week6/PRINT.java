import java.io.*;

public class PRINT
{
    // scanf() method using BufferedReader
    static String scanf()
    {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try
        {
            return reader.readLine();
        }
        catch(Exception e)
        {
            e.printStackTrace();
            return "";
        }
    }
    
    // print method
    static void print(String message)
    {
        System.out.print(message);
    }
    
    // println method  
    static void println(String message)
    {
        System.out.println(message);
    }
    
    // TryCatchBlock as method
    static void TryCatchBlock()
    {
        try
        {
            // Your code here
            println("Inside try block");
            String input = scanf();
            println("You entered: " + input);
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) 
    {
        // Simple usage
        print("Enter your name: ");
        String name = scanf();
        println("Hello, " + name);
        
        // Using TryCatchBlock
        TryCatchBlock();
    }
}