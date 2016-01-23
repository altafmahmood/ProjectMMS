#include<iostream>
#include<pthread.h>
#include<cstdlib>
#include"ConfigRead.h"
#include"memory.h"

using namespace std;

struct thread_data{
   void* ptr;
   int  size;
   char character;
};

void *PrintChar(void *threadarg)
{
   struct thread_data *myData;
    void* p;
   
   myData = (struct thread_data *) threadarg;

    p = myData->ptr;
    // std::cout << "HerE" <<std::endl;
   for(int i=0; i<myData->size; i++){
       *(char*)p = myData->character;
       p=(char*)p+1;
   }
   
   pthread_exit(NULL);
}

int threadFunction(void* p, int s, char c)
{    
//    char* pc = (char* )pv; 
//    std::cout << p;
   pthread_t threads;
   struct thread_data td;
   int rc,i=0;
      td.size = s;
      td.ptr = p;
      td.character = c;
      rc = pthread_create(&threads, NULL, PrintChar, (void *)&td);
      pthread_join(threads,NULL);
      
      if (rc){
         std::cout << "Error:unable to create thread," << rc << std::endl;
         exit(-1);
      }
}

void menu();

int main(){
    menu();
    return 0;
}


void menu(){
  MemoryManagement mm;
  Memory mo;
  ConfigRead cf;
  cf.assignData();
  List ls[cf.getNPool()];
  void* pool[cf.getNPool()];
  void* chunk[cf.getNPool()][cf.getPoolSize()];
  void* chunkAllocated[100];
  int noOfChunk[cf.getNPool()];
  int isPoolAllocated=0;
  static int chunkCount=0;
//   int chunkCount[cf.getNPool()];
  
  int choice,i=1;
  
  int pl,sz,rf;
  char ch;
    
  while(i){  
    std::cout << "\tMMS Menu" << std::endl;
    std::cout << "1. Allocate Pools\n2. Deallocate Pools\n3. Allocate chunk\n4. Deallocate chunk\n5. View pool status\n6. Insert Contents\n7. View Contents\n8. Any key to Exit" << std::endl;
    std::cout << " Enter Choice : ";
    std::cin >> choice;
    
    switch(choice){
        case 1:
            if(!isPoolAllocated){
                mm.createPool(cf.getNPool(), cf.getPoolSize(), pool);
                for(int j=0; j<cf.getNPool(); j++){
                    noOfChunk[j] = mm.createChunk(pool[j],chunk[j],cf.getPoolSize(),ls[j]);
                }
                isPoolAllocated++;
            }else{
                std::cout << "Pool already created deallocate first" << std::endl;
            }
            break;

        case 2:
            if(isPoolAllocated){
                for(int j=0; j<cf.getNPool(); j++){
                    mm.freePool(pool[j]);
                }
                isPoolAllocated=0;
            }else{
                std::cout << "Pool is not allocated Allocate First" << std::endl;
            }
            break;
            
        case 3:
            pl=(cf.getNPool()+1);
            while(pl>cf.getNPool()){
                std::cout << "Enter the pool to allocate chunk : ";
                std::cin >> pl;
            }
            std::cout << "Enter the size to allocate : " ;
            std::cin >> sz;
            if(sz>cf.getPoolSize()){
                std::cout << "Not allocated" << std::endl;
            }else{
                chunkAllocated[chunkCount] = mm.allocateChunk(sz, ls[pl], pl);
                std::cout << "Allocated " << chunkAllocated[chunkCount] << ". Reference Number is " << chunkCount << " & Pool is " << pl << std::endl;
            }
            chunkCount++;
            break;
            
        case 4:
            std::cout << "Enter reference number to deallocate : " ;
            std::cin >> rf;
            std::cout << "Enter the pool : ";
            std::cin >> pl;
            if(rf<chunkCount){
                mm.deallocateChunk(chunkAllocated[rf],ls[pl],pl);
            }else{
                std::cout << "Reference not present" << std::endl;
            }
            break;
            
        case 5:
            std::cout << "Enter the Pool Number : ";
            std::cin >> pl;
            if(pl<cf.getNPool()){
                mm.displayInfo(pl);
                std::cout << "\n\tMemory Map\n";
                ls[pl].display();
            }else{
                std::cout << "Pool not present" << std::endl;
            }
            break;
            
        case 6:
            std::cout << "Enter the character to fill : ";
            std::cin >> ch;
            std::cout << "Enter the reference to fill : ";
            std::cin >> rf;
            std::cout << "Enter the size : ";
            std::cin >> sz;
            if(rf<chunkCount){
                threadFunction(chunkAllocated[rf],sz,ch);
            }else{
                std::cout << "Reference not present" << std::endl;
            }
            break;
            
        case 7:
           std::cout << "Enter Reference Number : ";
            std::cin >> rf;
            std::cout << "Enter the size : ";
            std::cin >> sz;
            if(rf<chunkCount){
                mm.viewContents((char*)chunkAllocated[rf],sz);    
            }else{
                std::cout << "Reference not present" << std::endl;
            }
            break;
            
        default:
            i=0;
            break;                
    }
  }  
}

/*
int main(){
    MemoryManagement mm;
    Memory mo;
    ConfigRead cf;
    cf.assignData();
    List ls[cf.getNPool()];   

    void* pool[cf.getNPool()];
    void* chunk[cf.getNPool()][cf.getPoolSize()];
    // std::cout << "Initiated";
    
    mm.createPool(cf.getNPool(), cf.getPoolSize(), pool);
    // char* fa = (char*) pool[0];
    mm.createChunk(pool[0],chunk[0],cf.getPoolSize(),ls[0]);
    void* fb = mm.allocateChunk(100,ls[0]);
    //std::cout<<"fb==>"<<fb<<std::endl;
    
    threadFunction(fb,100,'a');
   
    std::cout << "After thread" <<std::endl;
    mm.viewContents((char*)fb,100);
    
    ls[0].display();
    return 0;   
}

*/


/*
void getInput(){
    
}

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
    //std::string fsa= "Created a log file\n";
    //mm.createLog(fsa);
    // std::string fsb="Something\n";
    // mm.createLog(fsb);
    
    ls[0].display();
    // std::cout << std::endl << chunk[0][0] << std::endl;
    // std::cout << chunk[0][1] << std::endl;
    // std::cout << chunk[0][2] << std::endl;
    
    //mo.deallocate(fla);
    */




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