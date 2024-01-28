// Filename: TP2.java
// Description: The main entry point for the shapes objects
// Author: Marcus Blea
// Date Modified: 11/25/2022

import java.awt.*;
import java.awt.event.*;

public class TP2 {
    public static void main(String args[]) {
        System.out.println("\nWelcome to Instruments Java!!!\n");
        InstrumentMaker dc = new InstrumentMaker();
        dc.createInstrument();
        

        dc.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                System.exit(0); 
            }
        });
    }
}
