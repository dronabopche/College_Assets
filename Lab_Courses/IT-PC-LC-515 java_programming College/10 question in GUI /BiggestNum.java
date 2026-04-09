import java.awt.*;
import java.awt.event.*;

class LargestOfTwo extends Frame implements ActionListener, WindowListener {
    Label l1, l2, l3;
    TextField t1, t2, t3;
    Button b1;

    LargestOfTwo() {
        setLayout(new FlowLayout());

        l1 = new Label("Enter First Number:");
        t1 = new TextField(10);
        l2 = new Label("Enter Second Number:");
        t2 = new TextField(10);
        b1 = new Button("Find Largest");
        l3 = new Label("Result:");
        t3 = new TextField(15);
        t3.setEditable(false);

        add(l1); add(t1);
        add(l2); add(t2);
        add(b1);
        add(l3); add(t3);

        b1.addActionListener(this);

        setSize(350,200);
        setVisible(true);
        addWindowListener(this);
    }

    public void actionPerformed(ActionEvent e) {
        int a = Integer.parseInt(t1.getText());
        int b = Integer.parseInt(t2.getText());
        if(a > b)
            t3.setText("Largest: " + a);
        else if(b > a)
            t3.setText("Largest: " + b);
        else
            t3.setText("Both are Equal");
    }

    public void windowClosing(WindowEvent e){ System.exit(0); }
    public void windowActivated(WindowEvent e) {}
    public void windowClosed(WindowEvent e) {}
    public void windowDeactivated(WindowEvent e) {}
    public void windowDeiconified(WindowEvent e) {}
    public void windowIconified(WindowEvent e) {}
    public void windowOpened(WindowEvent e) {}

    public static void main(String[] args) {
        new LargestOfTwo();
    }
}
