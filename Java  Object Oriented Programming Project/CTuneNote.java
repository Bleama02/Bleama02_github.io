// Filename: CTuneNote.java
// Description: Class to set the tunning note
// Author: Marcus Blea
// Date Modified: 11/25/2022

public class CTuneNote {
    // Member variables
    private double locationX;
    private double locationY;
    
    // Constructors
    public CTuneNote() {
        set(0.0, 0.0); 
        System.out.println("Concert pitch is Bb");
    }

    public CTuneNote(double x, double y) {
        set(x, y);
        System.out.println("Concert pitch is Eb");
    }

    // Accessor functions
    public void set(double x, double y) {locationX = x; locationY = y;}
    public void x(double x) {locationX = x;}
    public void y(double y) {locationY = y;}

    public double x() {return locationX;}
    public double y() {return locationY;}


    // Member Functions
    public double calcPitch(CTuneNote p2) {
        return Math.sqrt(Math.pow(this.x() - p2.x(), 2) + 
                        Math.pow(this.y() - p2.y(), 2)); 
    }

    public static double calcPitch(CTuneNote p1, CTuneNote p2) {
        return Math.sqrt(Math.pow(p1.x() - p2.x(), 2) + 
                        Math.pow(p1.y() - p2.y(), 2)); 
        
    }
}
