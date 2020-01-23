/*
 *
 *  Game
 *  
 *  by Vinicius Rodrigues
 *  21 de Janeiro de 2020
 * 
 */

#include <iostream>

#include <glm/glm.hpp>

#include "../server/server.h"
#include "../utils/game_state.hpp"
#include "../utils/parse_game_state.hpp"
#include "../utils/parse_coords.hpp"

#ifndef _GAME_H_
#define _GAME_H_

class Game : public Server
{

public:

    Game();

    void init(unsigned int port);
    void resetGame();
    void initGame();
    void movePlayer(int player, std::string action);
    void updateGame();
    void updateBall(float elapsed);
    void updateCollision();
    bool isTableCollision(float x, float y);
    void adjustBallPosition(float xTable, int player);
    void actualizeClients();
    void serviceThread();
    void atualize(std::string msg);

    ~Game();

private:

    GameState gameState;
    float ballAngle;

};

#include "game.cpp"

#endif