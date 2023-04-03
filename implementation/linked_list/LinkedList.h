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
        bool setData(string n, double s);
        struct data getData();
};

class LinkedList{
    
    public:
        Node *head, *tail;
    
        LinkedList();
        void add_to_head(Node t);
        void add_to_tail(Node t);
        void add_insorting(Node t);
        Node delete_from_head();
        Node delete_from_tail();
        bool delete_from_middle(string node_name);
        void delete_low_score(double n);
        void delete_low_score_faster(double n);
        int num_nodes();
        double score_sum();
        double score_min();
        double score_max();
        double score_mean();
        bool list_empty();
        void get_statics();
        double get_score(string node_name);
        void get_all();
        void invert();
        friend void make_array_from_list(Node array[],LinkedList a);
        void list_merge(LinkedList b);
        friend bool list_equal(LinkedList a, LinkedList b);

};

bool is_equal(Node *p1, Node *p2);

bool  equal_data(Node t1, Node t2);

void make_array_from_list(Node array[],LinkedList a);






#endif