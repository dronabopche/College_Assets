import java.awt.*;
import java.awt.event.*;

class DivCheck extends Frame implements ActionListener, WindowListener {
    Label l1, l2, l3;
    TextField t1, t2, t3;
    Button b1;

    DivCheck() {
        setLayout(new FlowLayout());

        l1 = new Label("Enter Number:");
        t1 = new TextField(10);
        l2 = new Label("Enter Divisor:");
        t2 = new TextField(10);
        b1 = new Button("Check Divisibility");
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
        int num = Integer.parseInt(t1.getText());
        int div = Integer.parseInt(t2.getText());
        if(div == 0) t3.setText("Divisor cannot be 0");
        else if(num % div == 0) t3.setText(num + " is divisible by " + div);
        else t3.setText(num + " is not divisible by " + div);
    }

    public void windowClosing(WindowEvent e){ System.exit(0); }
    public void windowActivated(WindowEvent e) {}
    public void windowClosed(WindowEvent e) {}
    public void windowDeactivated(WindowEvent e) {}
    public void windowDeiconified(WindowEvent e) {}
    public void windowIconified(WindowEvent e) {}
    public void windowOpened(WindowEvent e) {}

    public static void main(String[] args) {
        new DivCheck();
    }
}
