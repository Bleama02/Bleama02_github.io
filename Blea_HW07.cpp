// File Name: Blea_HW07.cpp
// Description: Moving the Camera
// Author: Marcus Blea
// Date modified: November 15, 2022

#include "GLUtilities.h"
#include "Camera.h"

// Function protoypes
void enableLights();
void display(void);
void resetScene();
void reshape(GLsizei width, GLsizei height);
void keyboardClick(unsigned char key, GLsizei x, GLsizei y);
void specialInput(int key, GLsizei x, GLsizei y);
void mouseClick(int button, int state, GLsizei x, GLsizei y);
void mouseMotion(GLsizei x, GLsizei y);
void timer(int millisec);


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


Camera avatarPOV;

int main(int argc, char** argv)
{

    //glutInit is used to initialize the GLUT library. 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); 
    glutInitWindowSize(windowWidth, windowHeight); 
    glutInitWindowPosition(50, 50); // Postion's the window's top-left corner 
    glutCreateWindow(" Draw Lots Of GLUT Shapes!");

    // Callback Functions
    glutDisplayFunc(&display);        // Callback to display
    glutReshapeFunc(&reshape);       
    glutKeyboardFunc(&keyboardClick); 
    glutSpecialFunc(&specialInput);
    glutMouseFunc(&mouseClick);       
    glutMotionFunc(&mouseMotion);    
    glutTimerFunc(20, &timer, 20);    

    resetScene();
    glutMainLoop();
    return EXIT_SUCCESS;
}

void display(void)
{   
    reshape(windowWidth, windowHeight);
    avatarPOV.runCamera();
    enableLights();
    #if defined__APPLE__
    glClear(GL_COLOR_BUFFER_BIT);
    #else
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    #endif
    glEnable(GL_CULL_FACE);
    glMatrixMode(GL_MODELVIEW);         // Swtich to model view mode (objects)
    glLoadIdentity();

   
    glPushMatrix();   
    glTranslatef(locationX, locationY, 0.0f); 
    glRotatef(orbitRotation, 0.0f, 1.0f, 0.0f); 
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
    drawPyramid();
    glPopMatrix();                   

    //glTranslatef(0.0f, 0.0f, -10.0f);
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
    avatarPOV.setLocation(0.0f, 0.0f, -7.0f);
    avatarPOV.setRotation(0.0f, 0.0f, 1.0f);
    avatarPOV.setProjectionType(CAM_PROJ_PERSPECTIVE);
    blLightsAreOn = true;
    rotationX = 0.0f;
    rotationY = 0.0f;
    locationX = 0;
    locationY = 0;
    prevMouseX = 0;
    prevMouseY = 0;
    //prevMouseX, prevMouseY;
    blMouseLeftDown = false;
    blMouseMiddleDown = false;
    blMouseRightDown = false;

    glClearColor(0.05f, 0.05f, 0.05f, 1.0f); 
    glClearDepth(1.0f);                      
    glEnable(GL_DEPTH_TEST);                
    glDepthFunc(GL_LEQUAL);                 
    glShadeModel(GL_SMOOTH);                 
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 
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

    avatarPOV.setupCamera(CAM_PROJ_PERSPECTIVE, width, height, 45.0f, 0.01f, 2000.0f);

    // Set the viewport to cover the entire window
    glViewport(0, 0, width, height);
}

void keyboardClick(unsigned char key, GLsizei x, GLsizei y)
{

    switch (key)
    {
        case 'q': case 'Q': case 27:
            exit(EXIT_SUCCESS);
            break;
        case 'L': 
            blLightsAreOn = !blLightsAreOn;
      break;
        case 'r': case 'R' :
            resetScene();
            break;
        case 'w':
            avatarPOV.moveForward(0.1f);
            break; 
        case 's':
            avatarPOV.moveBackward(0.1f);
            break; 
        case 'a':
            avatarPOV.strafeLeft(0.1f);
            break;   
        case 'd':
            avatarPOV.strafeRight(0.1f);
            break;
         case 'i':
            avatarPOV.moveForward(10.0f);
            break; 
        case 'k':
            avatarPOV.moveBackward(10.0f);
            break; 
        case 'j':
            avatarPOV.turnLeft(0.5f);
            break;   
        case 'l':
            avatarPOV.turnRight(0.5f);
            break;
        case '\'':
            avatarPOV.moveUp(0.1f);
            break;   
        case '/':
            avatarPOV.moveDown(0.1f);
            break;

    }
    glutPostRedisplay();

}

void specialInput(int key, GLsizei x, GLsizei y)
{
     switch (key)
    {
        case GLUT_KEY_UP:
            avatarPOV.moveForward();
            break; 
        case GLUT_KEY_DOWN:
            avatarPOV.moveBackward();
            break; 
        case GLUT_KEY_LEFT:
            avatarPOV.strafeLeft();
            break;   
        case GLUT_KEY_RIGHT:
            avatarPOV.strafeRight();
            break;
    }
    glutPostRedisplay();
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
        if(x < prevMouseX) avatarPOV.turnLeft(0.3f);
        if(x > prevMouseX) avatarPOV.turnRight(0.3f);
        if(y > prevMouseY) avatarPOV.lookDown(0.3f);
        if(y < prevMouseY) avatarPOV.lookUp(0.3f);

        rotationX += x - prevMouseX;
        rotationY += y - prevMouseY;

    }
    if (blMouseRightDown)
    {
        if(x < prevMouseX) avatarPOV.strafeLeft(0.3f);
        if(x > prevMouseX) avatarPOV.strafeRight(0.3f);
        if(y < prevMouseY) avatarPOV.moveForward(0.3f);
        if(y > prevMouseY) avatarPOV.moveBackward(0.3f);
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