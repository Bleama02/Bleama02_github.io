// Filename: CWoodWind.java
// Description: Class to make a woodwind instrument
// Author: Marcus Blea
// Date Modified: 11/25/2022

import java.awt.*;
import java.awt.geom.*; 

public class CWoodWind extends CInstrument {
    // Member variables
    protected double width;
    protected double height;
    
    // Constructors
    public CWoodWind() {
        setModel(1.0, 2.0);
        System.out.println("WoodWind Created");
    }
    
    public CWoodWind(double m, double M) {
        setModel(m, M); 
        System.out.println("WoodWind Created");
    }

    // Accessor functions
    public void setModel(double m, double M) {
        m = 1.0;
        M = 2.0;
    }

    // Member Functions
    public double calcSize() {
        return  width * height;
    }

    public boolean company(Graphics2D ga) {
        System.out.println("Company Verified");
        return true;
    }
}