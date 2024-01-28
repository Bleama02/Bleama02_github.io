// Filename: InstrumentMaker.java
// Description: A class to allow instruments to be created
// Author: Marcus Blea
// Date Modified: 12/3/2022

import java.awt.*;

public class InstrumentMaker extends Frame {
    private static final long serialVersionUID = 1L;
    public Graphics2D ga; 
    public final int MAX_SHAPES = 10; 
    public final int MAX_WIDTH = 800; 
    public final int MAX_HEIGHT = 600; 

    private Rectangle bounds = new Rectangle(0, 0, 1, 1); 
    private CInstrument[] myInstument = new CInstrument[MAX_SHAPES];
    private int lastShapeIndex = 0;

    public InstrumentMaker() {
    }

    public void createInstrument() {
        
        myInstument[lastShapeIndex] = new CBrass();
        myInstument[lastShapeIndex].color.set(255, 255, 255);
        lastShapeIndex++;

        myInstument[lastShapeIndex] = new CLowBrass();
        myInstument[lastShapeIndex].color.set(122, 51, 0); 
        lastShapeIndex++;

        myInstument[lastShapeIndex] = new CTuba();
        myInstument[lastShapeIndex].color.set(135, 206, 235);
        lastShapeIndex++;

        myInstument[lastShapeIndex] = new CFrenchHorn();
        myInstument[lastShapeIndex].color.set(255, 255, 255);
        lastShapeIndex++;

        myInstument[lastShapeIndex] = new CWoodWind();
        myInstument[lastShapeIndex].color.set(0, 200, 25); 
        lastShapeIndex++;

        myInstument[lastShapeIndex] = new CClarinet();
        myInstument[lastShapeIndex].color.set(255, 255, 0);
        lastShapeIndex++;

        myInstument[lastShapeIndex] = new CSaxophone();
        myInstument[lastShapeIndex].color.set(255, 255, 0);
        lastShapeIndex++;

        myInstument[lastShapeIndex] = new CPercussion();
        myInstument[lastShapeIndex].color.set(0, 200, 25); 
        lastShapeIndex++;

        myInstument[lastShapeIndex] = new CDrum();
        myInstument[lastShapeIndex].color.set(0, 200, 25); 
        lastShapeIndex++;

        myInstument[lastShapeIndex] = new CSnareDrum();
        myInstument[lastShapeIndex].color.set(0, 200, 25); 
        lastShapeIndex++;
    }

    public void updateInstrument() {
        int cur = 0;

        ((CBrass)myInstument[cur]).setModel(cur, cur);
        myInstument[cur].setLocation((bounds.width/2.05), 360.0);
        cur++;

        ((CLowBrass)myInstument[cur]).setModel(cur, cur);
        myInstument[cur].setLocation((bounds.width/2.05), 360.0);
        cur++;

        ((CTuba)myInstument[cur]).setModel(cur, cur);
        myInstument[cur].setLocation((bounds.width/2.0), 200.0);
        cur++;

        ((CFrenchHorn)myInstument[cur]).setModel(cur, cur);
        myInstument[cur].setLocation((bounds.width/3.3) + 169.0, 200.0);
        cur++;

        ((CWoodWind)myInstument[cur]).setModel(cur, cur);
        myInstument[cur].setLocation((bounds.width/2.05), 360.0);
        cur++;

        ((CClarinet)myInstument[cur]).setModel(cur, cur);
        myInstument[cur].setLocation((bounds.width/2.0) + 160, 80.0);
        cur++;

        ((CSaxophone)myInstument[cur]).setModel(cur, cur);
        myInstument[cur].setLocation((bounds.width/2.0) + 160, 80.0);
        cur++;
        
        ((CPercussion)myInstument[cur]).setModel(cur, cur);
        myInstument[cur].setLocation((bounds.width/2.0) - 200.0, 395.0);
        cur++;

        ((CDrum)myInstument[cur]).setModel(cur, cur);
        myInstument[cur].setLocation((bounds.width/2.0) - 200.0, 395.0);
        cur++;

        ((CSnareDrum)myInstument[cur]).setModel(cur, cur);
        myInstument[cur].setLocation((bounds.width/2.0) - 200.0, 395.0);
        cur++;
    }

}