#pragma once
#include "RobotPosition.h"
#include "Command.h"
#include "Constant.h"
class ToyRobot {
private:
    RobotPosition m_currentPosition;
    ToyRobotState m_state;
public:
    ToyRobot();
    void ExecuteCommand(const string& command);
    CommandStatus ExecutePlaceCommand(const string& cmdstr);
    CommandStatus ExecuteLeftCommand();
    CommandStatus ExecuteRightCommand();
    CommandStatus ExecuteMoveCommand();
    ToyRobotState GetCurrentState();
    RobotPosition GetCurrentPosition();
    void operator=(const ToyRobot& ob);
    ToyRobot(const ToyRobot& ob);
    friend bool operator== (const ToyRobot& ob1, const ToyRobot& ob2);

};
