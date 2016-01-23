#include "Node.h"

//template <class Type>
class List{
    private:
        Node* head;
    public:
        List();
        void addToEnd(void*,int,int);
        void* getData(int);
        int getFlag(int);
        void setFlag(int, int);
        void setData(int, void*);
        void setNOfChunks(int, int);
        int getNOfChunks(void*);
        void display();
};