#pragma once
#include <string>
using namespace std;

bool ASSERT_VALID_PLACE_COMMAND(const string& t_strcmd);
bool ASSERT_VALID_COMMAND(const string& t_strcmd);
bool ASSERT_IGNORE_ALL_NON_PLACE_COMMANDS_BEFORE_FIRST_PLACE_COMMAND(vector<string>& t_commandlist);
bool ASSERT_FACING_DIRECTION(vector<string>& t_commandlist, string t_expectedfacing);
bool ASSERT_NO_FALL_OFF_TOY_ROBOT(vector<string>& t_commandlist);