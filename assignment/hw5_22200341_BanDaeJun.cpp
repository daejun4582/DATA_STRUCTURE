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


struct oper {
    char*op;
    int op_len;
};


bool is_operand(char ch, oper check);

bool check_infix(op_stack stack,string command, oper op);


int main(void){

    string command;

    bool result;

    oper op;

    op_stack stack = op_stack();

    op.op = new char[3];

    op.op_len = 3;

    char oper[] = { '{', '(', '['};

    for(int i = 0; i< op.op_len; i++) op.op[i] = oper[i];

    cout<<"검사할 infix 방식의 식을 입력해주세요. : ";

    getline(cin, command);

    result = check_infix(stack,command,op);

    cout << "해당 식은 "<< (result? "올바릅니다." : "잘못되었습니다.") << endl;

    
    return EXIT_SUCCESS;
}

bool check_infix(op_stack stack,string command, oper op){
    char token;
    char error;
    for(int i = 0; i< command.size(); i++){
        token = command[i];
        if(is_operand(token, op)){
            stack.push(token);
        }
        else{
            if(token == ')'){
                if(stack.get_top() == '(' && !stack.stack_empty()) stack.pop();
                else if(stack.stack_empty()) {cout << " '(' 가 Stack 내에 존재하지 않습니다." << endl; return false;}
                else {cout << " '(' 가 필요합니다." << endl; return false;}
            }
            else if(token == '}'){
                if(stack.get_top() == '{' && !stack.stack_empty()) stack.pop();
                else if(stack.stack_empty()) {cout << " '{' 가 Stack 내에 존재하지 않습니다." << endl; return false;}
                else {cout << " '{' 가 필요합니다." << endl; return false;}
            }
            else if(token == ']'){
                if(stack.get_top() == '[' && !stack.stack_empty()) stack.pop();
                else if(stack.stack_empty()) {cout << " '[' 가 Stack 내에 존재하지 않습니다." << endl; return false;}
                else {cout << " '[' 가 필요합니다." << endl; return false;}
            }
            
        }

    }

    if(!stack.stack_empty()) {
        error = stack.get_top();
        if(error == '('){
            cout << " ')' 가 필요합니다." << endl;
        }
        else if(error == '{'){
            cout << " '}' 가 필요합니다." << endl;
        }
        else if(error == '['){
            cout << " ']' 가 필요합니다." << endl;
        }
        return false;
          }
    return true;
}


bool is_operand(char ch, oper check){

    for (int i = 0; i< check.op_len; i++)
        if(ch == check.op[i]) return true;
    
    return false;
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