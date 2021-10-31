#pragma once
#include <iostream>

extern void splitStrByDelimeter(std::string str, char delimeter, std::string arr[]);
extern std::string removeFinalCharOfType(std::string str, char delimeter);
extern std::string removeParameters(std::string str);
extern std::string removeChar(std::string str, char del);
std::string removeFirstCharOfType(std::string str, char delimeter);
