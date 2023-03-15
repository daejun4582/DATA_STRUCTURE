#include <iostream>
#include <cstdlib>
#define SIZE 100

using namespace std;

class mystack{
    private:
        int top;
        int* s = new int[SIZE];
    public:
        mystack();
        void push(int x);
        int pop();
        int get_top();
        bool stack_full();
        bool stack_empty();
        
};


struct oper {
    char*op;
    int op_len;
};

int cal_postfix(mystack stack, string command, oper op);

int cal(int num1, int num2, char oper);

bool is_operand(char ch, oper check);

int main(void){

    string command;

    oper op;

    mystack stack = mystack();

    op.op_len = 7;
    op.op = (char*)malloc(sizeof(op.op_len));

    char oper[] = { '(', '$', '+', '-', '*', '/', '%'};
    for(int i = 0; i< op.op_len; i++) op.op[i] = oper[i];

    cout<<"계산할 식을 postfix 방식의 식을 입력해주세요. : ";

    cin >> command;

    cout << "계산 결과는 다음과 같습니다. : " << cal_postfix(stack,command,op) << endl;

    return EXIT_SUCCESS;
}

int cal_postfix(mystack stack, string command,oper op){

    char token;
    int num1,num2;

    for(int i = 0; i < command.size(); i++){
        token = command[i];

        if(is_operand(token, op)){
            num2 = stack.pop();

            num1 = stack.pop();

            stack.push(cal(num1,num2,token));
        }
        else{
            stack.push(token-48);
        }

    }

    return stack.get_top();
}

int cal(int num1, int num2, char oper){
    int result;
    if(oper == '+'){
        result =  num1 + num2;
    }
    else if(oper == '-'){
        result =  num1 - num2;
    }
    else if(oper == '/'){
        result =  num1 / num2;
    }
    else if(oper == '*'){
        result =  num1 * num2;
    }

    return result;
}

bool is_operand(char ch, oper check){

    for (int i = 0; i< check.op_len; i++)
        if(ch == check.op[i]) return true;
    
    return false;
}



mystack::mystack(){
    top = 0;
}

void mystack::push(int x){
    s[top++] = x;
}

int mystack::pop(){
    return s[--top];
}

int mystack::get_top(){
    return s[top-1];
}

bool mystack::stack_full(){
    if(top>=SIZE) return true;
    else return false;
}

bool  mystack::stack_empty(){
    if(top ==0 ) return true;
    else return false;
}