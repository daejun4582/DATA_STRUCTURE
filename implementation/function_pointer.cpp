#include <iostream>
#include <stdlib.h>
#include <cstdlib>
 
using namespace std;


int comp_int(const void *a,const void *b){
    return (*((int*)a)-*((int*)b));
}

int comp_char(const void *a,const void *b){
    return (*((char*)a)-*((char*)b));
}


int main(void){
    int values[] = { 4, 6, 3, 2, 5, 7, 9, 8};
    // char values[] = { 'n', 'i', 'b', 'c'};
    int n = sizeof(values)/sizeof(values[0]);
    qsort(values,n,sizeof(values[0]),comp_int);

    for(int i = 0; i < n; i++){
        cout<<values[i]<<" "; 
    }
    
    return EXIT_SUCCESS;
}