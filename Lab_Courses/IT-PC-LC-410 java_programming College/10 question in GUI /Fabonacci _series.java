import java.awt.*;
import java.awt.event.*;

class FibonacciSeries extends Frame implements ActionListener, WindowListener {
    Label l1, l2;
    TextField t1, t2;
    Button b1;

    FibonacciSeries() {
        setLayout(new FlowLayout());

        l1 = new Label("Enter Number of Terms:");
        t1 = new TextField(10);
        b1 = new Button("Generate");
        l2 = new Label("Result:");
        t2 = new TextField(30);
        t2.setEditable(false);

        add(l1); add(t1);
        add(b1);
        add(l2); add(t2);

        b1.addActionListener(this);

        setSize(400,200);
        setVisible(true);
        addWindowListener(this);
    }

    public void actionPerformed(ActionEvent e) {
        int n = Integer.parseInt(t1.getText());
        int a = 0, b = 1, c;
        String result = a + " " + b;
        for(int i=2; i<n; i++) {
            c = a+b;
            result += " " + c;
            a = b;
            b = c;
        }
        t2.setText(result);
    }

    public void windowClosing(WindowEvent e){ System.exit(0); }
    public void windowActivated(WindowEvent e) {}
    public void windowClosed(WindowEvent e) {}
    public void windowDeactivated(WindowEvent e) {}
    public void windowDeiconified(WindowEvent e) {}
    public void windowIconified(WindowEvent e) {}
    public void windowOpened(WindowEvent e) {}

    public static void main(String[] args) {
        new FibonacciSeries();
    }
}

