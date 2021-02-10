// 
// ToyRobotTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<vector>

#include "Common.h"
#include "CommandRules.h"
#include "TestCases.h"
using namespace std;


void CheckValidPlaceCommand(const string& t_strcmd) {
    if (ASSERT_VALID_PLACE_COMMAND(t_strcmd) == true)
        std::cout << t_strcmd << endl << " Test Case[CheckValidCommand][Success]" << endl;
    else
        std::cout << t_strcmd << endl<< " Test Case[CheckValidCommand][Failed]" << endl;
}

void CheckValidCommand(const string& t_strcmd) {
    if (ASSERT_VALID_COMMAND(t_strcmd) == true)
        std::cout << t_strcmd << endl<< " Test Case[CheckValidCommand][Success]" << endl;
    else
        std::cout << t_strcmd << endl<< " Test Case[CheckValidCommand][Failed]" << endl;
}


void CheckIgnoredAllNonPlaceCommands(vector<string>& t_commandlist) {   
    if (ASSERT_IGNORE_ALL_NON_PLACE_COMMANDS_BEFORE_FIRST_PLACE_COMMAND(t_commandlist) == true) {
        std::cout <<  " Test Case[CheckNoFallOffToyRobot][Success]" << endl;
    }
    else {
        std::cout << " Test Case[CheckNoFallOffToyRobot][Failed]" << endl;
    }
}

void CheckNoFallOffToyRobot(vector<string>& t_commandlist) {
    if (ASSERT_NO_FALL_OFF_TOY_ROBOT(t_commandlist) == true) {
        std::cout << " Test Case[CheckNoFallOffToyRobot][Success]" << endl;
    }
    else {
        std::cout << " Test Case[CheckNoFallOffToyRobot][Failed]" << endl;
    }
    
}

void CheckToyRobotFacing(vector<string>& t_commandlist, string t_strcmd) {
    
    if (ASSERT_FACING_DIRECTION(t_commandlist, (string) t_strcmd) == true) {
        std::cout << " Test Case[CheckToyRobotFacingToy][Success]"   << endl;
    }
    else {
        std::cout << " Test Case[CheckToyRobotFacingToy][Failed]"   << endl;
    }

}
 
int main()
{   
    cout << "###################Test Case 1 #################"<<endl<<endl;
    string t_strcmd_1 = "PLACE 0,0,NORTH";
    CheckValidPlaceCommand(t_strcmd_1);
    cout << endl << endl;

    cout << "###################Test Case 2 #################" << endl << endl;
    string t_strcmd_2 = "PLACE 0,6,NORTH";
    CheckValidPlaceCommand(t_strcmd_2);
    cout << endl << endl;
    

    cout << "###################Test Case 3 #################" << endl << endl;
    string t_strcmd_3 = "move";
    CheckValidCommand(t_strcmd_3);
    cout << endl << endl;

    cout << "###################Test Case 4 #################" << endl << endl;
    string t_strcmd_4 = "MOVE";
    CheckValidCommand(t_strcmd_4);
    cout << endl << endl;

    cout << "###################Test Case 5 #################" << endl << endl;
    vector<string> t_commandlist_1 = { "MOVE", "LEFT", "RIGHT" };
    CheckIgnoredAllNonPlaceCommands(t_commandlist_1);
    cout << endl << endl;

    cout << "###################Test Case 6 #################" << endl << endl;
    vector<string> t_commandlist_2 = { "MOVE", "LEFT","PLACE 3,1,EAST", "RIGHT" };
    CheckIgnoredAllNonPlaceCommands(t_commandlist_1);
    cout << endl << endl;

    
    cout << "###################Test Case 7 #################" << endl << endl;
    vector<string> t_commandlist_3 = { "PLACE 3,3,EAST", "MOVE", "LEFT", "LEFT","LEFT", "LEFT", "REPORT"};
    CheckToyRobotFacing(t_commandlist_3, "EAST");
    cout << endl << endl;
    
    cout << "###################Test Case 8 #################" << endl << endl;
    vector<string> t_commandlist_4 = { "PLACE 3,3,EAST", "MOVE", "MOVE", "MOVE", "MOVE" };
    CheckNoFallOffToyRobot(t_commandlist_3);
    cout << endl << endl;

    cout << "###################Test Case 9 #################" << endl << endl;
    vector<string> t_commandlist_5 = { "PLACE 1,2,EAST", "RIGHT", "RIGHT", "MOVE", "MOVE", "MOVE", "REPORT" };
    CheckNoFallOffToyRobot(t_commandlist_5);
    cout << endl << endl;



    std::cin.get();
}

 