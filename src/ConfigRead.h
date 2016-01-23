//Copyright (c)
//Authors     : Altaf Mahmood, Akash Negi & Amisha
//Employee ID : 333841, 334085 & 334079
//Date        : 18 Jan 2016
//Time        : 13:24
//Purpose     : Program to read the Configuration Files

#include<string>

class ConfigRead{
    private:
        char *logFile, *poolFile;
        int poolSize;
        int nPools;
        int logFileSize;
        int nLogFiles;

    public:
        ConfigRead();
        int getPoolSize();
        int getNPool();
        int getLogFileSize();
        int getNLogFile();
        int assignData();
        int fileRead(char*, int&, int&);
        void display();
	    ~ConfigRead();
};
