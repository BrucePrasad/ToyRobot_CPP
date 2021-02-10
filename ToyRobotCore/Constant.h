
#ifndef CONSTANTS_H
#define CONSTANTS_H

#define MAX_TABLE_LENGTH	5
#define MAX_TABLE_BREADTH	5
#define PLACE_COMMAND_PATTERN "(PLACE)( )([0-5]{1})(,)([0-5]{1})(,)(NORTH|SOUTH|EAST|WEST)"
#define MOVE_COMMAND_PATTERN  "MOVE"
#define LEFT_COMMAND_PATTERN  "LEFT"
#define RIGHT_COMMAND_PATTERN  "RIGHT"
#define REPORT_COMMAND_PATTERN  "REPORT"

#define EAST_FACING "EAST"
#define WEST_FACING "WEST"
#define NORTH_FACING "NORTH"
#define SOUTH_FACING "SOUTH"

//
//const char* const ROBOT_COMMAND_INPUT_FILE_PATH = "P:\\";
//const char* const ROBOT_COMMAND_INPUT_FILE_NAME = "commands.txt";
const char* const chars = "\t\n\v\f\r ";
enum CommandType { Invalid = 1, Place, Left, Right, Move, Report };
enum ToyRobotState { NotPlaced = 1, Placed, Fallen };
enum CommandStatus { CmdStatusSuccess = 1, CmdStatusNoAction, CmdStatusOverflow, CmdStatusInvalid };
//#define STR_HELPER(x) #x//#define STR(x) STR_HELPER(x)
//#define SUCCESS_COMMAND_PRINT_MSG(X,Y,FACING)  PrintOutput(X,Y,FACING) "Output: "  ## #X  ## "," ## #Y ## ","## FACING
#define INVALID_COMMAND_PRINT_MSG               "Invalid command."
#define NO_ACTION_COMMAND_PRINT_MSG             "Command is not actioned, no valid PLACE command"
#define OVERFLOW_COMMAND_PRINT_MSG              "Command is not actioned, ToyRobot table overflow"

#endif


