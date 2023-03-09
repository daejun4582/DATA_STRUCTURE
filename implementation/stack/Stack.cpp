#include <iostream>
#include <stdlib.h>
#include "Stack.h"
using namespace std;


Stack::Stack(){
    count = 0;
    size = 3;
    p = (int*)malloc(sizeof(size));
    top  = 0;
}

void Stack::push(int x){
    if(stack_full()){
        size *= 2;
        p = (int*)realloc(p,sizeof(size));
        p[top++] = x;
        count++;
    }
    else{
        p[top++] = x;
        count++;
    } 
}

int Stack::pop(){
    if(count < size/2){
        size /= 2;
        p = (int*)realloc(p,sizeof(size));
    }
    count--;
    return p[--top];
}

bool Stack::stack_full(){
    if(top>=size) return true;
    else return false;
}

bool  Stack::stack_empty(){
    if(top ==0 ) return true;
    else return false;
}