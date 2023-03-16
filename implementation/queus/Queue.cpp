#include <iostream>
#include <cstdlib>
#include </Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/queus/Queue.h>

using namespace std;



Queue::Queue(){
    _front = 0;
    _rear = 0;
    _size = 5;
    _N = 0;
    _que = new indata[_size];
}

bool Queue::Enqueue(indata que){
    if(!(Queue_full())){
        _que[_rear] = que;
        _rear = (_rear+1)%_size;
        _N ++;
        return true;
    }

    return false;
}

indata Queue::Dequeue(){
    _N--;
    indata temp = _que[_front];
    _front = (_front+1) % _size ;
    return temp;
}
bool Queue::Queue_full(){
    if((_rear+1)%_size == _front) return true;
    return false;

}
bool Queue::Queue_empty(){
    if(_rear == _front) return true;
    return false;

}
void Queue::get_all(){
    for(int i = _front; i < _rear; i++){
        cout << _que[i].a << " ";
    }
    cout << endl;
}

void Queue::get_data(){
    cout << _front << " " << _rear << endl;
}







