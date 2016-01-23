#include "./LinkedList/List.h"
#include "GenerateLog.h"
#include <string>

class Memory{
    private:
        
    public:
        //void* operator new(size_t,int);
        //void operator delete(void*);
        void* allocate(int);
        void deallocate(void*);
};

class MemoryManagement:public Memory{
    private:
        int noOfChunks;
        int* allocatedChunk[];
        int* unallocatedChunk[];
        int TotalCapacity[100], MemoryAllocated[100], MemoryAvailable[100], MPoolSize;       
        
        List ls;
        GenerateLog gf;
    
    public:
        MemoryManagement();
        void createPool(int, int, void**);
        void freePool(void* );
        int createChunk(void* , void**, int, List& );
        void createLog(std::string);
        void createLog(std::string ,void* ,int );
        void* allocateChunk(int, List&, int);
        void deallocateChunk(void* , List&, int);
        void displayInfo(int);
        void viewContents(char*, int);
};