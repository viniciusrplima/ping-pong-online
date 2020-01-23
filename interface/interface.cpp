/*
    interface.cpp
*/

Interface::Interface()
{
}

void Interface::init()
{
    resetGame();

    Client::init();
}

void Interface::resetGame()
{
    gameState.p1Pos = 0.0f;
    gameState.p2Pos = 0.0f;
    gameState.ballPos = glm::vec2(0.0f, 0.0f);
    gameState.score = glm::vec2(0.0f, 0.0f);
}

void Interface::interfaceThread()
{
    /*std::string title = "Ping Pong Online - " + 
            socket.getRemoteAddress().toString() + ':' +
            std::to_string(socket.getRemotePort());*/

    //glutSetWindowTitle(title.c_str());

    glutMainLoop();
}

void Interface::render()
{
    glClearColor(0.1f, 0.1f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT bitor GL_DEPTH_BUFFER_BIT);

    renderTable(PLAYER1_XPOS, gameState.p1Pos);
    renderTable(PLAYER2_XPOS, gameState.p2Pos);
    renderBall(gameState.ballPos.x, gameState.ballPos.y);
    renderScore();

    glutSwapBuffers();
    glutPostRedisplay();
}

void Interface::renderTable(float x, float y)
{
    float halfHeight = TABLE_HEIGHT / WINDOW_HEIGHT;
    float width = 2.0f * TABLE_WIDTH / WINDOW_WIDTH;

    x = toRenderXCoord(x);
    y = toRenderYCoord(y);

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.6f, 0.0f);

    glBegin(GL_POLYGON);

    glVertex2f(x, y + halfHeight);
    glVertex2f(x, y - halfHeight);
    glVertex2f(x + width, y - halfHeight);
    glVertex2f(x + width, y + halfHeight);

    glEnd();
}

void Interface::renderBall(float x, float y)
{
    glLineWidth(2.0f);
    glColor3f(0.0f, 0.6f, 0.0f);

    x = toRenderXCoord(x);
    y = toRenderYCoord(y);
    float radius = 2.0f * BALL_RADIUS / WINDOW_WIDTH;

    glBegin(GL_POLYGON);

    for(float theta = 0.0f; theta < 2 * 3.15149f; theta += 0.2)
    {
        glVertex2f(x + radius * std::cos(theta), y + radius * std::sin(theta));
    }

    glEnd();
}

void Interface::renderScore()
{
    std::string scoreP1 = std::to_string((int)gameState.score.x);
    std::string scoreP2 = std::to_string((int)gameState.score.y);

    std::string strScore = scoreP1 + " x " + scoreP2;
    float strWidth = 0.0f;

    for(int i = 0; i < strScore.size(); i++)
        strWidth += glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24, strScore[i]);
    
    strWidth = 2.0f * strWidth / WINDOW_WIDTH;

    glRasterPos2d(-strWidth/2, 0.90f);

    for(int i = 0; i < strScore.size(); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, strScore[i]);
}

void Interface::keyboardHandle(int key)
{
    switch(key)
    {
        case GLUT_KEY_UP: {
            send("up");
            break;
        }
        case GLUT_KEY_DOWN: {
            send("down");
            break;
        }
    }
}

void Interface::actualize(std::string msg)
{
    parseStringToGame(msg, &(this->gameState));
}

Interface::~Interface()
{
}