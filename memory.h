#include"./LinkedList/List.h"

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
        List ls;
        
    public:
        MemoryManagement();
        void createPool(int, int, void**);
        void freePool(void* );
        int createChunk(char* , void**, int, List& );
        void createLog();
        void* allocateChunk(int, List&);
        void deallocateChunk(void* , List&);
};