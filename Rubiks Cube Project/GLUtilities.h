// File Name: GLUtilities.h
// Description: Custom utilities for OPenGL
// Author: Marcus Blea
// Date modified: November 17, 2022



#include <iostream>
using namespace std;
#include "Material.h"



#if defined __APPLE__
  #include <GLUT/glut.h> //If you are MAC
#elif defined _WIN32 || defined _WIN64
  #include <GL/glut.h> // If you are on PC
#elif _linux__
  #include <GLUT/freeglut.h>
#endif

void drawTextureCube(Material materials[], GLfloat w);

// Function Prototypes
void drawStrokeText(char *text, void *font, GLfloat x, GLfloat y, GLfloat z);
GLfloat getStrokeTextWidth(char *text, void *font);
void drawBitmapText(char *text, void *font, GLfloat x, GLfloat y);
GLfloat getBitmapTextWidth(char *text, void *font);

void drawCube();
void drawPyramid();