/*
    Game.cpp
*/

Game::Game()
{
}

void Game::init(unsigned int port)
{
    resetGame();

    Server::init(port);

}

void Game::resetGame()
{
    gameState.p1Pos = 0.0f;
    gameState.p2Pos = 0.0f;
    gameState.ballPos = glm::vec2(WINDOW_WIDTH/2, 0.0f);
    gameState.score = glm::vec2(0.0f, 0.0f);

    ballAngle = 0.6f;
}

void Game::initGame()
{
    actualizeClients();
    while(true)
    {
        updateGame();
    }
}

void Game::actualizeClients()
{
    notifyAll(parseGameToString(gameState));
}

void Game::movePlayer(int player, std::string action)
{
    float &pos = (player ? gameState.p2Pos : gameState.p1Pos);

    if(action == "up")
    {
        pos += PLAYER_SPEED;
    }
    else if(action == "down")
    {
        pos -= PLAYER_SPEED;
    }

    if(pos > MAX_MOVEMENT)
        pos = MAX_MOVEMENT;

    if(pos < -MAX_MOVEMENT)
        pos = -MAX_MOVEMENT;
    
}

void Game::updateGame()
{
    float elapsed = 1.0f / FRAMES_PER_SECOND;
    sf::sleep(sf::seconds(elapsed));

    updateBall(elapsed);
    updateCollision();

    actualizeClients();
}

void Game::updateBall(float elapsed)
{
    gameState.ballPos.x += BALL_SPEED * std::cos(ballAngle) * elapsed;
    gameState.ballPos.y += BALL_SPEED * std::sin(ballAngle) * elapsed;
}

void Game::updateCollision()
{
    // TABLES COLLISIONS

    if(isTableCollision(PLAYER1_XPOS, gameState.p1Pos))
    {
        ballAngle = reflectAngleInX(ballAngle);
        ballAngle += calcAngleMove(gameState.p1Pos - gameState.ballPos.y);
        adjustBallPosition(PLAYER1_XPOS, 0);
    }

    if(isTableCollision(PLAYER2_XPOS, gameState.p2Pos))
    {
        ballAngle = reflectAngleInX(ballAngle);
        ballAngle += calcAngleMove(gameState.p2Pos - gameState.ballPos.y);
        adjustBallPosition(PLAYER2_XPOS, 1);
    }


    // BOARD COLLISIONS

    if(gameState.ballPos.x <= BALL_RADIUS)
    {
        gameState.score.y += 1;
        ballAngle = reflectAngleInX(ballAngle);
        gameState.ballPos.x = BALL_RADIUS;
    }

    if(gameState.ballPos.x >= WINDOW_WIDTH - BALL_RADIUS)
    {
        gameState.score.x += 1;
        ballAngle = reflectAngleInX(ballAngle);
        gameState.ballPos.x = WINDOW_WIDTH - BALL_RADIUS;
    }

    if(gameState.ballPos.y >= WINDOW_HEIGHT/2 - BALL_RADIUS)
    {
        ballAngle = reflectAngleInY(ballAngle);
        gameState.ballPos.y = WINDOW_HEIGHT/2 - BALL_RADIUS;
    }
 
    if(gameState.ballPos.y <= -WINDOW_HEIGHT/2 + BALL_RADIUS)
    {
        ballAngle = reflectAngleInY(ballAngle);
        gameState.ballPos.y = -WINDOW_HEIGHT/2 + BALL_RADIUS;
    }
}

bool Game::isTableCollision(float x, float y)
{

    /*  TABLE POSITION
 
       <-> table width
        
       | |
       | |
       | |
       | |
       | |   <- Y       
       | |
       | |
       | |
       | |

       ^
       X

    */

    x += TABLE_WIDTH / 2;

    return std::abs(x - gameState.ballPos.x) < BALL_RADIUS + TABLE_WIDTH/2 and 
            gameState.ballPos.y < y + TABLE_HEIGHT / 2 and 
            gameState.ballPos.y > y - TABLE_HEIGHT / 2;
}

// Ajusta a posição da bola quando há colisão com as tabelas
void Game::adjustBallPosition(float xTable, int player)
{
    if(player == 1)
    {
        gameState.ballPos.x = xTable - BALL_RADIUS;
    }
    else
    {
        gameState.ballPos.x = xTable + BALL_RADIUS + TABLE_WIDTH;
    }
    
}

void Game::serviceThread()
{
    initGame();
}

void Game::atualize(std::string msg)
{
    auto commands = tokenize(msg);

    if(commands.size() != 2)
        return;

    int player = atoi(commands[0].c_str());
    std::string action = commands[1];

    movePlayer(player, action);
    actualizeClients();
}


Game::~Game()
{
}