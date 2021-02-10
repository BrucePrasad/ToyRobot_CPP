#include <string>
#include <vector>
#include <iostream>
#include "ToyRobot.h"
#include "CommandRules.h"
#include "Common.h"

using namespace std;

/*
    Purpose - Validate format of place command
    Input -  Place command in string format
    Output - Return true if format of the input is valid place command.
             Otherwise return false
             Valid place command format - PLACE <X>,<Y>,<F>
             where <X> = 0-5, <Y>= 0-5, <F>= EAST|WEST|NORTH|SOUTH
*/
bool ASSERT_VALID_PLACE_COMMAND(const string& t_strcmd) {
    CommandRules rules;
    return rules.IsValidPlaceCommand(t_strcmd);
}

/*
    Purpose - Validate format of PLACE,MOVE,LEFT,RIGHT or REPORT
    Input -  PLACE,MOVE,LEFT,RIGHT or REPORT command in string format
    Output - Return true if format of the input is valid PLACE,MOVE,LEFT,RIGHT or REPORT command.
             Otherwise return false.
             Valid place command format - PLACE <X>,<Y>,<F>
             where <X> = 0-5, <Y>= 0-5, <F>= EAST|WEST|NORTH|SOUTH
             Valid place command format - MOVE
             Valid place command format - LEFT
             Valid place command format - RIGHT
             Valid place command format - REPORT
*/
bool ASSERT_VALID_COMMAND(const string& t_strcmd) {
    CommandRules rules;
    if (rules.GetCommandType(t_strcmd) == CommandType::Invalid) {
        return false;
    }
    else {
        return true;
    }
}


 

/*
*   Purpose - Ignore any commands before execution of PLACE command
    Input -  List of commands
    Output - Return true if all commands are ignored
             Otherwise return false.
*/

bool ASSERT_IGNORE_ALL_NON_PLACE_COMMANDS_BEFORE_FIRST_PLACE_COMMAND(vector<string>& t_commandlist) {

    ToyRobot t_toyRobot;
    ToyRobot temp_t_toyRobot = t_toyRobot;

    for (string& command : t_commandlist) {
        try {
            if (!CommandRules::IsValidPlaceCommand(command)) {
                t_toyRobot.ExecuteCommand(command);
            }                
        }
        catch (const std::exception& e) {           
            return "false";
        }
    }
    if (t_toyRobot == temp_t_toyRobot) {
        return true;
    }
    else {
        return false;
    }
}


/*
*   Purpose - Verify that the facing direction
    Input -  Paramter 1: List of commands with a valid PLACE command followed by any number of commands
             Paramter 2: Expected facing direction in capital letter
    Output - Return true if the expected facing direction and current toyrobot direction are equal
             Otherwise return false.
*/

bool ASSERT_FACING_DIRECTION(vector<string>& t_commandlist, string t_expectedfacing) {
    ToyRobot t_toyRobot;
    for (string& command : t_commandlist) {
        try {
            t_toyRobot.ExecuteCommand(command);
        }
        catch (ToyRobotFallOffException& e) {            
            return "false";
        }
        catch (const std::exception& e) {
            //cout << "Exception " << e.what() << endl;
            return "false";
        }
    }
    for (auto& s : t_expectedfacing) s = toupper(s);
    //cout << t_expectedfacing;
    if (t_toyRobot.GetCurrentPosition().facing == t_expectedfacing) {
        return true;
    }
    else {
        return false;
    }
}




/*
*   Purpose - Ignore commands which tries to fall off the toy robot from the table
    Input -  List of commands with a valid PLACE command followed by any command
             tries to move the toy robot outside the table
    Output - Return true if toy robot is not fallen
             Otherwise return false.
*/

bool ASSERT_NO_FALL_OFF_TOY_ROBOT(vector<string>& t_commandlist) {
    ToyRobot t_toyRobot;
    for (string& command : t_commandlist) {
        try {
            t_toyRobot.ExecuteCommand(command);
        }
        catch (ToyRobotFallOffException& e) {
            cout << "Toy Robot fell off the table" << e.what() << endl;
            return "false";
        }
        catch (const std::exception& e) {
            cout << "Exception " << e.what() << endl;
            return "false";
        }
    }
    return true;
}


