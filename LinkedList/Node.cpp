#include"Node.h"

void Node::setData(void* d){
      data = d;
}

void Node::setNext(Node* n){
    next = n;
}

void Node::setFlag(int f){
    flag = f;
}

void Node::setNOfChunk(int c){
    nOfChunks = c;
}

void* Node::getData(){
    return data; 
}

int Node::getFlag(){
    return flag;
}

int Node::getNOfChunk(){
    return nOfChunks;
}

Node* Node::getNext(){
    return next;
}