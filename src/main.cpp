//Copyright (c)
//Authors     : Altaf Mahmood
//Date        : 18 Jan 2016
//Time        : 10:00
//Purpose     : main ties the character writing into seperate thread and provide functional running


#include<iostream>
#include<pthread.h>
#include<cstdlib>
#include"ConfigRead.h"
#include"memory.h"

using namespace std;

void menu();

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


int main(){
    menu();
    return 0;
}


void menu(){
  MemoryManagement mm;
  Memory mo;
  ConfigRead cf;
  int ret = cf.assignData();
  if(ret == 1){
    exit(0);
  }
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
            if(isPoolAllocated==1){
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
            }else{
                std::cout << "Pool not allocated" << std::endl;
                break;
            }

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
