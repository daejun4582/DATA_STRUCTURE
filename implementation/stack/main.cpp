#include <iostream>
#include <stdlib.h>
#include "Stack.h"
using namespace std;

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