// Filename: CInstrument.java
// Description: Class to make an instrument
// Author: Marcus Blea
// Date Modified: 11/25/2022

import java.awt.*;

public abstract class CInstrument {
    // Member variables
    protected CTuneNote center;
    protected double rotation;
    protected CColor color;

    // Constructors
    public CInstrument() {
        center = new CTuneNote(); 
        color = new CColor();
        rotation = 0.0;
        System.out.println("Instrument Created!");
    }

    // Accessor functions
    public void setLocation(CTuneNote p) {
        this.center = p;
    }

    public void setLocation(double x, double y) {
        this.center.x(x);
        this.center.y(y);
    }

    public void setColor(CColor c) {
        this.color = c;
    }

    public void setColor(int r, int g, int b) {
            this.color.set(r, g, b);
    }

    // Member Functions
    public abstract double calcSize();
    public abstract boolean company(Graphics2D ga);
}