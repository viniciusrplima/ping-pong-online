/*
    server.cpp

*/


Server::Server()
{
}

void Server::init(unsigned int port)
{
    this->port = port;

    // Conectando a porta e criando o servidor
    listener.listen(port);
    std::cout << "Conectado na porta " << port << std::endl;

    // Conectando aos clientes
    std::cout << "Esperando conexão do player 1" << std::endl;
    if(listener.accept(player1) != sf::Socket::Done)
    {
        std::cout << "Erro ao conectar cliente" << std::endl;
        return;
    }

    std::cout << "Esperando conexão do player 2" << std::endl;
    if(listener.accept(player2) != sf::Socket::Done)
    {
        std::cout << "Erro ao conectar cliente" << std::endl;
        return;
    }

    std::cout << "Players conectados" << std::endl;
    notifyAll("Todos os players estão conectados");

    // Inicializando comunicação com os players e o jogo
    std::thread firstPlayer([this]() {
        this->playerListener(0);
    });

    std::thread secondPlayer([this]() {
        this->playerListener(1);
    });

    std::thread service([this]() {
        this->serviceThread();
    });

    // O loop principal do jogo
    firstPlayer.join();
    secondPlayer.join();
    service.join();
}


// Função para ouvir as mensagens dos clientes
void Server::playerListener(int player)
{
    const std::size_t size = 100;
    char data[size];
    std::size_t readSize;

    while(true)
    {
        if(( player ? player2 : player1 )
            .receive(data, size, readSize) != sf::Socket::Done)
        {
            std::cout << "Conexão perdida!" << std::endl;
            return;
        }

        std::string msg = std::string(data).substr(0, readSize);

        atualize(std::to_string(player) + ' ' + msg);
    }
}

void Server::notifyAll(std::string msg)
{
    player1.send(msg.c_str(), msg.length());
    player2.send(msg.c_str(), msg.length());
}

Server::~Server()
{
}