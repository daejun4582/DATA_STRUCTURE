#ifndef __QUEUE_H__
#define __QUEUE_H__


struct indata{
    int a;
};

class Queue{
    private:
        int _front;
        int _rear;
        int _size;
        int _N;
        indata* _que;
    public:
        Queue();
        bool Enqueue(indata que);
        indata Dequeue();
        bool Queue_full();
        bool Queue_empty();
        void get_all();
        void get_data();
};





#endif