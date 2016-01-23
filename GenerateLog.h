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