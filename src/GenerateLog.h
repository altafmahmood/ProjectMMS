//Copyright (c)
//Authors     : Altaf Mahmood
//Date        : 21 Jan 2016
//Time        : 12:20
//Purpose     : Program to Generate Log file and to rotate it

#include<fstream>
#include<string>

class GenerateLog{
  private:
    std::ofstream outFile;
    std::ifstream inpFile;
    std::string fileName[100];

  public:
    GenerateLog();
    void Log();
    char* generateName();
    void displayName();
};
