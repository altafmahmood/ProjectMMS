#include<iostream>
#include"List.h"

List::List(){
    head = 0;
}

void List::addToEnd(void* d,int f,int n){
    Node* temp = new Node;
    temp->setData(d);
    temp->setFlag(f);
    temp->setNext(0);
    temp->setNOfChunk(0);

    if(head == 0){
        head = temp;
    }else{
        Node* tmp;
        tmp = head;
        while(tmp->getNext()!=0){
            tmp=tmp->getNext();
        }
        tmp->setNext(temp);
    }
}

void List::display(){
    Node* temp = head;
    while(temp != 0){
        std::cout << "Pointer : " << temp->getData() << "\tFlag : " << temp->getFlag() << "\tNoOf chunks : " << temp->getNOfChunk() << std::endl;
        temp = temp->getNext();
    }
    std::cout << std::endl;
}


void* List::getData(int pos){
    Node* temp = head;
    for(int i=1; i<pos; i++){
        temp = temp->getNext();
    }
    return temp->getData();
}


int List::getFlag(int pos){
    Node* temp = head;
    for(int i=1; i<pos; i++){
        temp = temp->getNext();
    }
    return temp->getFlag();
}


void List::setFlag(int pos, int f){
    Node* temp = head;
    for(int i=1; i<pos; i++){
        temp = temp->getNext();
    }
    temp->setFlag(f);
}

void List::setData(int pos, void* d){
    Node* temp = head;
    for(int i=1; i<pos; i++){
        temp = temp->getNext();
    }
    temp->setData(d);
}


void List::setNOfChunks(int pos, int c){
    Node* temp = head;
    for(int i=1; i<pos; i++){
        temp = temp->getNext();
    }
    temp->setNOfChunk(c);
}

int List::getNOfChunks(void* d){
    Node* temp = head;
    while(d!=temp->getData()){
        temp = temp->getNext();
    }
    return temp->getNOfChunk();
}
