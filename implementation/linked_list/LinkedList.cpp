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

bool Node::setData(string n, double s){
    
    a.score = s;
    a.name = n;
    a.id = 22;
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

void LinkedList::add_insorting(Node t){
    Node *p, *f, *pre ,temp;
    p = new Node;


    if(head == NULL){
        (*p) = t;
        p->link = head;
        head = p;
        if(tail == NULL) tail = p;
        return;
    }

    f = head;
    pre = NULL;

    while(f -> link != NULL){
        
        if(t.getData().score > f->getData().score ){
            pre = f;
            f = f ->link;
        }
        else if(pre == NULL){
            (*p) = t;
            p->link = head;
            head = p;
            return;
        }
        else{
            (*p) = t;
            p -> link = f;
            pre -> link = p;
            return;

        }

    }

    if(f == NULL){
        (*p) = t;
        p ->link = NULL;
        pre ->link = p;
        tail = p;
        return;
        }
    else if(t.getData().score > f->getData().score){
        (*p) = t;
        p ->link = NULL;
        f ->link = p;
        tail = p;
        return;
    }
    else if(pre == NULL){

        (*p) = t;
        p->link = head;
        head = p;
        return;
    }
    else {

        (*p) = t;
        p -> link = f;
        pre -> link = p;
        return;
    }


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

void LinkedList::delete_low_score(double n){

    if(head == NULL) return;

    Node *t;

    string delete_list[num_nodes()];

    int idx = 0;

    for(t = head; t != NULL; t = t->link){
        if(t->getData().score < n){
            delete_list[idx] = t->getData().name;
            idx++;
        }
            
    }

    for(int i = 0; i < idx; i++){
        delete_from_middle(delete_list[i]);
    }

}

void LinkedList::delete_low_score_faster(double n){
    Node *new_node, *old_node, *temp;
    
    if(head == NULL) return;

    new_node = head;
    old_node = NULL;  
    
    while(new_node -> link != NULL){

        if(new_node->getData().score < n && old_node != NULL){

            temp = new_node;
            new_node = new_node->link;
            old_node->link = new_node;

            delete temp;

            
        }
        else if(new_node->getData().score < n && old_node == NULL){
            temp = new_node;
            new_node = new_node->link;
            head = new_node;
            delete temp;

        }
        else{
            old_node = new_node;
            new_node = new_node -> link;
        }
        
    }

    if(new_node->getData().score < n){
        temp = new_node;
        new_node = new_node->link;
        tail = old_node;
        tail->link = NULL;
        if(new_node == NULL) head = NULL;

        delete temp;
    }
    else{
        tail = new_node;
        tail -> link = NULL;
    }

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

void LinkedList::invert(){

    Node *newhead = NULL,*oldhead = head,*tmp;

    while(oldhead != NULL){
        tmp = newhead;
        newhead = oldhead;
        oldhead = oldhead ->link;
        newhead ->link = tmp;
    }
    
    tail = head;
    head = newhead;

}

void LinkedList::list_merge(LinkedList b){
    if(head == NULL){
        return;
    }
    Node *t;
    t = head;
    while(t -> link != NULL){
        t = t-> link;
    }
    t->link = b.head;

}

void make_array_from_list(Node array[],LinkedList a){
    Node *t;
    int idx  = 0;

    for(t = a.head; t != NULL; t = t -> link){
        array[idx] = *t;
        idx++;
    }
}

bool list_equal(LinkedList a, LinkedList b){
    return is_equal(a.head, b.head);
    }

bool is_equal(Node *p1, Node *p2){
    if ( (p1 == NULL) &&  (p2 == NULL) )
        return true;
    if ( (p1 == NULL) ||  (p2 == NULL) )  // AND 조건은 처리 되었으므로, OR 조건 가능
        return false;
    if ( equal_data(*p1, *p2) )
        return(is_equal(p1->link, p2->link));
    else
        return false;
    }

bool  equal_data(Node t1, Node t2){
    if (t1.getData().name != t2.getData().name)
        return false;
    if (t1.getData().score != t2.getData().score)
        return false;
    return true;
    }

