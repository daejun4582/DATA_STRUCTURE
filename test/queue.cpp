#include <iostream>
#define Q_SIZE 5

using namespace std;



class indata {
    public:
        string _name;
        double _score;
        void set_data(string name,double score);
        indata get_data();
};




class queue{
    private:
        int _front,_rear;
        indata _q[Q_SIZE];
    public :
        queue();
        void Enqueue(string name, double score);
        indata Dequeue();
        bool queue_full();
        bool queue_empty();

};



int main(void){
    queue q = queue();
    indata p;

    q.Enqueue("hi",20);
    q.Enqueue("my",20);
    q.Enqueue("me",20);
    q.Enqueue("my",20);

    q.Enqueue("hi",20);

    while(!q.queue_empty()){
        p = q.Dequeue();

        cout << p._name << " " << p._score << endl;
    }
    

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

queue::queue(){
    _front = 0;
    _rear = 0;
}
void queue::Enqueue(string name, double score){
    if(!queue_full()){
        indata t;
        t.set_data(name,score);
        _q[_rear] = t;
        _rear = ( _rear + 1 ) % Q_SIZE ;
        cout << "Enqueue Success" << endl;
    }
    else{
        cout << "Queue is full" << endl;
    }   

}
indata queue::Dequeue(){
    indata t;

    if(!queue_empty())
    {
        t = _q[_front];
        _front = ( _front + 1 ) % Q_SIZE;
        return t;
    }
    else{
        cout << "Queue is empty" << endl;
    }

    return t;
    
}
bool queue::queue_full(){
    if(_front == (_rear + 1) % Q_SIZE)
        return true;
    return false;
}
bool queue::queue_empty(){
    if(_front == _rear)
        return true;
    return false;
}