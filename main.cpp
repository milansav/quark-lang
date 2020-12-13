#include <iostream>
#include <vector>

uint8_t parseCommand(std::string line)
{
    std::string temp = "";
    std::vector<std::string> arguments;
    for(uint16_t i = 0; i < line.size(); i++)
    {
        if(isspace(line[i]))
        {
            arguments.push_back(temp);
            temp = "";
        }
    }
}

int main()
{
    std::string line = "";
    while(line != "END")
    {
        std::getline(std::cin, line);
    }
    return 0;
}