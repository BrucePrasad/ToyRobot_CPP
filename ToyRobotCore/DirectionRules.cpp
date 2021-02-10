#include "DirectionRules.h"
#include "Constant.h"

vector<string> DirectionRules::directions = { NORTH_FACING, EAST_FACING,SOUTH_FACING, WEST_FACING };


string DirectionRules::GetNextDirection(const string& currentDirection, CommandType cmdType) {
    vector<string>::iterator it = find(directions.begin(), directions.end(), currentDirection);
    if (cmdType == CommandType::Left) {
        if (it == directions.begin())
            it = directions.end() - 1;
        else
            it--;
    }
    else if (cmdType == CommandType::Right) {
        if (it == directions.end() - 1)
            it = directions.begin();
        else
            it++;
    }
    return *it;
}

RobotPosition DirectionRules::GetNextMovePosition(const RobotPosition& currentPosition) {
    RobotPosition nextPosition = currentPosition;
    if (currentPosition.facing == EAST_FACING) {
        nextPosition.position.x = currentPosition.position.x + 1;
    }
    else if (currentPosition.facing == WEST_FACING) {
        nextPosition.position.x = currentPosition.position.x - 1;
    }
    else if (currentPosition.facing == NORTH_FACING) {
        nextPosition.position.y = currentPosition.position.y + 1;
    }
    else if (currentPosition.facing == SOUTH_FACING) {
        nextPosition.position.y = currentPosition.position.y - 1;
    }
    return nextPosition;
}