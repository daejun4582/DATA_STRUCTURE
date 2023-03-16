#include <iostream>
#include <cstdlib>
#include <string>
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

bool check_panlindrome(op_stack stack,string str);

string preprocess_string(string str);


int main(void){

    op_stack stack;

    string str;

    cout << "pelindrome을 확인할 문장을 입력하세요 . : ";
    
    getline(cin,str);

    str = preprocess_string(str);

    if(str.size() == 0) {
        cout<< "본 문장은 panlindrome이 아닙니다." <<endl;
        return EXIT_SUCCESS;
    }

    cout << "본 문장은 panlindrome" <<((check_panlindrome(stack,str)? " 입니다": "이 아닙니다.")) << endl;


    return EXIT_SUCCESS;
}

bool check_panlindrome(op_stack stack, string str){

    int str_len = str.size();    

    for(int i = 0; i< (str_len)/2 ; i++) {
        stack.push(str[i]);

    }

    
    for(int i = ((str_len % 2 ==0)? str_len/2 : str_len/2 +1); i<str.size();  i++){
        if(stack.pop() != str[i]) return false;
    }
    

    return true;;
}

string preprocess_string(string str){

    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    string result;
    for(int i =0; i<str.size(); i++){
        if(isalpha(str[i])!=0)
            result += tolower(str[i]);
    }
    return result;
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