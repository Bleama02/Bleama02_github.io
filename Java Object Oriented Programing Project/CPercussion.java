// Filename: CPercussinon.java
// Description: Class to make percussion instruments 
// Author: Marcus Blea
// Date Modified: 11/25/2022

import java.awt.*;
import java.awt.geom.*; 

public class CPercussion extends CInstrument {
    // Member variables
    protected double width;
    protected double height;
    
    // Constructors
    public CPercussion() {
        setModel(1.0, 2.0);
        System.out.println("Percussion Instrument Created");
    }
    
    public CPercussion(double m, double M) {
        setModel(m, M); 
        System.out.println("Percussion Instrument Created");
    }

    // Accessor functions
    public void setModel(double m, double M) {
        m = 1.0;
        M = 2.0;
    }

    // Member Functions
    public double calcSize() {
        return width * height;
    }

    public boolean company(Graphics2D ga) {
        System.out.println("Company Verified");
        return true;
    }
}