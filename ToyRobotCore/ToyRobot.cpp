#include "ToyRobot.h"
#include "Command.h"
#include "CommandRules.h"
#include "RobotPosition.h"
#include "DirectionRules.h"
#include "Constant.h"
#include "Common.h"
#include <string>
#include <iostream>

using namespace std;



void PrintStatus(string t_msg) {
    cout << t_msg << endl;
}

ToyRobotFallOffException ThrowToyRobotFallOffException() {    
    throw new ToyRobotFallOffException();
}


void PrintCommandExecutionStatus(const string& t_command, const CommandStatus& t_cmdstatus, const RobotPosition& t_curposition) {
    string message;
    switch (t_cmdstatus) {
    case CommandStatus::CmdStatusInvalid:
        message = "Command: " + t_command + " Output: " + INVALID_COMMAND_PRINT_MSG;
        PrintStatus(message);
        break;
    case CommandStatus::CmdStatusSuccess:
        if (t_command.compare(REPORT_COMMAND_PATTERN) == 0) {
            message = "Command: " + t_command + " Output: " + to_string(t_curposition.position.x) + ","
                + to_string(t_curposition.position.y) + ","
                + t_curposition.facing;
        }
        else
        {
            message = "Command: " + t_command;
        }
        
        PrintStatus(message);
        break;
    case CommandStatus::CmdStatusNoAction:
        message = "Command: " + t_command + " Output: " + NO_ACTION_COMMAND_PRINT_MSG;
        PrintStatus(message);
        break;
    case CommandStatus::CmdStatusOverflow:
        message = "Command: " + t_command + " Output: " + OVERFLOW_COMMAND_PRINT_MSG;
        PrintStatus(message);
        break;
    default:
        break;
    }
}

CommandStatus ToyRobot::ExecuteLeftCommand() {
    if (m_state != ToyRobotState::Placed) {
        return CommandStatus::CmdStatusNoAction;
    }
    string t_newDirection = DirectionRules::GetNextDirection(m_currentPosition.facing, CommandType::Left);
    m_currentPosition.facing = t_newDirection;
    return CommandStatus::CmdStatusSuccess;
}

CommandStatus ToyRobot::ExecuteRightCommand() {
    if (m_state != ToyRobotState::Placed) {
        return CommandStatus::CmdStatusNoAction;
    }
    string t_newDirection = DirectionRules::GetNextDirection(m_currentPosition.facing, CommandType::Right);
    m_currentPosition.facing = t_newDirection;
    return CommandStatus::CmdStatusSuccess;
}


CommandStatus ToyRobot::ExecuteMoveCommand() {
    if (m_state != ToyRobotState::Placed) {
        return CommandStatus::CmdStatusNoAction;
    }
    RobotPosition t_newPosition = DirectionRules::GetNextMovePosition(m_currentPosition);
    if (CommandRules::IsPositionWithinTableBoundary(t_newPosition)) {
        m_currentPosition = t_newPosition;
        return CommandStatus::CmdStatusSuccess;
    }
    else {
        return CommandStatus::CmdStatusOverflow;
    }
}


void ToyRobot::ExecuteCommand(const string& t_command) {
    Command o_cmd(t_command);
    o_cmd.m_type = CommandRules::GetCommandType(t_command);
    RobotPosition t_newPosition;
    switch (o_cmd.m_type) {
    case CommandType::Invalid:
        o_cmd.m_status = CommandStatus::CmdStatusInvalid;
        PrintCommandExecutionStatus(t_command, o_cmd.m_status, m_currentPosition);
        break;
    case CommandType::Place:
        o_cmd.m_status = ExecutePlaceCommand(t_command);
        PrintCommandExecutionStatus(t_command, o_cmd.m_status, m_currentPosition);
        break;
    case CommandType::Left:
        o_cmd.m_status = ExecuteLeftCommand();
        PrintCommandExecutionStatus(t_command, o_cmd.m_status, m_currentPosition);
        break;
    case CommandType::Right:
        o_cmd.m_status = ExecuteRightCommand();
        PrintCommandExecutionStatus(t_command, o_cmd.m_status, m_currentPosition);
        break;
    case CommandType::Move:
        o_cmd.m_status = ExecuteMoveCommand();
        PrintCommandExecutionStatus(t_command, o_cmd.m_status, m_currentPosition);
        break;
    case CommandType::Report:
        o_cmd.m_status = CommandStatus::CmdStatusSuccess;
        PrintCommandExecutionStatus(t_command, o_cmd.m_status, m_currentPosition);
        break;
    default:
        break;
    }
    
    /* 
        Note: In Windows, throwing ThrowToyRobotFallOffException by the shared library 
             is causing runtime exception. This exception generated at the shared library 
             is not propagating to the application.
    */
    if ( m_state == ToyRobotState::Placed &&  !CommandRules::IsPositionWithinTableBoundary(m_currentPosition)) {            
        throw ThrowToyRobotFallOffException();            
    }    
}


ToyRobot::ToyRobot() {
    m_state = ToyRobotState::NotPlaced;
    m_currentPosition.position.x = -1;
    m_currentPosition.position.y = -1;
    m_currentPosition.facing = "";
}

void ToyRobot :: operator=(const ToyRobot& ob) {
    m_currentPosition.position.x = ob.m_currentPosition.position.x;
    m_currentPosition.position.y = ob.m_currentPosition.position.y;
    m_currentPosition.facing = ob.m_currentPosition.facing;
}

bool operator== (const ToyRobot& ob1, const ToyRobot& ob2) {

    if(ob1.m_currentPosition.position.x == ob2.m_currentPosition.position.x 
        && ob1.m_currentPosition.position.y == ob2.m_currentPosition.position.y
        && ob1.m_currentPosition.facing.compare(ob2.m_currentPosition.facing)==0) {
        return true;
    }
    else {
        return false;
    }
}

ToyRobot::ToyRobot(const ToyRobot& ob) {
    m_currentPosition.position.x = ob.m_currentPosition.position.x;
    m_currentPosition.position.y = ob.m_currentPosition.position.y;
    m_currentPosition.facing = ob.m_currentPosition.facing;
}

RobotPosition ToyRobot::GetCurrentPosition() {
    return m_currentPosition;
}

CommandStatus ToyRobot::ExecutePlaceCommand(const string& cmdstr) {
    RobotPosition t_newPosition = CommandRules::ParsePlaceCommandAndGetNewPosition(cmdstr);
    if (CommandRules::IsPositionWithinTableBoundary(t_newPosition)) {
        m_currentPosition = t_newPosition;
        m_state = ToyRobotState::Placed;
        return CommandStatus::CmdStatusSuccess;
    }
    else
    {
        return CommandStatus::CmdStatusOverflow;
    }
}

ToyRobotState ToyRobot::GetCurrentState() {
    return m_state;
}

