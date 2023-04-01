#include <iostream>
#include <cstdlib>

using namespace std;



class Node{
    public:
        string _name;
        double _score;
        Node *link;
        bool set_data(string name, double score);
};

class LinkedList{
    // private:
        
    public:
        Node *head, *tail;
        LinkedList();
        void add_to_head(Node t);
        void delete_low_score(double n);
        bool list_empty();
        void show_all_data();

};



int main(void){
    LinkedList a;
    Node   tmp;
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

    tmp.set_data("Yang", 41.3);

    a.add_to_head(tmp);

    tmp.set_data("Hong", 78.2);

    a.add_to_head(tmp);

    cout << "The list before deletion \n";

    a.show_all_data();

    a.delete_low_score(60.0);

    cout << "\n\nThe list after deletion \n";

    a.show_all_data();


    return EXIT_SUCCESS;
}


bool Node::set_data(string name, double score){
    _name = name;
    _score = score;
    
    return true;
}

LinkedList::LinkedList (){
    head = NULL;
    tail = NULL;
}

bool LinkedList::list_empty(){
    if(head == NULL) return true;
    return false;
}

void LinkedList::add_to_head(Node t){
    Node *p;
    p = new Node;
    (*p) = t;
    p->link = head;
    head = p;
    if(tail == NULL) tail = p;
}

void LinkedList::show_all_data(){
    Node *t;
    int cnt = 0;
    

    for (t = head; t != NULL; t = t->link){
        cnt++;
        cout << cnt << "번 째 자료 : " <<endl;
        cout << "이름 : "  << t->_name << endl;
        cout << "점수 : "  << t->_score << endl;
        cout << "\n\n" ;
    }

}

void LinkedList::delete_low_score(double n){
    Node *new_node, *old_node, *temp;
    
    if(head == NULL) return;

    new_node = head;
    old_node = NULL;  
    
    while(new_node -> link != NULL){

        if(new_node->_score < n && old_node != NULL){
            // cout << "1 "<< endl;
            temp = new_node;
            new_node = new_node->link;
            old_node->link = new_node;

            delete temp;

            
        }
        else if(new_node->_score < n && old_node == NULL){
            // cout << "2 "<< endl;
            temp = new_node;
            new_node = new_node->link;
            head = new_node;
            delete temp;

        }
        else{
            // cout << "3 "<< endl;
            old_node = new_node;
            new_node = new_node -> link;
        }
        
    }

     if(new_node->_score < n){
        // cout << "4 "<< endl;
        temp = new_node;
        tail = old_node;


        if(tail != NULL)
            tail ->link = NULL;
        else{
            head = NULL;
        }

        delete temp;
        }
    else{
        // cout << "5 "<< endl;
        tail = new_node;
        tail -> link = NULL;
    }
}