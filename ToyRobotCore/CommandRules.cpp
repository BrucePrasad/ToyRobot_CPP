#include "Constant.h"
#include "CommandRules.h"
#include <regex>

CommandType CommandRules::GetCommandType(const string& cmd) {
    if (IsValidPlaceCommand(cmd)) {
        return CommandType::Place;
    }
    else if (IsValidMoveCommand(cmd)) {
        return CommandType::Move;
    }
    else if (IsValidLeftCommand(cmd)) {
        return CommandType::Left;
    }
    else if (IsValidRightCommand(cmd)) {
        return CommandType::Right;
    }
    else if (IsValidReportCommand(cmd)) {
        return CommandType::Report;
    }
    else {
        return CommandType::Invalid;
    }
}

bool CommandRules::IsValidPlaceCommand(const string& command) {
    if (regex_match(command, regex(PLACE_COMMAND_PATTERN)))
        return true;
    else
        return false;
}
bool CommandRules::IsValidMoveCommand(const string& command) {
    if (regex_match(command, regex(MOVE_COMMAND_PATTERN)))
        return true;
    else
        return false;
}

bool CommandRules::IsValidLeftCommand(const string& command) {
    if (regex_match(command, regex(LEFT_COMMAND_PATTERN)))
        return true;
    else
        return false;
}
bool CommandRules::IsValidRightCommand(const string& command) {
    if (regex_match(command, regex(RIGHT_COMMAND_PATTERN)))
        return true;
    else
        return false;
}

bool CommandRules::IsValidReportCommand(const string& command) {
    if (regex_match(command, regex(REPORT_COMMAND_PATTERN)))
        return true;
    else
        return false;
}




bool CommandRules::IsPositionWithinTableBoundary(const RobotPosition& newPosition) {
    if (newPosition.position.x >= 0 &&
        newPosition.position.y >= 0 &&
        newPosition.position.x <= MAX_TABLE_LENGTH &&
        newPosition.position.y <= MAX_TABLE_BREADTH)
        return true;
    else
        return false;
}

RobotPosition CommandRules::ParsePlaceCommandAndGetNewPosition(const string& t_cmdstr) {
    char c_spacedelimiter = ' ';
    const char* cp_comadelimiter = ",";
    string strcmd = t_cmdstr;
    string t_cmdstrpart = strcmd.substr(strcmd.find(c_spacedelimiter) + 1, strcmd.length());
    char* p_cmdpart = &t_cmdstrpart[0];
    char* cp_token;
    RobotPosition toyRobotPosition;
    cp_token = strtok_s(p_cmdpart, cp_comadelimiter, &p_cmdpart);
    toyRobotPosition.position.x = atoi(cp_token);
    cp_token = strtok_s(p_cmdpart, cp_comadelimiter, &p_cmdpart);
    toyRobotPosition.position.y = atoi(cp_token);
    cp_token = strtok_s(p_cmdpart, cp_comadelimiter, &p_cmdpart);
    toyRobotPosition.facing = string(cp_token);
    return toyRobotPosition;
}
