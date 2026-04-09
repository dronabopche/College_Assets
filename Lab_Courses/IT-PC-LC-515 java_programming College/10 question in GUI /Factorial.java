import java.awt.*;
import java.awt.event.*;

class FactorialRecursion extends Frame implements ActionListener, WindowListener {
    Label l1, l2;
    TextField t1, t2;
    Button b1;

    FactorialRecursion() {
        setLayout(new FlowLayout());

        l1 = new Label("Enter Number:");
        t1 = new TextField(10);
        b1 = new Button("Find Factorial");
        l2 = new Label("Result:");
        t2 = new TextField(20);
        t2.setEditable(false);

        add(l1); add(t1);
        add(b1);
        add(l2); add(t2);

        b1.addActionListener(this);

        setSize(350,200);
        setVisible(true);
        addWindowListener(this);
    }

    int fact(int n) { //making function for recursion 
        if(n == 0 || n == 1) return 1;
        return n * fact(n-1);
    }

    public void actionPerformed(ActionEvent e) {
        int n = Integer.parseInt(t1.getText());
        t2.setText("" + fact(n));
    }

    public void windowClosing(WindowEvent e){ System.exit(0); }
    public void windowActivated(WindowEvent e) {}
    public void windowClosed(WindowEvent e) {}
    public void windowDeactivated(WindowEvent e) {}
    public void windowDeiconified(WindowEvent e) {}
    public void windowIconified(WindowEvent e) {}
    public void windowOpened(WindowEvent e) {}

    public static void main(String[] args) {
        new FactorialRecursion();
    }
}
