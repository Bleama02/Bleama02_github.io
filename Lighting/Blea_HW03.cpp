//Filename: Blea_HW03.cpp
//Description: Draw a lot more shapes with basic lighting 
//Author: Marcus Blea
//September 29th 2022

#include <iostream>
using namespace std;

#if defined __APPLE__ 
    #include <GLUT/glut.h>
#elif defined _WIN32 || defined _WIN64
    #include <GL/glut.h>
#elif __linux__
    #include <GL/freeglut.h>
#endif

//Function prototypes..
void display(void);
void enableLights();
void resetScene();
void reshape(GLsizei width, GLsizei height);
void drawCube();
void drawPyramid();

//global variables

bool blLightsAreOn;

int main(int argc, char** argv)
{
    //Initialization functions 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);    //Use double buffer mode
    glutInitWindowSize(640, 640);       //Set the window's initial width and height
    glutInitWindowPosition(50,50); // Where the position of the window is

    glutCreateWindow("Draw Lots of GLUT Shapes");

    //callback functions...
    
    glutDisplayFunc(&display);
    glutReshapeFunc(&reshape);

    resetScene();
    glutMainLoop();
    return EXIT_SUCCESS;
}

void display(void)
{
    cout << "Drawing" << endl;

    #if defined __APPLE__ 
        glClear(GL_COLOR_BUFFER_BIT);
    #else
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    #endif

        glEnable(GL_CULL_FACE);

        glMatrixMode(GL_MODELVIEW); //switch to model view mode

        glLoadIdentity();
        glTranslatef(-2.0f, -3.0f, -15.0f);
        glRotatef(180.0f, 1.0f, 0.0f, 0.0f);
        glRotatef(25.0f, 0.0f, 1.0f, 0.0f);
        drawCube();

        glLoadIdentity();
        glColor3f(0.4f, 0.3f, 0.9);
        glTranslatef(2.0f, -3.0f, -15.0f);
        //glRotatef(180.0f, 1.0f, 0.0f, 0.0f);
        glRotatef(25.0f, 0.0f, 1.0f, 0.0f);
        glutWireTeapot(1.0f);

        glLoadIdentity();
        glColor3f(0.4f, 0.3f, 0.9);
        glTranslatef(-2.0f, 3.0f, -15.0f);
        //glRotatef(180.0f, 1.0f, 0.0f, 0.0f);
        glRotatef(25.0f, 0.0f, 1.0f, 0.0f);
        glutWireSphere(1.0f, 16, 32);

        glLoadIdentity();
        glColor3f(0.3f, 0.3f, 0.9f);
        glTranslatef(2.0f, 3.0f, -15.0f);
        glRotatef(180.0f, 0.35f, 1.0f, 0.0f);
        glutSolidTorus(0.5f, 1.0f, 32, 16);

    glutSwapBuffers();
}

void enableLights()
{
    if (blLightsAreOn)
    {
        glEnable(GL_LIGHTING);
        glEnable(GL_COLOR_MATERIAL);

        GLfloat lightsKa[] = {0.1f, 0.1f, 0.1f, 1.0f};    //Ambient light
        GLfloat lightsKd[] = {0.0f, 0.7f, 0.0f, 1.0f};    //diffuse light
        GLfloat lightsKs[] = {0.0f, 0.0f, 1.0f, 1.0f};    //Specular light

        glLightfv(GL_LIGHT0, GL_AMBIENT, lightsKa);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightsKd);
        glLightfv(GL_LIGHT0, GL_SPECULAR, lightsKs);

        GLfloat lightPos[] = {0.0f, 0.0f, -15.0f, 1.0f};
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
        glEnable(GL_LIGHT0);
         
    }
    else
    {
        glDisable(GL_LIGHTING);
    }
}

void resetScene()
{
    blLightsAreOn = false;
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glClearDepth(1.0f);                    // Set background to furthest away
    glEnable(GL_DEPTH_TEST);               // Enable the depth test for z
    glDepthFunc(GL_LEQUAL);                // Set depth to be in front of the background 
    glShadeModel(GL_SMOOTH);               // Set to smooth shading 
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Used best perspective correction
    glFrontFace(GL_CCW);
    enableLights();
}

void reshape(GLsizei width, GLsizei height)
{
    blLightsAreOn = !blLightsAreOn;
    enableLights();

    cout << "Reshape" << endl;
    if (height <= 0) height = 1;
    if (width <= 0) width = 1;

    GLfloat aspectRatio = (GLfloat)width/(GLfloat)height;

    //Ste the viewport to cover the entire window
    glViewport(0, 0, width, height);

    //set the aspect ratio for rendering to math th viewport
    glMatrixMode(GL_PROJECTION);   //Switch to projection mode 
    glLoadIdentity();              //Reset stuff in the currant mode

    //Enable perspective projection mode with (fov, aspect, zNearClip, zfarClip)
    if (height <= 0) height = 1;
    gluPerspective(45.0f, aspectRatio, 0.1f, 100.0f);

}

void drawCube()
{

    glBegin(GL_QUADS);

            // Front Face (z = 1.0f)
        glColor3f(1.0f, 1.0f, 0.0f);  //
        glVertex3f( 1.0f,  1.0f,  1.0f); //A
        glVertex3f(-1.0f,  1.0f,  1.0f); //B
        glVertex3f(-1.0f, -1.0f,  1.0f); //C
        glVertex3f( 1.0f, -1.0f,  1.0f); //D

    glEnd();

    glBegin(GL_QUADS);

            // Right Face (z = 1.0f)
        glColor3f(1.0f, 1.0f, 1.0f);  //
        glVertex3f( 1.0f,  1.0f,  1.0f); //A
        glVertex3f( 1.0f, -1.0f,  1.0f); //D
        glVertex3f( 1.0f, -1.0f, -1.0f); //H
        glVertex3f(1.0f,  1.0f, -1.0f); //E

    glEnd();
    
    glBegin(GL_QUADS);

            // Back Face (z = 1.0f)
        glColor3f(1.0f, 0.5f, 0.50f);  //
        glVertex3f(1.0f,  1.0f, -1.0f); //E
        glVertex3f( 1.0f, -1.0f, -1.0f); //H
        glVertex3f(-1.0f, -1.0f, -1.0f); //G
        glVertex3f(-1.0f,  1.0f, -1.0f); //F

    glEnd();

    glBegin(GL_QUADS);

            // Left Face (z = 1.0f)
        glColor3f(0.34f, .65f, 1.0f);  //
        glVertex3f(-1.0f,  1.0f, -1.0f); //F
        glVertex3f(-1.0f, -1.0f, -1.0f); //G
        glVertex3f(-1.0f, -1.0f, 1.0f); //C
        glVertex3f(-1.0f,  1.0f,  1.0f); //B

    glEnd();

    glBegin(GL_QUADS);

            // Bottom Face (z = 1.0f)
        glColor3f(1.0f, 0.0f, 0.0f);  //
        glVertex3f(-1.0f, -1.0f, 1.0f); //C
        glVertex3f(-1.0f, -1.0f, -1.0f); //G
        glVertex3f( 1.0f, -1.0f, -1.0f); //H
        glVertex3f( 1.0f, -1.0f,  1.0f); //D
        

    glEnd();

    glBegin(GL_QUADS);

            // top Face (z = 1.0f)
        glColor3f(1.0f, 0.89f, 0.67f);  //
        glVertex3f(-1.0f,  1.0f, -1.0f); //F
        glVertex3f(-1.0f,  1.0f,  1.0f); //B
        glVertex3f( 1.0f,  1.0f,  1.0f); //A
        glVertex3f(1.0f,  1.0f, -1.0f); //E

    glEnd();

}

void drawPyramid()
{
    glBegin(GL_QUADS);

        glColor3f(1.0f, 0.0f, 0.0f);  //
        glVertex3f(-1.0f, -1.0f, 1.0f); //A
        glColor3f(0.75f, 0.5f, 1.0f);  //
        glVertex3f(-1.0f, -1.0f, -1.0f); //B
        glColor3f(0.95f, 0.0f, 1.0f);  //
        glVertex3f( 1.0f, -1.0f, -1.0f); //C
        glColor3f(0.24f, 1.0f, 1.0f);  //
        glVertex3f( 1.0f, -1.0f,  1.0f); //D

    glEnd();

    glBegin(GL_TRIANGLES);

        glColor3f(1.0f, 1.0f, 0.5f);  //
        glVertex3f(-1.0f, -1.0f, 1.0f); //A
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex3f(0.0f, 1.0f, 0.0f); //E
        glColor3f(0.2f, 1.0f, 0.5f);
        glVertex3f(-1.0f, -1.0f, -1.0f); //B
        
    glEnd();

    glBegin(GL_TRIANGLES);

        glColor3f(0.2f, 1.0f, 0.5f); 
        glVertex3f(-1.0f, -1.0f, -1.0f); //B
        glColor3f(0.0f, 1.0f, 1.0f);  //
        glVertex3f(0.0f, 1.0f, 0.0f); //E
        glColor3f(0.55f, 0.5f, 0.25f);  //
        glVertex3f( 1.0f, -1.0f, -1.0f); //C
        
    glEnd();

    glBegin(GL_TRIANGLES);

        glColor3f(0.55f, 0.5f, 0.25f); //
        glVertex3f(1.0f, -1.0f, -1.0f); //C
        glColor3f(0.0f, 1.0f, 1.0f);  //
        glVertex3f(0.0f, 1.0f, 0.0f); //E
        glColor3f(0.43f, 0.5f, 0.3f);  //
        glVertex3f( 1.0f, -1.0f,  1.0f); //D
        
    glEnd();

    glBegin(GL_TRIANGLES);

          
        glColor3f(0.43f, 0.5f, 0.3f);  //
        glVertex3f( 1.0f, -1.0f, 1.0f); //D
        glColor3f(0.0f, 1.0f, 1.0f); //
        glVertex3f(0.3f, 1.0f,  0.56f); //E
        glColor3f(1.0f, 1.0f, 0.5f);  
        glVertex3f(-1.0f, -1.0f, 1.0f); //A
        
    glEnd();

}
