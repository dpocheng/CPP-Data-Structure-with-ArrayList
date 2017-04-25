#include <iostream>
#include <string>
#include "ArrayList.hpp"

int main()
{
    ArrayList<std::string> studentArray;
    std::cout << "Please enter 10 students ID and their names:" << std::endl;
    while(studentArray.size() < 10)
    {
        std::string userInput;
        std::getline(std::cin, userInput);
        studentArray.add(userInput);
    };
    for (int i = 0; i < studentArray.size(); i++)
    {
        std::string studentString = studentArray.at(i);
        std::string studentID = studentString.substr(0, studentString.find(' '));
        std::string name = studentString.substr(studentString.find(' ') + 1);
        std::cout << name << " (ID#" << studentID << ")" << std::endl;
    }
    return 0;
}

