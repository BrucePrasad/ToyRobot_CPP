#include "RobotPosition.h"



void RobotPosition :: operator=(const RobotPosition& rhs) {
    position.x = rhs.position.x;
    position.y = rhs.position.y;
    facing = rhs.facing;

}

string RobotPosition::ToString() {
    return   to_string(position.x) + "," + to_string(position.y) + ", " + facing;
}