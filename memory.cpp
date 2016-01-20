#include<cstdlib>
#include<iostream>
#include"memory.h"
#include "ConfigRead.h"

void* Memory::allocate(int size){
    void* storage = malloc(size);
    if(storage!=NULL){
        return storage;
    }else{
        return NULL;
    }
}

void Memory::deallocate(void* storage){
    free(storage);
}

MemoryManagement::MemoryManagement(){
    
}

void MemoryManagement::createPool(int poolSize,void** pool){
    Memory mo;
    int i = 0;
    
    for(i=0; i<poolSize; i++){
        pool[i] = mo.allocate(poolSize*sizeof(int));
    }
}

void MemoryManagement::freePool(void* storage){
    Memory mo;
    mo.deallocate(storage);
}

void MemoryManagement::createChunk(){
    
}

void MemoryManagement::createLog(){
    
}