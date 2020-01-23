

#include <iostream>
#include "interface.h"
#include "../utils/game_state.hpp"
    
Interface interface;

void render()
{
    interface.render();
}

void keyboard(int key, int, int)
{
    interface.keyboardHandle(key);
}

void update()
{
    interface.listen();
}

int main(int argc, char** argv)
{
    if(argc < 3)
    {
        std::cout << "Erro: endereço ip ou número de porta não informado" << std::endl;
	return 1;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE bitor GLUT_RGBA);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("");

    glutDisplayFunc(render);
    glutSpecialFunc(keyboard);
    glutIdleFunc(update);

    interface.connect(argv[1], atoi(argv[2]));
    interface.init();
}
