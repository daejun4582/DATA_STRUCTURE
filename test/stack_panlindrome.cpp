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



int main(void){

    string input;

    stack s = stack();

    bool check = true;

    cout << "input : " ;

    cin >> input;

    for(int i = 0; i < input.size()/2; i++){
        s.push(input[i]);
    }

    for(int i = ((input.size()%2 == 0)? input.size()/2:input.size()/2+1); i < input.size(); i++){

        if(s.empty_check()){
            check = false;
            break;
        }
        else{
            if(input[i] != s.pop()._token) {
                check = false;
                break;
            }
        }
    }

    if(check){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }


    return 0;
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