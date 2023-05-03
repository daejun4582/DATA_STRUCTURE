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

bool check_bracket(stack s, string input ,char brack[]);

int is_operand(char token,char brack[]);

int main(void){

    char bracket[] = {'[','{','(',']','}',')'};

    string input;

    stack s = stack();

    bool result;

    cout << "infix : ";

    cin >> input;

    result = check_bracket(s,input,bracket);

    cout << "result : this sentence is " << (result? " normal": "not normal") << endl;

    return 0;
}


bool check_bracket(stack s, string input ,char brack[]){
    char token;
    int check_n;

    for(int i = 0; i < input.size(); i++){


        token = input[i];

        check_n = is_operand(token,brack);

        if(0 <= check_n && check_n < 3)
        {
            s.push(token);
        }

        else if(3 <= check_n){

            if(s.empty_check())
            {
                cout << "open bracket is empty" << endl;

                return false;
            }
            else if(brack[check_n -3] != s.pop()._token) 
            {
                cout << "bracket is not matched" << endl;

                return false;
            }
                
        }

    }

    if(!(s.empty_check()))
    {

        cout << "close bracket is empty" << endl;

        return false;

    }

    return true;
        
}

int is_operand(char token,char brack[]){
    for(int i = 0; i < 6; i++){
        if(brack[i] == token) 
            return i;
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