// Filename: CClarinet.java
// Description: Class to make a clarinet
// Author: Marcus Blea
// Date Modified: 11/25/2022

import java.awt.*;

public class CClarinet extends CWoodWind {
    // Member variables
    public double width;
    public double height;

    // Constructors
    public CClarinet() {
        setModel (1.0);
        System.out.println("Clarinet made");
    }

    public CClarinet(double rad) {
        setModel(rad);
        System.out.println("Clarinet Created.");
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