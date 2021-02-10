//#pragma once
#ifndef TOYROBOTTABLE_H
#define TOYROBOTTABLE_H
#include <vector>
#include <string>
#include "ToyRobot.h"
using namespace std;

class ToyRobotTable {
private:
    vector<string> m_commands;
    ToyRobot m_toyRobot;
    void ReadCommands();
public:
    ToyRobotTable() {}
    void play();
};
#endif
