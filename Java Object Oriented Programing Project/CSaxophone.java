// Filename: CSaxophone.java
// Description: Class to make the most beautiful instrument. The Saxophone!
// Author: Marcus Blea
// Date Modified: 11/25/2022

import java.awt.*;

public class CSaxophone extends CWoodWind {
    // Member variables
    public double width;
    public double height;

    // Constructors
    public CSaxophone() {
        setModel (1.0);
        System.out.println("Saxophone Made");
    }

    public CSaxophone(double rad) {
        setModel(rad);
        System.out.println("Saxophone made.");
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