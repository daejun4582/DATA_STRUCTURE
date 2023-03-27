#include <iostream>

using namespace std;

#ifndef LINKEDLISTSTACK_H_
#define LINKEDLISTSTACK_H_

struct data{
    char token;
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
        LinkedList();
        void add_to_head(Node t);
        Node delete_from_head();
        int num_nodes();
        bool list_empty();
        void get_all();
        Node get_head();
};

class LinkedListStack{
    private:
        LinkedList _p;
    public:
        LinkedListStack();
        void push(struct data p);
        struct data pop();
        struct data top();
        int get_len();
        void get_dataes();
        bool stack_empty();

};




#endif