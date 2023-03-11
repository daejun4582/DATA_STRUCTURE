#include <iostream>
#include <stdlib.h>
#include "OpStack.h"
using namespace std;


OpStack::OpStack(){
    count = 0;
    size = 3;
    p = (char*)malloc(sizeof(size));
    top  = 0;
}

void OpStack::get_all(){
    for(int i = 0; i < count; i++){
        cout << p[i] << " ";
    }
    cout << endl;

}

void OpStack::push(char x){
    if(stack_full()){
        size *= 2;
        p = (char*)realloc(p,sizeof(char)*size);
        p[top++] = x;
        count++;

    }
    else{
        p[top++] = x;
        count++;

    } 
}

char OpStack::pop(){
    if(count < size/2){
        size /= 2;
        p = (char*)realloc(p,sizeof(size));
    }
    count--;

    return p[--top];
}

char OpStack::get_top(){
    return p[top-1];
}

bool OpStack::stack_full(){
    if(top>=size) return true;
    else return false;
}

bool  OpStack::stack_empty(){
    if(top ==0 ) return true;
    else return false;
}