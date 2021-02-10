#include <iostream>
#include <fstream>
#include <vector>
#include "Common.h"
#include "Constant.h"
#include<string>
#include "ToyRobotTable.h"
#include "ToyRobot.h" 
#include "AppSettings.h"

using namespace std;

void ToyRobotTable::ReadCommands() {
    ifstream t_file;
    string t_line;
    try {
        string t_inputfile = ROBOT_COMMAND_INPUT_FILE_PATH;
        t_inputfile += ROBOT_COMMAND_INPUT_FILE_NAME;
        t_file.open(t_inputfile);
        while (!t_file.eof()) {
            t_line = "";
            t_line = Common::trim(t_line);
            getline(t_file, t_line);
            m_commands.push_back(t_line);
        }
    }
    catch (const ifstream::failure& e) {
        cout << "Exception opening/reading command file " << e.what();
    }
    catch (exception& e) {
        cout << "Exception" << e.what();
    }

}

void ToyRobotTable::play()
{
    ReadCommands();
    for (string& command : m_commands) {
        command = Common::trim(command);
        m_toyRobot.ExecuteCommand(command);
    }
}
