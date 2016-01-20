#include"ConfigRead.h"
#include"memory.h"
#include<iostream>

int main(){
    MemoryManagement mm;
    Memory mo;
    ConfigRead cf;
    
    cf.assignData();
    void* pool[cf.getNPool()];
    
    mm.createPool(cf.getNPool(), pool);
    
    for(int i=0; i<cf.getNPool(); i++){
        std::cout << pool[i] << "\n";
        mm.freePool(pool[i]);
    }
    
    
    //mo.deallocate(fla);
    return 0;
    
}