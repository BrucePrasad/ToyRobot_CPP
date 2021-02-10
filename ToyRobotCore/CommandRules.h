//#pragma once
#ifndef COMMANDRULES_H
#define COMMANDRULES_H
#include <string.h>
#include "Constant.h"
#include "Command.h"
#include "RobotPosition.h"

static class CommandRules {
public:
    static CommandType  GetCommandType(const string& command);
    static bool IsValidPlaceCommand(const string& command);
    static bool IsValidMoveCommand(const string& command);
    static bool IsValidLeftCommand(const string& command);
    static bool IsValidRightCommand(const string& command);
    static bool IsValidReportCommand(const string& command);
    static bool IsPositionWithinTableBoundary(const RobotPosition& newPosition);
    static RobotPosition ParsePlaceCommandAndGetNewPosition(const string& t_cmdstr);
};
#endif
