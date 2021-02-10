#ifndef DIRECTIONRULES_H
#define DIRECTIONRULES_H

#include<vector>
#include<string>
#include "Constant.h"
#include "RobotPosition.h"

using namespace std;

static class DirectionRules {
public:
    static vector<string> directions;
    static string GetNextDirection(const string& currentDirection, CommandType cmdType);
    static RobotPosition GetNextMovePosition(const RobotPosition& currentToyRobotPosition);
};
#endif