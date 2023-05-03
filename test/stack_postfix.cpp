#include <iostream>

using namespace std;

class indata {
    public:
        char _token;
        void set_data(char token);
        char get_data();
};


class stack{
    private:
        int _top;
        int _size;
        indata *p;
    public:
        stack();
        stack(int size);
        void push(indata t);
        void push(char token);
        indata pop();
        indata top();
        bool full_check();
        bool empty_check();
        void get_all();
};


int get_precedence(char token ,char oper[]);

bool is_operand(char token ,char oper[]);

string postfix(stack &s ,string input ,char oper[]);


int main(void){

    char oper[] = {'$','(','+','-','*','/','%'};

    string input;

    stack s;

    cout << "infix : ";

    cin >> input;

    // postfix(s,input,oper);

    cout << "postfix : " << postfix(s,input,oper) << endl;

    return 0;
}

string postfix(stack &s ,string input ,char oper[]){

    char token;
    int pre;
    string result;

    if(input.size() == 0) return result;

    s.push('$');

    for (int i = 0; i < input.size(); i++){

        token = input[i];

        // cout << token << " "<< result << " " << s.top()._token << " " <<i << endl;

        if(is_operand(token,oper)){

            if(token == '('){

                s.push(token);

            }

            else{

                while(get_precedence(s.top()._token,oper) >= get_precedence(token,oper)) {

                    result += s.pop()._token;  

                }
                    
                s.push(token);

            }

        }
        else{

            if( token == ')'){

                while(s.top()._token != '(') {

                    result += s.pop()._token;  

                }

                s.pop();

            }
            else{

                result += token;

            }


        }

    }

    while(!(s.top()._token == '$')){
        result += s.pop()._token;
    }

    return result;
}

bool is_operand(char token, char oper[]){

    for(int i = 0; i < sizeof(oper)/sizeof(oper[0]); i++){
        if(token == oper[i]) 
            return true;    
    }
    return false;

}


int get_precedence(char token, char oper[]){


    for(int i = 0; i < sizeof(oper)/sizeof(oper[0]); i++){
        if(token == oper[i]){
            if(i >= 6) return 2;
            return i/2;
        }
    }

    return -1;
}


void indata::set_data(char token){
    this->_token = token;
}
char indata::get_data(){
    return _token;
}

stack::stack(){
    _top = 0;
    _size = 100;
    p = new indata[_size];
}
stack::stack(int size){
    _top = 0;
    _size = size;
    p = new indata[_size];

}
void stack::push(indata t){
    if(!full_check())
        p[_top++] = t;
    else {
        cout << "full" << endl;
        return;
    }
        
}

void stack::push(char token){

    indata k;
    k.set_data(token);


    if(!full_check())
        p[_top++] = k;
    else {
        cout << "full" << endl;
        return;
    }
        
}

indata stack::pop(){
    if(!empty_check())
        return  p[--_top];
}
indata stack::top(){
    int temp = _top -1;
    return p[temp];
}

bool stack::full_check(){
    if(_top == _size) return true;
    return false;
    
}
bool stack::empty_check(){
    if(_top == 0) return true;
    return false;
}
void stack::get_all(){
    for(int i = 0; i < _top; i++){
        cout << "token : " << p[i]._token  << endl;
    }
}