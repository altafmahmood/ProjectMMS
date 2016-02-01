//Copyright (c)
//Authors     : Altaf Mahmood
//Date        : 18 Jan 2016
//Time        : 10:45
//Purpose     : Program to generate a LinkedList

#include "Node.h"

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
