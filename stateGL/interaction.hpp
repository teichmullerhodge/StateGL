#pragma once 
#include <GL/glut.h>
#include <stdio.h>
#include "statefull.hpp"

enum MouseKeys {
    LEFT_CLICK,
    MIDDLE_CLICK,
    RIGHT_CLICK
};

class Movement {

public:
    static void handle_interaction(u_char key, int x, int y){

        printf("%d\n", key);
        switch(key){
            case 81: //q
            case 113: //Q 
                printf("Exiting...\n");
                exit(0);

        }
    }

    static void handle_mouse(int x, int y){

        float coordinateXPos = ((float)WIN_WIDTH - (float)x) / WIN_WIDTH;
        float coordinateYPos = ((float)WIN_HEIGHT - (float)y) / WIN_WIDTH;
        printf("Mouse at %f, %f\n", coordinateXPos, coordinateYPos);

    }

    static void handle_mouse_click(int button, int state, int x, int y){

        static int counter = 0;
        float coordinateXPos = ((float)WIN_WIDTH - (float)x) / WIN_WIDTH;
        float coordinateYPos = ((float)WIN_HEIGHT - (float)y) / WIN_WIDTH;
        if(state == 0){ // ? the button is clicked.
            bool resetState = false;
            switch(button){
                case RIGHT_CLICK:
                    resetState = true;
                    break;
                
            }    

            if(resetState){
                coordinateXPos = 0.0f;
                coordinateYPos = 0.0f;
            }

            switch(counter){
                case 1:
                    Statefull::x1.value = coordinateXPos;
                    Statefull::y1.value = coordinateYPos;
                    printf("Point created at (%f, %f)\n", Statefull::x1.value, Statefull::y1.value);
                    break;
                case 2:
                    Statefull::x2.value = coordinateXPos;
                    Statefull::y2.value = coordinateYPos;
                    printf("Point created at (%f, %f)\n", Statefull::x2.value, Statefull::y2.value);
                    break;
                case 3:
                    Statefull::x3.value = coordinateXPos;
                    Statefull::y3.value = coordinateYPos;
                    printf("Point created at (%f, %f)\n", Statefull::x3.value, Statefull::y3.value);
                    break;
                case 4:   
                    Statefull::x4.value = coordinateXPos;
                    Statefull::y4.value = coordinateYPos;
                    printf("Point created at (%f, %f)\n", Statefull::x4.value, Statefull::y4.value);
                    break;             
            }
            counter++;
            if(counter == 4){
                counter = 0;
            }
        }
        Statefull::shouldReload = true;

    }

};