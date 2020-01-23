/*
    game_state.hpp
*/

#include <glm/glm.hpp>

#ifndef _GAME_STATE_H_
#define _GAME_STATE_H_

static const float WINDOW_WIDTH = 600.0f;
static const float WINDOW_HEIGHT = 600.0f;
static const float FRAMES_PER_SECOND = 30.0f;
static const float TABLE_WIDTH = 10.0f;
static const float TABLE_HEIGHT = 200.0f;
static const float PLAYER_SPEED = 15.0f;
static const float PLAYER1_XPOS = 0.0f;
static const float PLAYER2_XPOS = WINDOW_WIDTH - TABLE_WIDTH;
static const float BALL_SPEED = 350.0f;
static const float BALL_RADIUS = 15.0f;
static const float ANGLE_DETOUR_COEF = 0.002f;
static const float HALF_TABLE_RENDER_HEIGHT = TABLE_HEIGHT / WINDOW_HEIGHT;
static const float MAX_MOVEMENT = WINDOW_HEIGHT / 2 - TABLE_HEIGHT / 2;
static const int GAME_STATE_PROPERTIES = 6;

struct GameState
{
    float p1Pos;
    float p2Pos;
    glm::vec2 ballPos;
    glm::vec2 score;
};

#endif
