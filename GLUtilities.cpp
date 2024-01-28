// File Name: GLUtilities.cpp
// Description: See header file for information
// Author: Marcus BLea
// Date modified: November 17, 2022


#include "GLUtilities.h"

void drawStrokeText(char *text, void *font, GLfloat x, GLfloat y, GLfloat z)
{
    //GLUT_STROKE_ROMAN
    //GLUT_STROKE_MONO_ROMAN
    glPushMatrix();
    glTranslatef(x, y, z);
    char *c;
    for (c=text; *c != '\0'; c++)
    {
        //glColor3f(*c/127.0f,*c/127.0f, *c/127.0f);
        //glColor3f(*c/255.0f,*c/255.0f, *c/255.0f);
        glColor3f(rand()/(GLfloat)RAND_MAX,rand()/(GLfloat)RAND_MAX, rand()/(GLfloat)RAND_MAX);
        glutStrokeCharacter(font, *c);
    }
    glPopMatrix();
}
void drawBitmapText(char *text, void *font, GLfloat x, GLfloat y)
{
    //GLUT_BITMAP_TIMES_ROMAN_10
    //GLUT_BITMAP_8_BY_13
    //GLUT_BITMAP_9_BY_15
    //GLUT_BITMAP_TIMES_ROMAN_24

    glPushMatrix();
    glRasterPos2f(x, y);
    char *c;
    for (c=text; *c; c++)
    {
        glutBitmapCharacter(font, *c);
        
    }
    glPopMatrix();

}
GLfloat getStrokeTextWidth(char *text, void *font)
{
    GLfloat w = 0.0f;
    char *c;
    for (c=text; *c != '\0'; c++)
    {
        w += (GLfloat)glutStrokeWidth(font, *c);
    }
    return w;

}

GLfloat getBitmapTextWidth(char *text, void *font)
{
    GLfloat w = 0.0f;
    char *c;
    for (c=text; *c; c++)
    {
        w += (GLfloat)glutBitmapWidth(font, *c);
    }
    return w;
}

void drawPyramid()
{ 
    //bottom face (y = -1.0f)
    glBegin(GL_QUADS);                  // Every glBegin it has to have a glEnd
        glColor3f(0.7f, 0.3f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);   // A 
        glVertex3f(-1.0f, -1.0f, -1.0f);  // B
        glVertex3f(1.0f, -1.0f, -1.0f);   // C
        glVertex3f(1.0f, -1.0f, 1.0f);    // D
    glEnd();
    //front face
    glBegin(GL_TRIANGLES);                  // Every glBegin it has to have a glEnd
        glColor3f(0.8f, 0.5f, 0.2f);
        glVertex3f(-1.0f, -1.0f, 1.0f); // A
        glColor3f(0.2f, 0.1f, 0.5f);
        glVertex3f(-1.0f, -1.0f, -1.0f);  // B
        glColor3f(0.6f, 0.4f, 0.7f);
        glVertex3f(0.0f, 1.0f, 0.0f);    // I
       
  glEnd();
    //Right face
    glBegin(GL_TRIANGLES);                  // Every glBegin it has to have a glEnd
        glColor3f(0.4f, 0.1f, 0.9f);
        glVertex3f(-1.0f, -1.0f, -1.0f);  // B
        glColor3f(0.6f, 0.4f, 0.7f);
        glVertex3f(1.0f, -1.0f, -1.0f);   // C
        glColor3f(0.3f, 0.4f, 0.7f);
        glVertex3f(0.0f, 1.0f, 0.0f);    // I
    glEnd();
    //Left face
    glBegin(GL_TRIANGLES);                  // Every glBegin it has to have a glEnd
        glColor3f(0.9f, 0.4f, 0.4f);
        glVertex3f(1.0f, -1.0f, -1.0f);   // C
        glColor3f(0.6f, 0.4f, 0.7f);
        glVertex3f(1.0f, -1.0f, 1.0f);    // D
        glColor3f(0.3f, 0.4f, 0.7f);
        glVertex3f(0.0f, 1.0f, 0.0f);    // I
        
    glEnd();
  //Back face
    glBegin(GL_TRIANGLES);                  // Every glBegin it has to have a glEnd
        glColor3f(0.6f, 0.6f, 0.7f);
        glVertex3f(1.0f, -1.0f, 1.0f);    // D
        glColor3f(0.6f, 0.4f, 0.7f);
        glVertex3f(-1.0f, -1.0f, 1.0f); // A
        glColor3f(0.3f, 0.4f, 0.7f);
        glVertex3f(0.0f, 1.0f, 0.0f);    // I
        
    glEnd();
}

void drawCube()
{
    // Front face (z = 1.0f)
    glBegin(GL_QUADS);                  // Every glBegin it has to have a glEnd
        glColor3f(0.5f, 0.5f, 0.5f);
        glVertex3f(1.0f, 1.0f, 1.0f);     // A
        glVertex3f(-1.0f, 1.0f, 1.0f);    // B
        glVertex3f(-1.0f, -1.0f, 1.0f);   // C 
        glVertex3f(1.0f, -1.0f, 1.0f);    // D
    glEnd();

    //Right face (z = 1.0f)
    glBegin(GL_QUADS);                  // Every glBegin it has to have a glEnd
        glColor3f(0.3f, 0.0f, 0.9f);
        glVertex3f(1.0f, 1.0f, 1.0f);     // A
        glVertex3f(1.0f, -1.0f, 1.0f);    // D
        glVertex3f(1.0f, -1.0f, -1.0f);   // H 
        glVertex3f(1.0f, 1.0f, -1.0f);    // E
    glEnd();

    //bottom face (y = -1.0f)
    glBegin(GL_QUADS);                  // Every glBegin it has to have a glEnd
        glColor3f(0.8f, 0.4f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);   // C 
        glVertex3f(-1.0f, -1.0f, -1.0f);  // G
        glVertex3f(1.0f, -1.0f, -1.0f);   // H 
        glVertex3f(1.0f, -1.0f, 1.0f);    // D
    glEnd();

    //left face (x = -1.0f)
    glBegin(GL_QUADS);                  // Every glBegin it has to have a glEnd
        glColor3f(0.1f, 0.4f, 0.9f);
        glVertex3f(-1.0f, 1.0f, 1.0f);    // B
        glVertex3f(-1.0f, 1.0f, -1.0f);   // F
        glVertex3f(-1.0f, -1.0f, -1.0f);  // G
        glVertex3f(-1.0f, -1.0f, 1.0f);   // C 
    glEnd();

    //back face (z = -1.0f)
    glBegin(GL_QUADS);                  // Every glBegin it has to have a glEnd
        glColor3f(0.6f, 0.7f, 0.8f);
        glVertex3f(1.0f, 1.0f, -1.0f);    // E
        glVertex3f(1.0f, -1.0f, -1.0f);   // H 
        glVertex3f(-1.0f, -1.0f, -1.0f);  // G
        glVertex3f(-1.0f, 1.0f, -1.0f);   // F
    glEnd();

    //Top Face
    glBegin(GL_QUADS);                  // Every glBegin it has to have a glEnd
        glColor3f(0.3f, 0.4f, 0.4f);
        glVertex3f(1.0f, 1.0f, 1.0f);     // A
        glVertex3f(1.0f, 1.0f, -1.0f);    // E
        glVertex3f(-1.0f, 1.0f, -1.0f);   // F
        glVertex3f(-1.0f, 1.0f, 1.0f);    // B
    glEnd();

}