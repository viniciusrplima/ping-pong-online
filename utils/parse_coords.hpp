/*
    parse_coords.hpp
*/

#include "game_state.hpp"

#ifndef _PARSE_COORDS_HPP_
#define _PARSE_COORDS_HPP_


float toRenderXCoord(float x)
{
    return 2.0f * x / WINDOW_WIDTH - 1.0f;
}

float toRenderYCoord(float y)
{
    return 2.0f * y / WINDOW_HEIGHT;
}

float reflectAngleInX(float angle)
{
    return M_PI - angle;
}

float reflectAngleInY(float angle)
{
    return -angle;
}

float calcAngleMove(float offset)
{
    return M_PI * offset * ANGLE_DETOUR_COEF;
}

#endif