//Copyright (c)
//Authors     : Altaf Mahmood, Akash Negi & Amisha
//Employee ID : 333841, 334085 & 334079
//Date        : 18 Jan 2016
//Time        : 10:00
//Purpose     : Program to Create memory pools and to allocate chunks from the available memory pools and generate appropriate log messages

#include "./LinkedList/List.h"
#include "GenerateLog.h"
#include <string>

class Memory{
    private:

    public:
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
