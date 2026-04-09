import java.awt.*;
import java.awt.event.*;

class SimpleCalculator extends Frame implements ActionListener, WindowListener {
    Label l1, l2, l3;
    TextField t1, t2, t3;
    Button add, sub, mul, div;

    SimpleCalculator() {
        setLayout(new FlowLayout());

        l1 = new Label("First Number:");
        t1 = new TextField(10);
        l2 = new Label("Second Number:");
        t2 = new TextField(10);
        l3 = new Label("Result:");
        t3 = new TextField(15);
        t3.setEditable(false);

        add = new Button("Add");
        sub = new Button("Sub");
        mul = new Button("Mul");
        div = new Button("Div");

        add(l1); add(t1);
        add(l2); add(t2);
        add(l3); add(t3);
        add(add); add(sub); add(mul); add(div);

        add.addActionListener(this);
        sub.addActionListener(this);
        mul.addActionListener(this);
        div.addActionListener(this);

        setSize(400,200);
        setVisible(true);
        addWindowListener(this);
    }

    public void actionPerformed(ActionEvent e) {
        double a = Double.parseDouble(t1.getText());
        double b = Double.parseDouble(t2.getText());
        if(e.getSource() == add) t3.setText("" + (a+b));
        else if(e.getSource() == sub) t3.setText("" + (a-b));
        else if(e.getSource() == mul) t3.setText("" + (a*b));
        else if(e.getSource() == div) {
            if(b != 0) t3.setText("" + (a/b));
            else t3.setText("Divide by 0 Error");
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
        new SimpleCalculator();
    }
}
