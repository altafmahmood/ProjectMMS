
class Memory{
    private:
        
    public:
        //void* operator new(size_t,int);
        //void operator delete(void*);
        void* allocate(int);
        void deallocate(void*);
};

class MemoryManagement{
    private:
        //List allocatedChunks;
        //List poolsCreated;
        void* pool;
        
    public:
        MemoryManagement();
        void createPool(int, void**);
        void freePool(void* );
        void createChunk();
        void createLog();
};