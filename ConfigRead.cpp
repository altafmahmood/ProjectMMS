#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "ConfigRead.h"
#include <stdlib.h>
#include <cstring>

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

void ConfigRead::assignData(){
    int num1, num2;

    fileRead(logFile, num1, num2);
    nLogFiles = num1;
    logFileSize = num2;

    fileRead(poolFile, num1, num2);
    nPools = num1;
    poolSize = num2;

}

void ConfigRead::fileRead(char* file, int& n1, int& n2){
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
    }else{
        std::cerr << "Configuration File " << file << " not found!" <<std::endl;
    }
}

void ConfigRead::display(){
    std::cout << poolSize << "  " << nPools << "  " << logFileSize << "  " << nLogFiles << std::endl;
}

ConfigRead::~ConfigRead(){
	delete[] poolFile;
	delete[] logFile;
}
