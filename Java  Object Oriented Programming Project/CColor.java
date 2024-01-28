// Filename: CColor.java
// Description: Class to encapsulate the properties of a Point
// Author: Marcus Blea
// Date Modified: 11/25/2022

public class CColor {
    final int MIN_VALUE = 0;
    final int MAX_VALUE = 255; 

    // Member variables
    private int colorR;
    private int colorG;
    private int colorB;

    // Constructors
    public CColor() {
        set (0, 0, 0); 
        System.out.println("Color Created.");
    }

    public CColor(int red, int green, int blue) {
        set(red, green, blue);
        System.out.println("Color Created.");
    }

    // Accessor functions
    public void set(int red, int green, int blue) { 
        this.r(red);
        this.g(green);
        this.b(blue);
    }

    public void r(int val) {
        if (val >= MIN_VALUE && val <= MAX_VALUE) colorR = val;
    }

    public void g(int val) {
        if (val >= MIN_VALUE && val <= MAX_VALUE) colorG = val;
    }

    public void b(int val) {
        if (val >= MIN_VALUE && val <= MAX_VALUE) colorB = val;
    }

    public int r() {return colorR;}
    public int g() {return colorG;}
    public int b() {return colorB;}

}
