#include <iostream>

using namespace std;

#ifndef LINKEDLISTQUEUE_H_
#define LINKEDLISTQUEUE_H_

struct data{
    string name;
    string id;
    double score;
};

class Node{
    private:
        struct data a;
    public:
        Node *link;
        bool setData(struct data p);
        struct data getData();
};

class LinkedList{
    private:
        Node *head, *tail;
    public:
        int _QSIZE;
        LinkedList();
        void add_to_tail(Node t);
        Node delete_from_head();
        int num_nodes();
        bool list_empty();
        bool list_full();
        void get_all();
};

class LinkedListQueue{
    private:
        LinkedList _q;
    public:
        LinkedListQueue();
        bool Enqueue(struct data indata);
        struct data Dequeue();
        bool Queue_full();
        bool Queue_empty();
        void get_all_dataes();
};




#endif