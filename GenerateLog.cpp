#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <unistd.h>
#include <cstring>
#include <cstdio>
#include "GenerateLog.h"
#include "ConfigRead.h"

static int countCh,fileNo,LineNo,NoOfFile,iDel,iAdd;

GenerateLog::GenerateLog(){
    iAdd=0;
    NoOfFile = 0;
    fileName[iAdd]=generateName();
    outFile.open(fileName[iAdd].c_str());
    iAdd++;
    NoOfFile++;
    // outFile.close();
    fileNo = 1;
    countCh = 0;
    LineNo = 1;
    iDel=0;
}

void GenerateLog::Log(){
    ConfigRead cf;
    cf.assignData();
    std::string str;
    int c,s;
    c=LineNo;
    
    inpFile.open(".memory.log");
    int k=LineNo;
    while(k){
        getline(inpFile,str);
        k--;
    }
    inpFile.close();
    
    LineNo++;
    countCh += str.length()+1;
    // std::cout << str.length() << std::endl;
    
    // std::cout << cf.getNLogFile() << "\n"; 
    if(countCh<cf.getLogFileSize()){
        // std::cout<<str<<std::endl;
        outFile << str << "\n";
    }else{
        if(NoOfFile>cf.getNLogFile()){
            // std::cout << fileName[iDel];
            remove(fileName[iDel].c_str());
            iDel++;
        }

        outFile.close();
        std::string p;
        inpFile.open(".memory.log");
        getline(inpFile,p);
        inpFile.close();
        
        fileName[iAdd] = generateName();
        outFile.open(fileName[iAdd].c_str());
        iAdd++;
        NoOfFile++;
        fileNo++;
        outFile << p << "\n" << str << "\n";
        countCh=str.length()+p.length()+1;
    }
}

char* GenerateLog::generateName(){
    time_t now = time(0);
    std::string dt = ctime(&now);
    std::string str1,str2,strf="./Logs/";
    std::stringstream ss(dt);
        
        ss >> str1;
        ss >> str1;
        strf += str1;
        ss >> str1;
        strf += str1;
        strf += "-";
        ss >> str1;
        strf += str1;
        strf +="-";
        strf += dynamic_cast< std::ostringstream & >( (std::ostringstream() << std::dec << fileNo ) ).str();
        strf += ".log";
        
        // std::cout << strf << std::endl; 
        char* st = const_cast<char*>(strf.c_str());
        NoOfFile++;

    return st;
}

void GenerateLog::displayName(){
    for(int i=0;i<iAdd;i++){
        std::cout << fileName[i] << std::endl; 
    }
}
