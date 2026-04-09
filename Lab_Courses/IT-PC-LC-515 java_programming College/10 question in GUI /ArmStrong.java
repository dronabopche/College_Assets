import java.awt.*;
import java.awt.event.*;

class ArmstrongNumber extends Frame implements ActionListener, WindowListener {
    Label l1, l2;
    TextField t1, t2;
    Button b1;

    ArmstrongNumber() {
        setLayout(new FlowLayout());

        l1 = new Label("Enter Number:");
        t1 = new TextField(10);
        b1 = new Button("Check Armstrong");
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
        int n = Integer.parseInt(t1.getText());
        int temp = n, sum = 0, d, digits = String.valueOf(n).length();
        while(temp > 0) {
            d = temp % 10;
            sum += Math.pow(d, digits);
            temp /= 10;
        }
        if(sum == n) t2.setText("Armstrong Number");
        else t2.setText("Not Armstrong");
    }

    public void windowClosing(WindowEvent e){ System.exit(0); }
    public void windowActivated(WindowEvent e) {}
    public void windowClosed(WindowEvent e) {}
    public void windowDeactivated(WindowEvent e) {}
    public void windowDeiconified(WindowEvent e) {}
    public void windowIconified(WindowEvent e) {}
    public void windowOpened(WindowEvent e) {}

    public static void main(String[] args) {
        new ArmstrongNumber();
    }
}
