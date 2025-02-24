#pragma once 
#include <GL/glut.h>
#include <stdio.h>

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

};