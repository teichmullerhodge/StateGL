#include <GL/glut.h>
#include "stateGL/configurations.hpp"
#include "stateGL/window.hpp"
#include "stateGL/scene.hpp"
#include "stateGL/interaction.hpp"
#include "stateGL/statefull.hpp"
#include <stdio.h>
#include <time.h>
#include <math.h>


void update(){

    if(Statefull::savePathLoaded){

        Statefull::watch_state();
    }

    float red[] = {1.0f, 0.0f, 0.0f, 1.0f};
    float green[] = {0.0f, 1.0f, 0.0f, 1.0f};
    float blue[] = {0.0f, 0.0f, 1.0f, 1.0f};
    float pink[] = {1.0f, 0.0f, 1.0f, 1.0f};
    // printf("%f\n", Statefull::size.value);
    glBegin(GL_POLYGON);        

        Scene::set_draw_color(red);
        glVertex2f(-Statefull::size.value, 0.0f);

        Scene::set_draw_color(green);
        glVertex2f(0.0f, Statefull::size.value);

        Scene::set_draw_color(blue);
        glVertex2f(Statefull::size.value, 0.0f);

        
        Scene::set_draw_color(pink);
        glVertex2f(0.0f, -Statefull::size.value);

        
            
    glEnd(); 
    glutSwapBuffers();
    glFlush(); 

}

int main(int argc, char** argv) {
    
    srand(time(NULL));

    if(argc > 1){
        bool reloadedState = Statefull::init(argv[1]);
        printf(reloadedState ? "Success loading state." : "Could not load state");
    }

    Window::init(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE, argc, argv);
    Window::set_color(0.1, 0.3, 0.3, 1.0);
    Scene::register_display_callback(Scene::display);
    Scene::register_keyboard_callback(Movement::handle_interaction);
    Scene::main_loop(update);
    return 0;
}