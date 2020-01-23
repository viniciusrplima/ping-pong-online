/*
 *  Ping Pong Online
 * 
 *  by Vinicius Rodrigues
 *  21 de Janeiro de 2020
 * 
 */

#include <iostream>

#include "game/game.h"

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        std::cout << "Erro: Necessário indicar porta" << std::endl;
        return 1;
    }

    Game game;
    game.init(atoi(argv[1]));
}