#pragma once 
#include <GL/glut.h>


class Scene {

public:

    static void display(){
        Scene::set_draw_color(1.0f, 0.0f, 1.0f, 0.0f);
        
        glClear(GL_COLOR_BUFFER_BIT);
        glutSwapBuffers(); 
    }

    static void set_draw_color(float R, float G, float B, float A){ 

        glColor4f(R, G, B, A);

    }

    static void set_draw_color(float RGBA[]){ 

        glColor4f(RGBA[0], RGBA[1], RGBA[2], RGBA[3]);

    }


    static void register_keyboard_callback(void (*callback)(unsigned char, int, int)){
        
        glutKeyboardFunc(callback);

    }
    
    static void register_display_callback(void (*callback)()){

        glutDisplayFunc(callback); 

    }

    static void main_loop(void (*callback)()){
     
        glutIdleFunc(callback); 
        glutMainLoop(); 

    }
};


