#include <iostream>

using namespace std;

class indata {
    public:
        string _name;
        double _score;
        void set_data(string name,double score);
        indata get_data();
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
        indata pop();
        indata top();
        bool full_check();
        bool empty_check();
        void get_all();
};



int main(void){

    stack s = stack();

    indata k ;

    k.set_data("kim",100);

    s.push(k);

    cout << s.top()._name << endl;

    // k.set_data("sat",450);

    // s.push(k);
    
    // k.set_data("mil",65.4);

    // s.push(k);

    // k.set_data("moe",123.4);

    // s.push(k);

    // k.set_data("keo",65.2342);

    // s.push(k);

    // k.set_data("seo",232.4);

    // s.push(k);

    // s.get_all();

    // cout << "\n출력 결과 체크\n" <<endl;

    // while(!(s.empty_check())){
    //     indata k = s.pop();
    //     cout << "name : " << k._name << " score : " << k._score << endl;
    // }


    

    return 0;
}

void indata::set_data(string name,double score){
    _name = name;
    _score = score;
}
indata indata::get_data(){
    indata p;
    p.set_data(_name,_score);
    return p;
}

stack::stack(){
    _top = 0;
    _size = 5;
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
        cout << "name : " << p[i]._name << " score : " << p[i]._score << endl;
    }
}