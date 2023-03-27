#include <iostream>
#include <cstdlib>
#define SIZE 100

using namespace std;


class op_stack{
     private:
        int top;
        char* s = new char[SIZE];
    public:
        op_stack();
        void push(char x);
        char pop();
        char get_top();
        bool stack_full();
        bool stack_empty();
};



int is_operand(char token,char *oper);

bool check_bracket(op_stack stack,string command, char *oper);


int main(void){

    string command;

    bool result;

    op_stack stack = op_stack();

    char oper[] = { '(', '{', '[',')','}',']'};

    cout<<"검사할 infix 방식의 식을 입력해주세요. : ";

    getline(cin, command);

    result = check_bracket(stack,command, oper);

    cout << "해당 식은 "<< (result? "올바릅니다." : "잘못되었습니다.") << endl;

    
    return EXIT_SUCCESS;
}

bool check_bracket(op_stack stack,string command, char *oper){
    char token;
    int op_check;
    char stack_out;
    for(int i = 0; i < command.size(); i++){
        token = command[i];
        op_check = is_operand(token,oper);

        if(0 <= op_check && op_check < 3){
            stack.push(token);
        }
        else if(op_check >= 3){
            if(stack.stack_empty() == false){
                stack_out = stack.pop() ;
                if(stack_out != oper[op_check - 3]){
                    cout << "원인 : 괄호 불일치" << endl;
                    cout << "잘못된 괄호 : " << stack_out << "   필요한 괄호 :" << oper[op_check - 3] << endl;
                    return false;
                }
            }
            else{
                cout << "원인 : 닫는 괄호 누락" << endl;
                cout << "부족한 닫는 괄호 : " << oper[op_check-3] << endl;
                return false;
            }
        }



    }

    if(stack.stack_empty() != true){
        cout << "원인 : 닫는 괄호 누락" << endl;
        cout << "부족한 닫는 괄호 : " << oper[op_check-3] << endl;
        return false;
    }

    return true;

}


int is_operand(char token,char *oper){
    for(int i = 0; i < 6; i++){
        if(token == oper[i]){
            return i;
        }
    }
    return -1;
}


op_stack ::op_stack(){
    top = 0;
}

void op_stack::push(char x){
    s[top++] = x;
}

char op_stack::pop(){
    return s[--top];
}

char op_stack::get_top(){
    return s[top-1];
}


bool op_stack::stack_full(){
    if(top>=SIZE) return true;
    else return false;
}

bool  op_stack::stack_empty(){
    if(top ==0 ) return true;
    else return false;
}