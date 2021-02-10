#pragma once
#include <string>
#include "Constant.h"
using namespace std;
class Command {
public:
    string m_cmdstr;
    CommandType m_type;
    CommandStatus m_status;
    Command(string m_cmdstr) { this->m_cmdstr = m_cmdstr; this->m_type = CommandType::Invalid; }
};