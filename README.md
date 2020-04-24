# Ping Pong Online

Jogo multiplayer de ping pong utilizando C++, OpenGL e SFML.

### Dependências

Para que o jogo compile corretamente é necessário instalar as seguintes dependências.
```
sudo apt install libsfml-dev
```

### Compilação

Para recompilar execute o shellscript nos diretórios dos executáveis.
```
./comp.sh
```
Talvez seja necessário instalar as bibliotecas e libs do SFML.

### Inicialização

Para rodar o jogo é necessário primeiro executar o servidor do jogo no teminal fornecendo a porta na qual o servidor vai atuar.
O servidor irá esperar até que os jogadores se conectem.

```
./ping-pong <port>
```

Depois disso, execute duas instâncias dos clientes, sendo elas no mesmo computador ou em computadores diferentes, desde que 
estejam conectados à mesma rede. Deve indicar o endereço ip e a porta em que o servidor está agindo:

```
cd interface
./pp-client <ip adress> <port>
```
Se for executar o cliente localmente execute:
```
./pp-client localhost <port>
```
Para saber o ip da máquina em que o servidor está rodando execute:
No Linux:
```
ifconfig
```
No Windows
```
ipconfig
```
