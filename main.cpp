#include <iostream>
#include <vector>

uint8_t parseCommand(std::string line)
{
    std::string temp = "";
    std::vector<std::string> arguments;
    //Split line into arguments
    for(uint16_t i = 0; i < line.size(); i++)
    {
        if(isspace(line[i]))
        {
            arguments.push_back(temp);
            temp = "";
        }
    }
    arguments.push_back(temp);


}

std::vector<std::string> parseInput(std::string line)
{
    std::string temp = "";
    std::vector<std::string> arguments;
    //Split line into arguments
    for(uint16_t i = 0; i < line.size(); i++)
    {
        if(isspace(line[i]))
        {
            arguments.push_back(temp);
            temp = "";
        }
    }
    arguments.push_back(temp);

    return arguments;
}

enum EXPRESSION_TYPE
{
    LITERAL,
    POINTER
};

int main()
{
    std::string line = "";
    while(line != "END")
    {
        std::getline(std::cin, line);
        std::vector<std::string> args = parseInput(line);
    }
    return 0;
}

void performAction(std::vector<std::string> arguments) //its bad but it does the job for now
{
    std::string first = arguments[0];

    if(first == "LOAD");
    else
    if(first == "REMEMBER");
    else
    if(first == "PRINT");
    else
    if(first == "SUM");
    else
    if(first == "SUBTRACT");
    else
    if(first == "MULTIPLY");
    else
    if(first == "DIVIDE");    
}