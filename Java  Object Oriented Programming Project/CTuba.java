// Filename: CTuba.java
// Description: Class to make a Tuba
// Author: Marcus Blea
// Date Modified: 11/25/2022

import java.awt.*;

public class CTuba extends CLowBrass {
    // Member variables
    public double width;
    public double height;

    // Constructors
    public CTuba() {
        setModel (1.0);
        System.out.println("Tuba made");
    }

    public CTuba(double rad) {
        setModel(rad);
        System.out.println("Tuba Made.");
    }

    // Accessor functions
    public void setModel(double m, double M) {
        
    }

    public void setModel(double r) {
       
    }

    // Member Functions
    public double calcSize() {
        return super.calcSize();
    }

    public boolean company(Graphics2D ga) {
        return super.company(ga);
    }
}