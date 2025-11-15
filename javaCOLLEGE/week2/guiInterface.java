import java.awt.*;
import java.awt.event.*;

class Login extends Frame implements ActionListener, WindowListener {
    Label l1, l2, l3;
    TextField t1, t2, t3;
    Button b1;

    Login() {
        setLayout(new FlowLayout());

        l1 = new Label("Enter Username:");
        t1 = new TextField(15);

        l2 = new Label("Enter Password:");
        t2 = new TextField(15);
      

        b1 = new Button("Login");

        l3 = new Label("Result:");
        t3 = new TextField(20);
        t3.setEditable(false);

        add(l1); add(t1);
        add(l2); add(t2);
        add(b1);
        add(l3); add(t3);

        b1.addActionListener(this);

        setSize(400,200);
        setVisible(true);
        addWindowListener(this);
    }

    public void actionPerformed(ActionEvent e) {
        String user = t1.getText();
        String pass = t2.getText();

        if(user.equals("admin") && pass.equals("123")) {
            t3.setText("Login Successful!");
        } else {
            t3.setText("Invalid Credentials");
        }
    }

    public void windowClosing(WindowEvent e){ System.exit(0); }
    public void windowActivated(WindowEvent e) {}
    public void windowClosed(WindowEvent e) {}
    public void windowDeactivated(WindowEvent e) {}
    public void windowDeiconified(WindowEvent e) {}
    public void windowIconified(WindowEvent e) {}
    public void windowOpened(WindowEvent e) {}

    public static void main(String[] args) {
        new Login();
    }
}
