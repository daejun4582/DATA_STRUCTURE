#include <iostream>
#include <stdlib.h>
#include "/Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/linked_list_stack/LinkedListStack.h"

using namespace std;

enum Menus
{
    PUSH,
    POP,
    TOP,
    GET_LEN,
    GET_ALL,
    STACK_EMPTY,
    BREAK,
    COUNT
};

string menu[] = { 
    "   PUSH           ",
    "   POP            ",
    "   TOP            ",
    "   GET_LEN        ",
    "   GET_ALL        ",
    "   STACK_EMPTY    ",
    "   BREAK          ",
    "   COUNT          "
    };


void print_menu();
void call_push(LinkedListStack &stack);
void call_pop(LinkedListStack &stack);
void call_top(LinkedListStack &stack);
void call_get_len(LinkedListStack &stack);
void call_get_all(LinkedListStack &stack);
void call_stack_empty(LinkedListStack &stack);
void run_program(LinkedListStack &stack);


int main(void){
    
    LinkedListStack stack = LinkedListStack();

    run_program(stack);

    return EXIT_SUCCESS;
}

void print_menu(){
    Menus k = COUNT;

    cout << "\n사용할 명령어를 입력하세요. \n" << endl;
    cout << "--------------------------" << endl;
    cout << "         Menu List" << endl;
    cout << "--------------------------" << endl;


    for(int i = 0; i < k; i++){
       cout << menu[i] << " [" << i << "]"<<endl;
    }
    cout << "--------------------------" << endl;
    
    cout << "\nCommand : " ;

}

void call_push(LinkedListStack &stack){

    struct data indata;

    cout << "입력할 데이터를 입력해주세요 : " << endl;

    cout << "이름  : ";
    cin >> indata.name;

    cout << "학번  : ";
    cin >>indata.id ;

    cout << "점수  : ";
    cin >> indata.score;
    
    stack.push(indata);

    cout << "완료되었습니다." << endl;

}


void call_pop(LinkedListStack &stack){
    struct data result;

    if(stack.stack_empty() == false){
        result = stack.pop();
        cout << "삭제한 학생의 자료는 다음과 같습니다." << endl;
        cout << "----------------------------" << endl;
        cout << "이름 : " << result.name << endl;
        cout << "학번 : " << result.id << endl;
        cout << "완료되었습니다." << endl;
    }
    else{
        cout << "데이터가 존재하지 않습니다." << endl;
    }
}
void call_top(LinkedListStack &stack){
    struct data check_top;
    if(stack.stack_empty() == false){
        check_top = stack.top();
        cout << "현재 top에 있는 학생의 자료는 다음과 같습니다." << endl;
        cout << "----------------------------" << endl;
        cout << "이름 : " << check_top.name << endl;
        cout << "학번 : " << check_top.id << endl;
        cout << "완료되었습니다." << endl;
    }
    else{
        cout << "데이터가 존재하지 않습니다." << endl;
    }
}
void call_get_len(LinkedListStack &stack){
    cout << "현재 스택내의 원소 개수는 " << stack.get_len() << "입니다." << endl;
}
void call_get_all(LinkedListStack &stack){
    if(stack.stack_empty() == false){
        cout << "\n--------------------------------" << endl;
        cout << "현재의 데이터를 출력하겠습니다." << endl;
        cout << "--------------------------------\n" << endl;
        stack.get_dataes();
    }
    else {
        cout << "출력할 데이터가 존재하지 않습니다." << endl;
    }
}
void call_stack_empty(LinkedListStack &stack){
    cout << "현재 스택에 원소가 " << (stack.stack_empty()? "존재 하지 않습니다." : "존재 합니다.") << endl;
}


void run_program(LinkedListStack &stack){
    int command;
    bool status;

    while(true){

        status = false;
        print_menu();
        cin >> command;
        cout << "\n" << endl;

        switch(command){
            case Menus::PUSH :
                call_push(stack);
                break;
            
            case Menus::POP :
                call_pop(stack);
                break;
            
            case Menus::TOP :
                call_top(stack);
                break;

            case Menus::GET_LEN :
                call_get_len(stack);
                break;

            case Menus::GET_ALL :
                call_get_all(stack);
                break;

            case Menus::STACK_EMPTY :
                call_stack_empty(stack);
                break;

            case Menus::BREAK :
                status = true;
                break;

            default :
                cout << "잘못된 명령어 입니다. 다시 입력해주세요. " << endl;
                break;
        }

        if(status == true) break;
    }
}