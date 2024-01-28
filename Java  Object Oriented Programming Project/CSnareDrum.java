// Filename: CSnareDrum.java
// Description: Class to make a snare drum
// Author: Marcus Blea
// Date Modified: 11/25/2022

import java.awt.*;

public class CSnareDrum extends CDrum {
    // Member variables
    public double width;
    public double height;

    // Constructors
    public CSnareDrum() {
        setModel (1.0);
        System.out.println("Snare Drum made");
    }

    public CSnareDrum(double rad) {
        setModel(rad);
        System.out.println("Snare Drum Made.");
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