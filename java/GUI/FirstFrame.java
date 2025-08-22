package GUI;

import java.awt.Color;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.swing.JFrame;

public class FirstFrame extends JFrame {

    public static void main(String[] args) {
        FirstFrame fr = new FirstFrame("Hello");
        fr.setSize(240, 240);
        fr.getContentPane().setBackground(Color.white);
        fr.setVisible(true);
        fr.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        SecondFrame fs = new SecondFrame("Second Frame");
        fs.setSize(240, 240);
        fs.getContentPane().setBackground(Color.white);
        fs.setVisible(true);
        fs.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        ThirdFrame ft = new ThirdFrame("Third Frame");
        ft.setSize(240, 240);
        ft.getContentPane().setBackground(Color.white);
        ft.setVisible(true);
        ft.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }

    public FirstFrame(String str) {
        super(str);
    }
}

class SecondFrame extends JFrame {
    public SecondFrame(String str) {
        super(str);
    }
}

class ThirdFrame extends JFrame {
    public ThirdFrame(String str) {
        super(str);
    }
}