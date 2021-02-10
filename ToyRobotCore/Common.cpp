#include <string>
#include "Common.h"
#include "Constant.h"

std::string& Common::ltrim(std::string& str)
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

std::string& Common::rtrim(std::string& str)
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}

std::string& Common::trim(std::string& str)
{
    return ltrim(rtrim(str));
}

void Common::Display1() {

}


