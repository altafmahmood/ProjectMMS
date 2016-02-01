//Copyright (c)
//Authors     : Altaf Mahmood
//Date        : 18 Jan 2016
//Time        : 10:00
//Purpose     : Program to generate a Node for LinkedList with void* Data, Flag and NoOfChunks

class Node{
    private:
        void* data;
        int flag;
        int nOfChunks;
        Node* next;
    public:
        void setData(void*);
        void setFlag(int);
        void setNOfChunk(int);
        void setNext(Node*);
        void* getData();
        int getFlag();
        int getNOfChunk();
        Node* getNext();
};
