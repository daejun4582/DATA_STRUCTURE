#include <iostream>

using namespace std;

#ifndef LINKEDLISTQUEUE_H_
#define LINKEDLISTQUEUE_H_

#include </Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/linked_list/LinkedList.h>


class LinkedListQueue{
    private:
        LinkedList _q;
    public:
        LinkedListQueue();
        bool Enqueue(struct data indata);
        struct data Dequeue();
        bool Queue_empty();
        void get_all_dataes();
};




#endif