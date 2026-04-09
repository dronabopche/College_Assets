import java.awt.*;
import java.awt.event.*;

class PalindromeCheck extends Frame implements ActionListener, WindowListener {
    Label l1, l2;
    TextField t1, t2;
    Button b1;

    PalindromeCheck() {
        setLayout(new FlowLayout());

        l1 = new Label("Enter String/Number:");
        t1 = new TextField(15);
        b1 = new Button("Check Palindrome");
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
 
    public void actionPerformed(ActionEvent e) {
        String str = t1.getText();
        String rev = new StringBuilder(str).reverse().toString();
        if(str.equals(rev))
            t2.setText("Palindrome");
        else
            t2.setText("Not Palindrome");
    }

    public void windowClosing(WindowEvent e){ System.exit(0); }
    public void windowActivated(WindowEvent e) {}
    public void windowClosed(WindowEvent e) {}
    public void windowDeactivated(WindowEvent e) {}
    public void windowDeiconified(WindowEvent e) {}
    public void windowIconified(WindowEvent e) {}
    public void windowOpened(WindowEvent e) {}

    public static void main(String[] args) {
        new PalindromeCheck();
    }
}
