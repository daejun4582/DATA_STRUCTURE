#include <iostream>
#include <cstdlib>
#include </Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/linked_list/LinkedList.h>

using namespace std;



struct data Node::getData(){
    return a;
}

bool Node::setData(struct data p){
    
    a.id = p.id;
    a.name = p.name;
    a.score = p.score;
    return true;
}



LinkedList::LinkedList (){
    head = NULL;
    tail = NULL;
}

void LinkedList::add_to_head(Node t){
    Node *p;
    p = new Node;
    (*p) = t;
    p->link = head;
    head = p;
    if(tail == NULL) tail = p;
}

void LinkedList::add_to_tail(Node t){
    Node *p;
    p = new Node;
    (*p) = t;
    p ->link = NULL;
    if(tail != NULL)
        tail->link = p;
    else
        head = p;
    tail = p;
}

Node LinkedList::delete_from_head(){
    Node *t;
    Node temp;

    t = head;
    temp = *head;
    head  = head->link;

    delete t;

    if(head == NULL) tail = NULL;
    
    return temp;
}

int LinkedList::num_nodes(){
    Node *t;

    int count = 0;

    for (t = head; t != NULL; t = t->link)
        count++;

    return count;
}

bool LinkedList::list_empty(){
    if(head == NULL) return true;
    return false;
}

void LinkedList::get_all(){
    Node *t;
    int cnt = 0;
    

    for (t = head; t != NULL; t = t->link){
        cnt++;
        cout << cnt << "번 째 자료 : " <<endl;
        cout << "이름 : "  << t->getData().name << endl;
        cout << "학번 : "  << t->getData().id  << endl;
        cout << "점수 : "  << t->getData().score << endl;
        cout << "\n\n" ;
    }


    
}
