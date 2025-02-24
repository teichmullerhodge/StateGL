#pragma once 
#include <GL/glut.h>


class Window {

public:
    static void init(int width, int height, const char *title, int argc, char** argv){

        glutInit(&argc, argv); 
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
        glutInitWindowSize(width, height); 
        glutCreateWindow(title); 
    
    
    }

    static void set_color(float R, float G, float B, float A){ 

        glClearColor(R, G, B, A);
    }
};