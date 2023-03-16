#include <iostream>
#include <cstdlib>
#include "/Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/op_stack/OpStack.h"
using namespace std;


/*
--run command--
cd "/Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/assignment/" && g++ -std=c++2a -g /Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/postfix.cpp /Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/op_stack/OpStack.cpp -o a.out  && "/Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/assignment/"/a.out
*/


struct oper {
    char*op;
    int op_len;
};


string postfix(OpStack stack,string com,oper cehck);
bool is_operand(char ch, oper check);
int get_precedence(char op, oper check);


int main(void){
    string command;

    oper op;

    op.op_len = 7;
    op.op = (char*)malloc(sizeof(op.op_len));

    char oper[] = { '(', '$', '+', '-', '*', '/', '%'};
    for(int i = 0; i< op.op_len; i++) op.op[i] = oper[i];

    OpStack stack = OpStack();

    stack.push('$');

    cout<<"변환할 infix 방식의 식을 입력해주세요. : ";

    cin >> command;

    // postfix(stack,command,op);

    cout << "변환한 postfix 결과는 다음과 같습니다. : " << postfix(stack,command,op) <<endl;

    return EXIT_SUCCESS;
}

string postfix(OpStack stack,string com,oper check){

    char token;
    string result;

    for(int i = 0; i < com.length(); i++){

        token = com[i];
        
        if(is_operand(token,check)){

            if(token == '(') {
                
                stack.push('(');

            }

            else{     
                
                while(get_precedence(stack.get_top(),check) >= get_precedence(token,check)) result += stack.pop();//cout << stack.pop() ;
    
                stack.push(token);

            }

        }
        else{

            if(token == ')') {

                while(stack.get_top() != '(') result += stack.pop();//cout << stack.pop() ;

                stack.pop();
            }
            else
                result += token; 
                // cout << token ;
            
        }
            
    }

    while(stack.get_top() != '$') result += stack.pop();//cout << stack.pop() ;
    cout << endl;

    return result ;
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


/*
G*(A-B*(C/D+E)/F)
GABCD/E+*F/-* 

A+B+C*D-E*F
AB+CD*+EF*-
*/


