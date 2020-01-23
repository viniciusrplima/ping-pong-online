/*
 *
 *  Interface
 *  
 *  by Vinicius Rodrigues
 *  21 de Janeiro de 2020
 */

#include <iostream>
#include <thread>
#include <GL/glut.h>
#include <SFML/Network.hpp>

#include "../client/client.h"
#include "../utils/game_state.hpp"
#include "../utils/parse_game_state.hpp"
#include "../utils/parse_coords.hpp"

#ifndef __INTERFACE_H_
#define __INTERFACE_H_

class Interface : public Client
{

public:

    Interface();

    void init();
    void resetGame();
    void interfaceThread();
    void render();
    void renderTable(float x, float y);
    void renderBall(float x, float y);
    void renderScore();
    void keyboardHandle(int key);

    void actualize(std::string msg);

    ~Interface();

private:

    GameState gameState;

};

#include "interface.cpp"

#endif