#pragma once
 
#include <string>
using namespace std;

struct Point
{
public:
    int x;
    int y;
};
class RobotPosition {
private:
public:
    Point position;
    string facing;
    //ToyRobotPosition& operator=(const ToyRobotPosition& rhs);
    void operator=(const RobotPosition& rhs);
    string ToString();
};

