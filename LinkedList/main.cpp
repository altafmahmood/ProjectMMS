#include "List.h"
#include<cstdlib>

int main(){
    List ls;
    void* fla = malloc(10);
    ls.addToEnd(fla,10);
    ls.addToEnd(fla,20);
    ls.addToEnd(fla,30);
    ls.display();
    ls.getData(2);
}