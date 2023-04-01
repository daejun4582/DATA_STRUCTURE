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
    private:
        Node *head, *tail;
    public:
        LinkedList();
        void insert_node(Node t);
        void delete_low_score(double n);
        bool list_empty();
        void show_all_data();

};

int main(void){

    LinkedList  thelist;

    Node   tmp;

        tmp.set_data("Kim", 73.5);

        thelist.insert_node(tmp);

        tmp.set_data("Lee", 82.2);

        thelist.insert_node(tmp);

        tmp.set_data("Park", 51.3);

        thelist.insert_node(tmp);

        tmp.set_data("Choi", 95.1);

        thelist.insert_node(tmp);

        tmp.set_data("Ryu", 71.3);

        thelist.insert_node(tmp);

        tmp.set_data("Yang", 58.2);

        thelist.insert_node(tmp);

        tmp.set_data("Hong", 83.5);

        thelist.insert_node(tmp);

        cout << " The list after insertions \n";

        thelist.show_all_data();       

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

void LinkedList::insert_node(Node t){
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
        
        if(t._score > (*f)._score ){
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
    else if(t._score > (*f)._score){
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