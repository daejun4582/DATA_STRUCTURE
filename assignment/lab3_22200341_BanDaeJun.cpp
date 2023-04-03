#include <iostream>

using namespace std;

struct data{
    string name;
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
        int num_nodes();
        double score_max();
        void get_all();
        friend void make_array_from_list(Node array[],LinkedList a);
        void list_merge(LinkedList b);

};

void make_array_from_list(Node array[],LinkedList a);

int main(){

    LinkedList  a;
    Node   tmp;
    tmp.setData("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.setData("Lee", 58.2);
    a.add_to_head(tmp);
    tmp.setData("Park", 91.3);
    a.add_to_head(tmp);
    tmp.setData("Choi", 55.1);
    a.add_to_head(tmp);
    tmp.setData("Ryu", 77.1);
    a.add_to_head(tmp);
    tmp.setData("Yang", 41.3);
    a.add_to_head(tmp);
    tmp.setData("Hong", 78.2);
    a.add_to_head(tmp);
    cout << " --- The contents of the list A ---\n";
    a.get_all();

    double max = a.score_max();
    cout << "\n The max. score  = " << max << endl;
    cout << "\n\n "<< endl;

    Node *s_array;
    int n;
    n = a.num_nodes();
    s_array = new Node[n];
    make_array_from_list(s_array, a);
    cout << "\n --- The contents of the array --- \n";
    for (int k = 0;k < n ;k++)
    cout <<  k << " : " << s_array[k].getData().name << " : " << s_array[k].getData().score << endl;

    LinkedList b;
    tmp.setData("Bae", 88.4);
    b.add_to_head(tmp);
    tmp.setData("Son", 67.2);
    b.add_to_head(tmp);
    tmp.setData("Cho", 97.5);
    b.add_to_head(tmp);
    tmp.setData("Kwon", 77.4);
    b.add_to_head(tmp);

    a.list_merge(b);   
    cout << "\n\n --- The contents of the list A --- \n";
    a.get_all();
    max = a.score_max();
    cout << "\n\n The max. score  = " << max << "\n\n";

    return 0;


}







struct data Node::getData(){
    return a;
}

bool Node::setData(struct data p){
    
    a.name = p.name;
    a.score = p.score;
    return true;
}

bool Node::setData(string n, double s){
    
    a.score = s;
    a.name = n;
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

int LinkedList::num_nodes(){
    Node *t;

    int count = 0;

    for (t = head; t != NULL; t = t->link)
        count++;

    return count;
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






void LinkedList::get_all(){
    Node *t;
    int cnt = 0;
    

    for (t = head; t != NULL; t = t->link){
        cnt++;
        cout << cnt << "번 째 자료 : " <<endl;
        cout << "이름 : "  << t->getData().name << endl;
        cout << "점수 : "  << t->getData().score << endl;
        cout << "\n\n" ;
    }

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








