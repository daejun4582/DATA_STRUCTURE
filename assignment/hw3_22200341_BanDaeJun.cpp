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


string postfix(op_stack stack,string com,oper cehck);

bool is_operand(char ch, oper check);

int get_precedence(char op, oper check);


int main(void){
    string command;

    oper op;

    op.op_len = 7;
    op.op = (char*)malloc(sizeof(op.op_len));

    char oper[] = { '(', '$', '+', '-', '*', '/', '%'};
    for(int i = 0; i< op.op_len; i++) op.op[i] = oper[i];

    op_stack stack = op_stack();

    stack.push('$');

    cout<<"변환할 infix 방식의 식을 입력해주세요. : ";

    cin >> command;

    cout << "변환한 postfix 결과는 다음과 같습니다. : " << postfix(stack,command,op) << endl;

    return EXIT_SUCCESS;
}

string postfix(op_stack stack,string com,oper check){

    char token;

    string result;

    for(int i = 0; i < com.length(); i++){

        token = com[i];
        
        if(is_operand(token,check)){

            if(token == '(') {
                
                stack.push('(');

            }

            else{     
                
                while(get_precedence(stack.get_top(),check) >= get_precedence(token,check)) result += stack.pop();
    
                stack.push(token);

            }

        }
        else{

            if(token == ')') {

                while(stack.get_top() != '(') result += stack.pop();

                stack.pop();
            }
            else 
                result += token;
            
        }
            
    }

    while(stack.get_top() != '$') result += stack.pop();

    return result;
}

bool is_operand(char ch, oper check){

    for (int i = 0; i< check.op_len; i++)
        if(ch == check.op[i]) return true;
    
    return false;
}



int get_precedence(char op, oper check){
    int prec;
    for (int i = 0; i< check.op_len; i++)
        if(op == check.op[i]) {
            prec = (i / 2);
            if(prec>=3) return 2;
        }
    
    return prec;
    
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