#include <iostream>
#include <stdlib.h>
using namespace std;

class Stack{
    private:
        int* p;
        int top;
        int size;
        int count;
    public:
        Stack();
        void push(int x);
        int pop();
        bool stack_full();
        bool stack_empty();

};



int main(void){
    string command;
    int indata;
    Stack s = Stack();
    for(;;){
        cout<<"명령어를 입력하세요 : ";
        cin >> command;
        if(command == "push"){
            cout<<"넣을 값을 입력하세요. : ";
            cin >> indata;
            s.push(indata);
        }
        else if(command == "pop"){
            if(s.stack_empty())
                cout<<"더 이상 데이터가 존재하지 않습니다.\n\n";
            else
                cout<<"결과 : "<<s.pop()<<"\n";
        }
        else if(command == "done"){
            break;
        }
        else{
            cout<<"존재하지 않는 명령어 입니다. 다시 입력해주세요.\n\n";
        }
    }
    return EXIT_SUCCESS;
}


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