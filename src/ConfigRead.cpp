#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <cstring>
#include <cstdlib>
#include "ConfigRead.h"

using namespace std;

ConfigRead::ConfigRead(){
    poolFile = new char(11);
    logFile = new char(10);
    strcpy(poolFile,".pool.conf");
    strcpy(logFile,".log.conf");
}

int ConfigRead::getPoolSize(){
    return poolSize;
}

int ConfigRead::getNPool(){
    return nPools;
}

int ConfigRead::getLogFileSize(){
    return logFileSize;
}

int ConfigRead::getNLogFile(){
    return nLogFiles;
}

int ConfigRead::assignData(){
    int num1, num2;

    int sa = fileRead(logFile, num1, num2);
    nLogFiles = num1;
    logFileSize = num2;

    int sb = fileRead(poolFile, num1, num2);
    nPools = num1;
    poolSize = num2;

    if(sa==0 && sb==0){
      return 0;
    }else{
      return 1;
    }

}

int ConfigRead::fileRead(char* file, int& n1, int& n2){
    ifstream inpfile;
    inpfile.open(file);
    string str;
    char ch;

    if(inpfile.is_open()){
        while(inpfile.get(ch)){
            if(ch == '='){
                getline(inpfile,str);
                istringstream iss(str);
                iss >> n1;
                break;
            }
        }
        while(inpfile.get(ch)){
            if(ch == '='){
                getline(inpfile,str);
                istringstream iss(str);
                iss >> n2;
                break;
            }
        }
        inpfile.close();
        return 0;
    }else{
        std::cerr << "Configuration File " << file << " not found!" <<std::endl;
        return 1;
    }
}

void ConfigRead::display(){
    std::cout << poolSize << "  " << nPools << "  " << logFileSize << "  " << nLogFiles << std::endl;
}

ConfigRead::~ConfigRead(){
	delete[] poolFile;
	delete[] logFile;
}
