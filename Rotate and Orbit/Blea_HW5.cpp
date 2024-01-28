//Filename: Blea_HW05.cpp
//Description: Rotate and orbit
//Author: Marcus Blea
//October 18th 2022

#include <iostream>
using namespace std;

#if defined __APPLE__ 
    #include <GLUT/glut.h>
#elif defined _WIN32 || defined _WIN64
    #include <GL/glut.h>
#elif __linux__
    #include <GL/freeglut.h>
#endif

// Function protoypes
void enableLights();
void display(void);
void resetScene();
void reshape(GLsizei width, GLsizei height);
void keyboardClick(unsigned char key, GLsizei x, GLsizei y);
void mouseClick(int button, int state, GLsizei x, GLsizei y);
void mouseMotion(GLsizei x, GLsizei y);
void timer(int millisec);
void drawCube();
void drawPyramid();


//Global Varibles
bool blLightsAreOn = true;
GLfloat rotationX, rotationY;   // Current rotation of the center object
GLfloat locationX, locationY;   // Current location of the center object
int orbitRotation;              // Rotation in degrees 
GLsizei prevMouseX, prevMouseY; // Current mouse location in the window
GLsizei windowWidth = 640, windowHeight = 480;
bool blMouseLeftDown;           // Current state of the windoww
bool blMouseMiddleDown;         // Current state of the windoww
bool blMouseRightDown;          // Current state of the windoww



int main(int argc, char** argv)
{

    //glutInit is used to initialize the GLUT library. 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_DOUBLE); // use double buffer mode
    glutInitWindowSize(windowWidth, windowHeight); // Set the window's intial width and hieght
    glutInitWindowPosition(50, 50); // Postion's the window's top-left corner 
    glutCreateWindow(" Draw Lots Of GLUT Shapes!");

    // Callback Functions
    glutDisplayFunc(&display);        // Callback to display
    glutReshapeFunc(&reshape);        // Callback to catch reshape of the window
    glutKeyboardFunc(&keyboardClick); //Callback to the handle noraml keyborad clicks
    glutMouseFunc(&mouseClick);       // Callback to handle mouse buttons
    glutMotionFunc(&mouseMotion);     // Callback to handle mouse movement
    glutTimerFunc(20, &timer, 20);    // Redraw every 20m2(50 times per second)

    resetScene;
    glutMainLoop();
    return EXIT_SUCCESS;
}

void display(void)
{ 
    //cout << orbitRotation << endl;
    //cout << "Drawing..." << endl;
    enableLights();
    #if defined__APPLE__
    glClear(GL_COLOR_BUFFER_BIT);
    #else
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    #endif
    glEnable(GL_CULL_FACE);
    glMatrixMode(GL_MODELVIEW);         // Swtich to model view mode (objects)

    //Draw the Center
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -15.0f);
    glPushMatrix();   // Stores the current state of the matrix
    glTranslatef(locationX, locationY, 0.0f); 
    glRotatef(orbitRotation, 0.0f, 1.0f, 0.0f); // says go ahead and rotate how many degress. Takes object and roate it around the x axis
    glRotatef(orbitRotation, 1.0f, 0.0f, 0.0f);
    glScalef(0.5f, 0.5f, 0.5f);
    //glRotatef(25.0f, 0.0f, 1.0f, 0.0f);
    drawCube();
    glPopMatrix();                       // restroes the current state of the matrix

    //Draw the orbiting object
    glPushMatrix();  
    glRotatef(rotationX, 1.0f, 0.0f, 0.0f);
    glRotatef(-orbitRotation, 0.0f, 1.0f, 0.0f); // orbit
    glTranslatef(3.0f + locationX, 0.0f, 0.0f);
    glRotatef(orbitRotation, 1.0f, 0.0f, 0.0f); // spin
    glScalef(0.3f, 0.3f, 0.3f);
    glutSolidTorus(0.5f, 1.0f, 32, 16);
    glPopMatrix();                   


    glutSwapBuffers(); // call once and only once
}

void enableLights()
{
    if(blLightsAreOn)
    {
        glEnable(GL_LIGHTING);
        glEnable(GL_COLOR_MATERIAL);

        GLfloat lightsKa[] = {0.4f, 0.4f, 0.4f,1.0f};   // ambient light
        GLfloat lightsKd[] = {0.7f, 0.7f, 0.7f, 1.0f};  // diffuse light
        GLfloat lightsKs[] = {1.0f, 1.0f, 1.0f,1.0f};  // specular light
        glLightfv(GL_LIGHT0, GL_AMBIENT, lightsKa);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightsKd);
        glLightfv(GL_LIGHT0, GL_SPECULAR, lightsKs);

        GLfloat lightPos[] = {0.0f, 0.0f, -13.0f, 1.0f}; // location of the light
        glLightfv (GL_LIGHT0, GL_POSITION, lightPos);
        glEnable(GL_LIGHT0);


    }
    else
    {
        glDisable(GL_LIGHTING);

    }

}

void resetScene()
{
    blLightsAreOn = true;
    rotationX = 0.0f;
    rotationY = 0.0f;
    locationX = 0;
    locationY = 0;
    prevMouseX = 0;
    prevMouseY = 0;
    prevMouseX, prevMouseY;
    blMouseLeftDown = false;
    blMouseMiddleDown = false;
    blMouseRightDown = false;

    glClearColor(0.05f, 0.05f, 0.05f, 1.0f); // f is short for floating point
    glClearDepth(1.0f);                      // Set the background to 
    glEnable(GL_DEPTH_TEST);                 // Enable the dpeth test for z-culling
    glDepthFunc(GL_LEQUAL);                  // Set depth to be in front of the background
    glShadeModel(GL_SMOOTH);                 // Set to smooth shading 
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // USE best persecptive direction
    glFrontFace (GL_CCW);
    glutPostRedisplay();

}

void reshape(GLsizei width, GLsizei height)
{
 
    cout << "reshape!" << endl;
    if (height <= 0)  height = 1;           // Sanity checks. Atlest keep it at one
    if (width <= 0)  width = 1;             // Sanity Checks. Atleast keep it at 1
    GLfloat aspectRatio = (GLfloat)width / (GLfloat)height;

    windowWidth = width;
    windowHeight = height;

    // Set the viewport to cover the entire window
    glViewport (0, 0, width, height);

    // set the aspect ratio for rendering to match the viewport 
    glMatrixMode(GL_PROJECTION); // Swtich to projection mode (camera)
    glLoadIdentity(); //Reset stuff in the current mode

    //Enable perspective projection mode with (fov, aspect, zNearClip)
    gluPerspective(45.0, aspectRatio, 0.1f, 100.0f); // easy way to set up the camera

}

void keyboardClick(unsigned char key, GLsizei x, GLsizei y)
{

    switch (key)
    {
        case 'q': case 'Q': case 27:
            exit(EXIT_SUCCESS);
        break;
        case 'l': case 'L': 
            blLightsAreOn = !blLightsAreOn;
        glutPostRedisplay();
      break;
        case 'r': case 'R' :
            resetScene();
            glutPostRedisplay();
         break;  


    }

}

void mouseClick(int button, int state, GLsizei x, GLsizei y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN) blMouseLeftDown = true;
        else blMouseLeftDown = false;

    }
    if (button == GLUT_MIDDLE_BUTTON)
    {
        if (state == GLUT_DOWN) blMouseMiddleDown = true;
        else blMouseMiddleDown = false;

    }
    if (button == GLUT_RIGHT_BUTTON)
    {
        if (state == GLUT_DOWN) blMouseRightDown = true;
        else blMouseRightDown = false;

    }
    prevMouseX = x;
    prevMouseY = y;
    glutPostRedisplay();

  
}
void mouseMotion(GLsizei x, GLsizei y)
{
    if (blMouseLeftDown)
    {
        rotationX += x - prevMouseX;
        rotationY += y - prevMouseY;

    }
    if (blMouseRightDown)
    {
        locationX += 10.0f * (x - prevMouseX) / windowWidth;
        locationY += 10.0f * (y - prevMouseY) / windowHeight;
        //locationY += y - prevMouseY;

    }
    prevMouseX = x;
    prevMouseY = y;
    glutPostRedisplay();

}
void timer(int millisec)
{
    orbitRotation++;
    if (orbitRotation >= 360) orbitRotation -= 360;
    glutTimerFunc(millisec, &timer, millisec);
    glutPostRedisplay();

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
void drawCube()
{
    // Front face (z = 1.0f)
    glBegin(GL_QUADS);                  // Every glBegin it has to have a glEnd
        glColor3f(0.7f, 0.6f, 0.3f);
        glVertex3f(1.0f, 1.0f, 1.0f);     // A
        glVertex3f(-1.0f, 1.0f, 1.0f);    // B
        glVertex3f(-1.0f, -1.0f, 1.0f);   // C 
        glVertex3f(1.0f, -1.0f, 1.0f);    // D
    glEnd();

    //Right face (z = 1.0f)
    glBegin(GL_QUADS);                  // Every glBegin it has to have a glEnd
        glColor3f(0.5f, 0.8f, 0.8f);
        glVertex3f(1.0f, 1.0f, 1.0f);     // A
        glVertex3f(1.0f, -1.0f, 1.0f);    // D
        glVertex3f(1.0f, -1.0f, -1.0f);   // H 
        glVertex3f(1.0f, 1.0f, -1.0f);    // E
    glEnd();

    //bottom face (y = -1.0f)
    glBegin(GL_QUADS);                  // Every glBegin it has to have a glEnd
        glColor3f(0.4f, 0.5f, 0.9f);
        glVertex3f(-1.0f, -1.0f, 1.0f);   // C 
        glVertex3f(-1.0f, -1.0f, -1.0f);  // G
        glVertex3f(1.0f, -1.0f, -1.0f);   // H 
        glVertex3f(1.0f, -1.0f, 1.0f);    // D
    glEnd();

    //left face (x = -1.0f)
    glBegin(GL_QUADS);                  // Every glBegin it has to have a glEnd
        glColor3f(0.1f, 0.7f, 0.9f);
        glVertex3f(-1.0f, 1.0f, 1.0f);    // B
        glVertex3f(-1.0f, 1.0f, -1.0f);   // F
        glVertex3f(-1.0f, -1.0f, -1.0f);  // G
        glVertex3f(-1.0f, -1.0f, 1.0f);   // C 
    glEnd();

    //back face (z = -1.0f)
    glBegin(GL_QUADS);                  // Every glBegin it has to have a glEnd
        glColor3f(0.6f, 0.8f, 0.4f);
        glVertex3f(1.0f, 1.0f, -1.0f);    // E
        glVertex3f(1.0f, -1.0f, -1.0f);   // H 
        glVertex3f(-1.0f, -1.0f, -1.0f);  // G
        glVertex3f(-1.0f, 1.0f, -1.0f);   // F
    glEnd();

    //Top Face
    glBegin(GL_QUADS);                  // Every glBegin it has to have a glEnd
        glColor3f(0.7f, 0.8f, 0.4f);
        glVertex3f(1.0f, 1.0f, 1.0f);     // A
        glVertex3f(1.0f, 1.0f, -1.0f);    // E
        glVertex3f(-1.0f, 1.0f, -1.0f);   // F
        glVertex3f(-1.0f, 1.0f, 1.0f);    // B
    glEnd();

}