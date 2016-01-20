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
        void assignData();
        void fileRead(char*, int&, int&);
        void display();
	    ~ConfigRead();
};
