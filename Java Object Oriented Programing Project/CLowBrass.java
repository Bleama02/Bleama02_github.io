// Filename: ClowBrass.java
// Description: Class to make Low Brass instrument 
// Author: Marcus Blea
// Date Modified: 11/25/2022

import java.awt.*;
import java.awt.geom.*; 

public class CLowBrass extends CBrass {
    // Member variables
    protected double width;
    protected double height;
    
    // Constructors
    public CLowBrass() {
        setModel(1.0, 2.0);
        System.out.println("Low Brass Instrument made.");
    }
    
    public CLowBrass(double m, double M) {
        setModel(m, M); 
        System.out.println("Low Brass Instrument made");
    }

    // Accessor functions
    public void setModel(double m, double M) {
        
    }

    // Member Functions
    public double calcSize() {
        return  width * height;
    }

    public boolean company(Graphics2D ga) {
        return super.company(ga);
    }
}