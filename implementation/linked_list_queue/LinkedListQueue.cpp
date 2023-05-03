#include <iostream>
#include </Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/linked_list_queue/LinkedListQueue.h>

struct data Node::getData(){
    return a;
}

bool Node::setData(struct data p){
    
    a.id = p.id;
    a.name = p.name;
    a.score = p.score;
    return true;
}


LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
}


void LinkedList::add_to_tail(Node t){
    Node *p;
    p = new Node;
    (*p) = t;
    p ->link = head;

    if(tail != head)
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

    for (t = head; t -> link != head; t = t->link)
        count++;

    return count;
}
bool LinkedList::list_empty(){
    if(head == NULL) return true;
    return false;
}
bool LinkedList::list_full(){
    if(tail -> link == head) return true;
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









bool LinkedListQueue::Enqueue(struct data indata){
    Node t;
    t.setData(indata);
    _q.add_to_tail(t);
    return true;
}
struct data LinkedListQueue::Dequeue(){
    Node result = _q.delete_from_head();
    return result.getData();
}


bool LinkedListQueue::Queue_full(){
    if(_q.list_full()) return true;
    return false;
}
bool LinkedListQueue::Queue_empty(){
    if(_q.list_empty()) return true;
    return false;
}
void LinkedListQueue::get_all_dataes(){
    _q.get_all();
}