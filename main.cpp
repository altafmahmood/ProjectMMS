#include"ConfigRead.h"
#include"memory.h"
// #include"./LinkedList/List.h"
#include<iostream>



int main(){
    MemoryManagement mm;
    Memory mo;
    ConfigRead cf;
    cf.assignData();
    List ls[cf.getNPool()];   

    void* pool[cf.getNPool()];
    void* chunk[cf.getNPool()][cf.getPoolSize()];
    
    mm.createPool(cf.getNPool(), cf.getPoolSize(), pool);
    
    
     for(int i=0; i<cf.getNPool(); i++){
        std::cout << pool[i] << "\n";
        //mm.freePool(pool[i]);
     }
    char* fa;
    fa = (char*)pool[0];
    
    mm.createChunk(fa,chunk[0],cf.getPoolSize(),ls[0]);
    ls[0].display();
    
    std::cout << mm.allocateChunk(100,ls[0]) << std::endl;
    void* ff = mm.allocateChunk(100,ls[0]);
    std::cout << mm.allocateChunk(100,ls[0]) << std::endl;
    mm.deallocateChunk(ff,ls[0]);
    
    ff = mm.allocateChunk(200,ls[0]);
    mm.allocateChunk(270,ls[0]);
    mm.deallocateChunk(ff,ls[0]);
    mm.allocateChunk(150,ls[0]);
    
    ls[0].display();
    // std::cout << std::endl << chunk[0][0] << std::endl;
    // std::cout << chunk[0][1] << std::endl;
    // std::cout << chunk[0][2] << std::endl;
    
    //mo.deallocate(fla);
    return 0;
    
}






/*  char* fa=(char*)pool[0];
    char* l=fa;
    for(int i=0; i<1024;i++){
        *l='a';
        l++;
    }
    
     char* fb=(char*)pool[1];
     l=fb;
    for(int i=0; i<1024;i++){
        *l='b';
        l++;
    }
    
    l=fa;
    for(int i=0;i<1024;i++){
        std::cout<<*l<<"  ";
        l++;
    }
    std::cout << std::endl;
    
    l=fb;
    for(int i=0;i<1024;i++){
        std::cout<<*l<<"  ";
        l++;
    }
    std::cout << std::endl;
    */
    