/*
 *
 *  Server
 * 
 *  by Vinicius Rodrigues
 *  20 de Janeiro de 2020
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <thread>
#include <SFML/Network.hpp>

#ifndef _SERVER_H_
#define _SERVER_H_

class Server
{

public:

    Server();

    void init(unsigned int port);
    void playerListener(int player);
    void notifyAll(std::string msg);

    // Função que chama uma função da classe
    // filha para que entre nas funções de thread
    virtual void serviceThread() = 0;


    // Essa função é definida na classe filha
    // Para que receba mensagens dos clientes
    virtual void atualize(std::string) = 0;

    ~Server();

private:

    sf::TcpListener listener;
    unsigned int port;
    sf::TcpSocket player1, player2;
};

#include "server.cpp"

#endif