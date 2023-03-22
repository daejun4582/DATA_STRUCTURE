#include <iostream>
using namespace std;
#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

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
        LinkedList();
        void add_to_head(Node t);
        void add_to_tail(Node t);
        Node delete_from_head();
        int num_nodes();
        bool list_empty();
        void get_all();

};






#endif