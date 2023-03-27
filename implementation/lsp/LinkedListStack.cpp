#include <iostream>
#include <cstdlib>
#include </Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/lsp/LinkedListStack.h>

using namespace std;

struct data Node::getData(){
    return a;
}

bool Node::setData(struct data p){
    
    a.token = p.token;

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
        cout << "token : "  << t->getData().token << endl;
        cout << "\n\n" ;
    }

}

Node LinkedList::get_head(){
    return *head;
}


LinkedListStack::LinkedListStack(){
    _p = LinkedList();
}

void LinkedListStack::push(struct data p){
    Node indata = Node();
    indata.setData(p);
    _p.add_to_head(indata);
    
}

struct data LinkedListStack::pop(){
    return _p.delete_from_head().getData();
}

struct data LinkedListStack::top(){

    return _p.get_head().getData();
}


int LinkedListStack::get_len(){
    return _p.num_nodes();
}

void LinkedListStack::get_dataes(){
    _p.get_all();
}

bool LinkedListStack::stack_empty(){
    if(_p.list_empty()) return true;
    return false;
}
