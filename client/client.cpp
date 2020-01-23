/*
    client.cpp
*/

Client::Client()
{
}

void Client::connect(const char* ip, unsigned int port)
{
    if(socket.connect(ip, port) != sf::Socket::Done)
    {
        std::cout << "Erro ao connectar a " << ip << ':' << port << std::endl;
        return;
    }
    std::cout << "Conectado ao servidor" << std::endl;

    std::string msg = receive();
    std::cout << msg << std::endl;
}

void Client::init()
{
    // std::thread listen([this]() {
    //     this->initListen();
    // });
    // std::thread interface([this]() {
    //     this->interfaceThread();
    // });

    // listen.join();
    // interface.join();

    this->interfaceThread();
}

void Client::initListen()
{
    while(true)
    {
        listen();
    }
}

void Client::listen()
{
    std::string msg = receive();
    actualize(msg);
}

void Client::send(std::string msg)
{
    if(socket.send(msg.c_str(), msg.length()) != sf::Socket::Done)
    {
        std::cout << "Erro ao enviar a mensagem" << std::endl;
    }
}

std::string Client::receive()
{
    const std::size_t size = 100;
    char data[size];
    std::size_t readSize;

    if(socket.receive(data, size, readSize) != sf::Socket::Done)
    {
        std::cout << "Erro ao receber mensagem" << std::endl;
    }

    return std::string(data).substr(0, readSize);
}

Client::~Client()
{
}