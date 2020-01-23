/*
    parseGameState.hpp
*/

#include <string>
#include <vector>
#include "game_state.hpp"

#ifndef _PARSE_GAME_STATE_HPP_
#define _PARSE_GAME_STATE_HPP_

std::vector<std::string> tokenize(std::string str)
{
    std::vector<std::string> tokens;
    std::string token = "";

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == ' ')
        {
            if(token != "")
            {
                tokens.push_back(token);
                token = "";
            }
        }
        else
        {
            token += str[i];
        }
    }

    if(token != "")
        tokens.push_back(token);

    return tokens;
}

std::string parseGameToString(GameState state)
{
    std::string strState = "";

    strState += std::to_string(state.p1Pos) + ' ';
    strState += std::to_string(state.p2Pos) + ' ';
    strState += std::to_string(state.ballPos.x) + ' ';
    strState += std::to_string(state.ballPos.y) + ' ';
    strState += std::to_string(state.score.x) + ' ';
    strState += std::to_string(state.score.y) + ' ';

    return strState;
}

void parseStringToGame(std::string str, GameState *state)
{
    std::vector<std::string> stateTokens = tokenize(str);

    if(stateTokens.size() != GAME_STATE_PROPERTIES)
        return;

    state->p1Pos = atof(stateTokens[0].c_str());
    state->p2Pos = atof(stateTokens[1].c_str());
    state->ballPos = glm::vec2(atof(stateTokens[2].c_str()), atof(stateTokens[3].c_str()));
    state->score = glm::vec2(atof(stateTokens[4].c_str()), atof(stateTokens[5].c_str()));
}

#endif