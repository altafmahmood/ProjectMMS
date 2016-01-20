//template<class int>
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