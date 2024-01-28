// Filename: CFrenchHorn.java
// Description: Class to make FrenchHorn
// Author: Marcus Blea
// Date Modified: 11/25/2022

import java.awt.*;

public class CFrenchHorn extends CBrass {
    // Member variables
    public double width;
    public double height;

    // Constructors
    public CFrenchHorn() {
        setModel (1.0);
        System.out.println("French Horn made");
    }

    public CFrenchHorn(double rad) {
        setModel(rad);
        System.out.println("French Horn Created.");
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