import java.awt.*;
import java.awt.event.*;

class AddTwoNumbers extends Frame implements ActionListener, WindowListener {
    Label l1, l2, l3;
    TextField t1, t2, t3;
    Button b1;

    AddTwoNumbers() {
        setLayout(new FlowLayout());

        l1 = new Label("Enter First Number:");
        l2 = new Label("Enter Second Number:");
        l3 = new Label("Result:");

        t1 = new TextField(10);
        t2 = new TextField(10);
        t3 = new TextField(10);
        t3.setEditable(false);

        b1 = new Button("Add");

        add(l1); add(t1);
        add(l2); add(t2);
        add(l3); add(t3);
        add(b1);

        b1.addActionListener(this);

        setSize(300,200);
        setVisible(true);
        addWindowListener(this);
    }

    public void actionPerformed(ActionEvent e) {
        int a = Integer.parseInt(t1.getText());
        int b = Integer.parseInt(t2.getText());
        t3.setText("" + (a+b));
    }

    public void windowClosing(WindowEvent e){ System.exit(0); }
    public void windowActivated(WindowEvent e) {}
    public void windowClosed(WindowEvent e) {}
    public void windowDeactivated(WindowEvent e) {}
    public void windowDeiconified(WindowEvent e) {}
    public void windowIconified(WindowEvent e) {}
    public void windowOpened(WindowEvent e) {}

    public static void main(String[] args) {
        new AddTwoNumbers();
    }
}

