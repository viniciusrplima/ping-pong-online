/*
    client.h
*/

#include <iostream>
#include <thread>
#include <SFML/Network.hpp>

#ifndef _CLIENT_H_
#define _CLIENT_H_

class Client
{

public:

    Client();

    void connect(const char* ip, unsigned int port); // Conecta-se ao servidor
    void init(); // Inicializa thread principais do cliente
    void send(std::string msg); // Envia mensagens ao servidor
    std::string receive();  // Espera por mensagens do servidor
    void initListen();  // Inicializa e gerencia a comunicação com o servidor

    void listen();

    // Função que adiciona a classe filha na thread do cliente
    virtual void interfaceThread() = 0;

    // Função que atualize a classe filha
    virtual void actualize(std::string msg) = 0;

    ~Client();

protected:

    sf::TcpSocket socket;

};

#include "client.cpp"

#endif