import java.awt.*;
import java.awt.event.*;

class RevNumber extends Frame implements ActionListener, WindowListener {
    Label l1, l2;
    TextField t1, t2;
    Button b1;

    RevNumber() {
        setLayout(new FlowLayout());

        l1 = new Label("Enter Number:");
        t1 = new TextField(10);
        b1 = new Button("Reverse");
        l2 = new Label("Result:");
        t2 = new TextField(20);
        t2.setEditable(false);

        add(l1); add(t1);
        add(b1);
        add(l2); add(t2);

        b1.addActionListener(this);

        setSize(300,200);
        setVisible(true);
        addWindowListener(this);
    }

    public void actionPerformed(ActionEvent e) {
        int n = Integer.parseInt(t1.getText());
        int rev = 0;
        while(n > 0) {
            rev = rev*10 + n%10;
            n /= 10;
        }
        t2.setText("" + rev);
    }

    public void windowClosing(WindowEvent e){ System.exit(0); }
    public void windowActivated(WindowEvent e) {}
    public void windowClosed(WindowEvent e) {}
    public void windowDeactivated(WindowEvent e) {}
    public void windowDeiconified(WindowEvent e) {}
    public void windowIconified(WindowEvent e) {}
    public void windowOpened(WindowEvent e) {}

    public static void main(String[] args) {
        new RevNumber();
    }
}
