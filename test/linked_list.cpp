#include <iostream>

using namespace std;

typedef struct {
    string name;
    double score;
}indata;

class Node{
    public :
        indata p;
        Node *link;
        void set_data(string n, double s);
};

class LinkedList{
    public:
        Node *head,*tail;  
        LinkedList();
        void add_to_head(Node t);
        void add_to_tail(Node t);

        Node delete_from_head();
        Node delete_from_tail();
        bool delete_by_name(string t_name);
        void delete_low_score(double n);

        double score_sum();
        double score_average();

        double find_score_by_name(string t_name);
        void print_all();
        int num_nodes();
        bool list_empty();

        void invert();
        friend void make_array_from_list(Node array[],LinkedList a);
        friend bool list_equal(LinkedList a, LinkedList b);

};
bool is_equal(Node *p1, Node *p2);

bool  equal_data(Node t1, Node t2);

void make_array_from_list(Node array[],LinkedList a);

int main(void){
    LinkedList  a;
    Node   tmp;
    tmp.set_data("Yang", 41.3);
    a.add_to_head(tmp);
    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("Lee", 58.2);
    a.add_to_head(tmp);
    tmp.set_data("Park", 91.3);
    a.add_to_head(tmp);
    tmp.set_data("Choi", 55.1);
    a.add_to_head(tmp);
    tmp.set_data("Ryu", 77.1);
    a.add_to_head(tmp);
    tmp.set_data("Hong", 78.2);
    a.add_to_head(tmp);
    
    cout << " --- The contents of the list A ---\n";
    a.print_all();

    cout << "\n\n "<< endl;

   a.delete_by_name("Yang");

   cout << "\n\n "<< endl;

   a.print_all();
   

    return 0;
}



void Node::set_data(string n, double s){
    p.name = n;
    p.score = s;
}

LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
}

void LinkedList::add_to_head(Node t){
    Node *p = new Node;
    *p = t;
    
    p ->link = head;

    head = p;

    if(tail == NULL) 
        tail = p;
}

void LinkedList::add_to_tail(Node t){
    Node *p = new Node;
    *p = t;

    p -> link = NULL;

    if(tail != NULL)
        tail -> link = p;
    else
        head = tail;
    
    tail = p;
}


Node LinkedList::delete_from_head(){
    Node *p;
    Node temp;

    //head != NULL 인 상황 즉 데이터가 존재 할때 사용가능
    
    temp = *head;

    p = head;

    head = head -> link;


    delete p;

    if(head == NULL)
        tail = NULL;
    
        
    return temp;
    
}

Node LinkedList::delete_from_tail(){

    Node *pre,*front,*p;
    Node temp;

    //head != NULL 인 상황 즉 데이터가 존재 할때 사용가능

    temp = *tail;
    p = tail;

    pre = NULL;
    front = head;

    while(front -> link != NULL){
        pre = front;
        front = front -> link;
    }

    if(pre == NULL){ //there is only one data in list
        

        tail = tail -> link;

        delete p;

        if(tail == NULL)
            head = NULL;

        return temp;
    }

    tail = pre;
    
    tail -> link = NULL;

    delete p;

    return temp;
}

bool LinkedList::delete_by_name(string t_name){
    Node *find,*front,*pre,*p;
    Node temp;

    //head != NULL 인 상황 즉 데이터가 존재 할때 사용가능

    find = NULL;

    front = head;
    pre = NULL;

    while(front != NULL){
        
        if(front->p.name == t_name){
            find = front;
            break;
        }

        pre = front;
        front = front -> link;
    }


    if(find == NULL)
        return false;
    
    if(pre == NULL){
        temp = delete_from_head();

        cout << temp.p.name << " " << temp.p.score << endl;
    }
    else if(front -> link == NULL){
        temp = delete_from_tail();d

        cout << temp.p.name << " " << temp.p.score << endl;
    }
    else{
        pre -> link = front -> link;

        temp = *find;

        cout << temp.p.name << " " << temp.p.score << endl;

        delete find;
    }

    return true;
        
}

void LinkedList::delete_low_score(double n){
    
    if(head == NULL) return;

    Node *t, *pre, *front;

    pre = NULL;
    front = head;

    while(front -> link != NULL){
        if(pre == NULL && front->p.score < n){

            t = front;
            front = front ->link;

            delete t;
        }
        else if(pre != NULL && front ->p.score < n){

            t = front;

            front = front -> link;

            pre -> link = front ;

            delete t;

        }
        else{
            pre = front;
            front = front -> link;
        }

    }

    if(pre == NULL && front ->p.score < n){
        t = front;

        front = front -> link;

        head = front;
        tail = head;

        delete t;

    }
    else if(pre != NULL && front ->p.score < n){
        t =  front;

        pre -> link = front -> link;

        tail = pre;

        delete t;

    }





}

double LinkedList::score_sum(){
    Node *f;
    double sum = 0;

    for(f = head; f != NULL; f = f->link){
        sum += f->p.score;
    }

    return sum;
}
double LinkedList::score_average(){
    return score_sum()/num_nodes();

}


int LinkedList::num_nodes(){
    int count = 0;
    
    Node *f;

    if(head == NULL) return 0;

    for(f = head; f != NULL; f = f -> link){
        count ++;
    }

    return count;
}

bool LinkedList::list_empty(){
    if(head == NULL) 
        return true;
    return false;
}

double LinkedList::find_score_by_name(string t_name){
    Node *front,*find;

    for(front = head; front != NULL; front = front -> link){

        if(front->p.name == t_name){
            find = front;
            break;
        }

    }

    if(find == NULL)
        return -1;
    return find->p.score;
}

void LinkedList::print_all(){
     Node *f = head;

    if(head == NULL) return;

    for(f = head; f != NULL; f = f ->link){

        cout << f->p.name << " " << f->p.score << endl;

    }

    return;
    
}


void LinkedList::invert(){

    Node *pre,*front,*temp;

    if(head == NULL)
        return;

    front = head;
    pre = NULL;

    while(front != NULL){
        temp = pre;
        pre = front;
        front = front -> link;
        pre -> link = temp;
    }

    tail = head;
    head = pre;

}



void make_array_from_list(Node array[],LinkedList a){
    
    Node *t;
    int idx = 0;

    for(t = a.head; t != NULL; t = t -> link){
        array[idx] = *t;
        idx++;
    }
}


bool list_equal(LinkedList a, LinkedList b){

}
bool is_equal(Node *p1, Node *p2){
    if(p1 == NULL && p2 == NULL)
        return true;
    if(p1 == NULL || p2 == NULL)
        return false;
    if( equal_data (*p1,*p2) )
        return is_equal(p1->link,p2->link);
    else
        return false;
    
}
bool  equal_data(Node t1, Node t2){
    if(t1.p.name == t2.p.name && t1.p.score == t2.p.score)
        return true;
    return false; 
}