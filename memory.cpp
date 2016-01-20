#include<cstdlib>
#include<iostream>
#include"memory.h"
#include "ConfigRead.h"
// #include "./LinkedList/List.h"

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

void MemoryManagement::createPool(int nPool,int poolSize,void** pool){
    int i;
    for(i=0; i<nPool; i++){
        pool[i] = allocate(poolSize);
    }
}

void MemoryManagement::freePool(void* storage){
    //Memory mo;
    deallocate(storage);
}

int MemoryManagement::createChunk(char* pool, void** chunk, int poolSize, List& lst){
    noOfChunks = poolSize/100;
    //List ls;
    for(int i=0; i<noOfChunks; i++){
        chunk[i]=pool+i*100;
        ls.addToEnd(chunk[i],0);    //Flag=0 for unallocated;
    }
    
    lst=ls;
    
    return noOfChunks;
}

void MemoryManagement::createLog(){
    
}

void* MemoryManagement::allocateChunk(int size, List& lst){
    int i=0,x=0,cnt;
    int total=1,found=0;
    void* returnValue;
    
    if(size>100){
        total = size/100+1;
        while(x<noOfChunks){
            if(lst.getFlag(x)==1){
                x++;
            }else{
                cnt = total;
                returnValue=lst.getData(x);
                while(cnt){
                    if(lst.getFlag(x)==1){
                        x++;
                        found=0;
                        break;
                    }else{
                        found=1;
                    }
                    x++;cnt--;
                }
                if(1==found){
                    cnt = total;
                    x = x-cnt;
                    lst.setNOfChunks(x,total);
                    while(cnt){
                        lst.setFlag(x,1);
                        x++;cnt--;
                    }
                    break;
                }
            }
        }
    }else{
        while(lst.getFlag(i)==1){
            i++;
        }
        lst.setFlag(i,1);
        returnValue = lst.getData(i);
        lst.setNOfChunks(i,total);
        found = 1;
    }
    if(!found){
        return NULL;
    }else{
        return returnValue;
    }
    
}

void MemoryManagement::deallocateChunk(void* chunk, List& lst){
    int i=0,j=0;
    while(lst.getData(i)!=chunk){
        i++;
    }
    j = lst.getNOfChunks(chunk);
    while(j){
        lst.setFlag(i,0);
        lst.setNOfChunks(i,0);
        i++;j--;
    }
}


