
#ifndef COMMON_H
#define COMMON_H
#include <string>
#include <exception>
static class Common {
public:
	static void Display1();
	static std::string& ltrim(std::string& str);
	static std::string& rtrim(std::string& str);
	static std::string& trim(std::string& str);
};

class ToyRobotFallOffException: std::exception{
public:
   const char* what() const throw()  override
    {
        return "Toy Robot fall off the table\n";
    }
};
#endif