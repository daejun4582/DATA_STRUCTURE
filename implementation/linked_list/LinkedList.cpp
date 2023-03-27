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

Node LinkedList::delete_from_tail(){
    Node *t, *f, *pre, temp;

    int num_node = num_nodes();

    f = head;

    t = tail;
    temp = *tail;

    pre = NULL;

    while(f -> link != NULL) {
        pre = f;
        f = f -> link;
    }
    
    if(pre == NULL){

        tail = NULL;
        head = NULL;

        delete t;

        return temp;
    }

    tail = pre;
    tail->link = NULL;
    
    delete t;

    if(tail == NULL) head = NULL;

    return temp;
}

bool LinkedList::delete_from_middle(string node_name){
    Node *f, *pre, temp;

    f = head;
    pre = NULL;

    while(f -> link != NULL){
        
        if(f->getData().name == node_name) break;
        pre = f;
        f = f ->link;

    }

    if(f == NULL) return false;


    if(pre == NULL) temp =  delete_from_head();
    else if(f->link == NULL) temp = delete_from_tail();
    else {
        pre-> link = f->link;
        temp = *f;

        delete f;
    }

    cout << "현재 삭제한 데이터의 이름은 " << temp.getData().name <<endl;
    return true;
}

int LinkedList::num_nodes(){
    Node *t;

    int count = 0;

    for (t = head; t != NULL; t = t->link)
        count++;

    return count;
}

double LinkedList::score_sum(){
    Node *t;
    double sum = 0;
    for(t = head; t != NULL; t = t->link){
        sum += t->getData().score;
    }
    return sum;
}

double LinkedList::score_min(){
    Node *t;
    double min = head->getData().score;
    for(t = head; t != NULL; t = t->link){
        if(min > t->getData().score)
            min = t->getData().score;
    }
    return min;
}
double LinkedList::score_max(){
    Node *t;
    double max = head->getData().score;
    for(t = head; t != NULL; t = t->link){
        if(max < t->getData().score)
            max = t->getData().score;
    }
    return max;
}
double LinkedList::score_mean(){
    return score_sum()/num_nodes();
}

bool LinkedList::list_empty(){
    if(head == NULL) return true;
    return false;
}

void LinkedList::get_statics(){
    double max = score_max();
    double min = score_min();
    double sum = score_sum();
    double mean = score_mean();


    cout << "--------------------------" << endl;
    cout << "         statics          " << endl;
    cout << "--------------------------" << endl;
    cout <<"    max      [" << max << "]" << endl;
    cout <<"    min      [" << min << "]" << endl;
    cout <<"    sum      [" << sum << "]" << endl;
    cout <<"    mean     [" << mean << "]" << endl;
    cout << "--------------------------" << endl;
}

double LinkedList::get_score(string node_name){
    Node *t;
    double result = -1;
    for(t = head; t != NULL; t = t->link){

        if(node_name == t->getData().name){
            result =  t->getData().score;
            break;
        }
            
    }
    
    return result;
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

