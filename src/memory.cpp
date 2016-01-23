#include<cstdlib>
#include<iostream>
#include<string>
#include<fstream>
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
    std::ofstream outFile(".memory.log");
    outFile << "Logs\t\t\t Memory Space\tSize\n";
    outFile.close();
    MPoolSize = 0;
}

void MemoryManagement::createPool(int nPool,int poolSize,void** pool){
    int i;
    MPoolSize = poolSize;
    for(i=0; i<nPool; i++){
        pool[i] = allocate(poolSize);
        TotalCapacity[i] = poolSize;
        MemoryAllocated[i] = 0;
        MemoryAvailable[i] = TotalCapacity[i];
        createLog("Pool created \t", pool[i], poolSize);
    }
}

void MemoryManagement::freePool(void* storage){
    deallocate(storage);
    createLog("Pool Deallocated",storage,MPoolSize);
}

int MemoryManagement::createChunk(void* pool, void** chunk, int poolSize, List& lst){
    noOfChunks = poolSize/100;
    List ls;
    for(int i=0; i<noOfChunks; i++){
        chunk[i]=(char*)pool+i*100;
        ls.addToEnd(chunk[i],0,0);    //Flag=0 for unallocated;
    }

    lst=ls;
    return noOfChunks;
}

void* MemoryManagement::allocateChunk(int size, List& lst, int Npool){
    int i=0,x=0,cnt;
    int total=1,found=0;
    void* returnValue;

    if(size>100){
        total = (size/100)+1;
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
                    lst.setFlag(x,1);
                    break;
                }
            }
        }
    }else{
        total = 1;
        while(lst.getFlag(i)==1){
            i++;
        }
        lst.setFlag(i,1);
        returnValue = lst.getData(i);
        lst.setNOfChunks(i,total);
        found = 1;
    }
    if(!found){
        createLog("Chunk Allottment failed\n");
        return NULL;
    }else{
        createLog("Chunk Allotted\t",returnValue, (total+1)*100);
        MemoryAllocated[Npool] += total*100;
        return returnValue;
    }
}

void MemoryManagement::deallocateChunk(void* chunk, List& lst, int Npool){
    int i=0,j=0;
    while(lst.getData(i)!=chunk){
        i++;
    }
    j = lst.getNOfChunks(chunk);
    createLog("Deallocated\t\t",chunk,j*100);
    MemoryAllocated[Npool] -= j*100;
    while(j){
        lst.setFlag(i,0);
        lst.setNOfChunks(i,0);
        i++;j--;
    }

}

void MemoryManagement::displayInfo(int Npool){
    std::cout << "TotalCapacity : " << TotalCapacity[Npool] << std::endl;
    std::cout << "MemoryAllocated : " << MemoryAllocated[Npool] << std::endl;
    MemoryAvailable[Npool] = TotalCapacity[Npool] - MemoryAllocated[Npool];
    std::cout << "MemoryAvailable : " << MemoryAvailable[Npool] << std::endl;
}

void MemoryManagement::viewContents(char* ptr,int size){
    char* v = ptr;
    for(int i=0; i<size; i++){
        std::cout << *v << "\t";
        v++;
    }
    std::cout << std::endl;
}


void MemoryManagement::createLog(std::string log){
    std::ofstream outFile(".memory.log",std::ios::app);
    outFile << log;
    outFile.close();
    gf.Log();
}

void MemoryManagement::createLog(std::string log, void* storage, int size){
    std::ofstream outFile(".memory.log",std::ios::app);
    outFile << log << storage << "\t\t " << size << "\n";
    outFile.close();
    gf.Log();
}
