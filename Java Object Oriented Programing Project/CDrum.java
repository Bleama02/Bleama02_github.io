// Filename: CDrum.java
// Description: Class to make a drum
// Author: Marcus Blea
// Date Modified: 11/25/2022

import java.awt.*;
import java.awt.geom.*; 

public class CDrum extends CPercussion {
    // Member variables
    protected double width;
    protected double height;
    
    // Constructors
    public CDrum() {
        setModel(1.0, 2.0);
        System.out.println("Drum made.");
    }
    
    public CDrum(double m, double M) {
        setModel(m, M); 
        System.out.println("Drum made");
    }

    // Accessor functions
    public void setModel(double m, double M) {
        
    }

    // Member Functions
    public double calcSize() {
        return super.calcSize();
    }

    public boolean company(Graphics2D ga) {
        return super.company(ga);
    }
}