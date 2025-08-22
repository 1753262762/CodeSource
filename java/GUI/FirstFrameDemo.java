package GUI;

import java.awt.Color;
import java.awt.Frame;
import java.awt.Panel;

public class FirstFrameDemo {
    public static void main(String[] args) {
        Frame fr = new Frame("Hello");
        fr.setSize(240, 180);
        fr.setBackground(Color.green);
        fr.setLayout(null);
        Panel pan = new Panel();
        pan.setSize(100, 100);
        pan.setBackground(Color.yellow);
        fr.add(pan);
        fr.setVisible(true);
    }
}
