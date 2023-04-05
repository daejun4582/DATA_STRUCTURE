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
        void add_to_tail(Node t);
        Node delete_from_head();
        Node delete_from_tail();
        bool delete_from_middle(string node_name);
        int num_nodes();
        double score_sum();
        double score_min();
        double score_max();
        double score_mean();
        bool list_empty();
        void get_statics();
        void get_all();

};

string menu[] = {
    "add_to_head          ",
    "add_to_tail          ",
    "delete_from_head     ",
    "delete_from_name     ",
    "get_statics          ",
    "print_all            ",
    "break                "
    };

enum Menus
{
    IN_HEAD,
    IN_TAIL,
    DELETE_FROM_HEAD,
    DELETE_FROM_MIDDLE,
    GET_STACTICS,
    GET_ALL,
    BREAK,
    COUNT
};

void print_menu(string *menu);
void call_in_head            (LinkedList &mylist);
void call_in_tail            (LinkedList &mylist);
void call_delete_from_head   (LinkedList &mylist);
void call_delete_from_middle (LinkedList &mylist);
void call_get_statics        (LinkedList &mylist);
void call_get_all            (LinkedList &mylist);
void run_program             (LinkedList &mylist);

int main(void){
    LinkedList mylist = LinkedList();
    
    run_program(mylist);
    
    return EXIT_SUCCESS;
}

void print_menu(string *menu){

    cout << "\n사용할 명령어를 입력하세요. \n" << endl;
    cout << "--------------------------" << endl;
    cout << "         Menu List" << endl;
    cout << "--------------------------" << endl;


    for(int i = 0; i < Menus::COUNT; i++){
       cout << menu[i] << " [" << i << "]"<<endl;
    }
    cout << "--------------------------" << endl;
    
    cout << "\nCommand : " ;
}

void call_in_head            (LinkedList &mylist){
    Node t;
    struct data indata;

    cout << "입력할 데이터를 입력해주세요 : " << endl;

    cout << "이름  : ";
    cin >> indata.name;

    cout << "점수  : ";
    cin >> indata.score;
    
    t.setData(indata);
    mylist.add_to_head(t);

    cout << "완료되었습니다." << endl;
}
void call_in_tail            (LinkedList &mylist){
    Node t;
    struct data indata;
    cout << "입력할 데이터를 입력해주세요 : " << endl;

    cout << "이름  : ";
    cin >> indata.name;

    cout << "점수  : ";
    cin >> indata.score;
    
    t.setData(indata);
    mylist.add_to_tail(t);

    cout << "완료되었습니다." << endl;
}

void call_delete_from_head   (LinkedList &mylist){
    Node result;

    if(mylist.list_empty() == false){
        result = mylist.delete_from_head();
        cout << "삭제한 학생의 자료는 다음과 같습니다." << endl;
        cout << "----------------------------" << endl;
        cout << "이름 : " << result.getData().name << endl;
        cout << "점수 : " << result.getData().score << endl;
        cout << "완료되었습니다." << endl;
    }
    else{
        cout << "더이상 삭제할 데이터가 존재하지 않습니다." << endl;
    }
}

void call_delete_from_middle (LinkedList &mylist){
    string find;
    if(mylist.list_empty() == false){
        cout << "삭제할 데이터의 이름을 입력해주세요." << endl;
        cin >> find;
        if(mylist.delete_from_middle(find) == true){
            cout << "완료하였습니다." << endl;
        }
        else{
            cout << "실패하였습니다." << endl;
        }
    }
    else{
        cout << "더이상 삭제할 데이터가 존재하지 않습니다." << endl;
    }
}
void call_get_statics        (LinkedList &mylist){
    if(mylist.list_empty() == false){
        mylist.get_statics();
    }
    else{
        cout << "데이터가 존재하지 않습니다" << endl;
    }
}
void call_get_all            (LinkedList &mylist){
    if(mylist.list_empty() == false){
        cout << "\n-----------------------" << endl;
        cout << "현재의 데이터를 출력하겠습니다." << endl;
        cout << "-----------------------" << endl;
        mylist.get_all();
    }
    else {
        cout << "출력할 데이터가 존재하지 않습니다." << endl;
    }
}

void run_program             (LinkedList &mylist){
    int command;
    bool check;

    while(true){
        print_menu(menu);
        cin >> command;
        check = false;
        
        
        switch(command){
            case Menus::IN_HEAD :
                call_in_head(mylist);
                break;
            case Menus::IN_TAIL :
                call_in_tail(mylist);
                break;

            case Menus::DELETE_FROM_HEAD :
                call_delete_from_head(mylist);
                break;
            case Menus::DELETE_FROM_MIDDLE :
                call_delete_from_middle(mylist);
                break;
            case Menus::GET_STACTICS :
                call_get_statics(mylist);
                break;

            case Menus::GET_ALL :
                call_get_all(mylist);
                break;

            case Menus::BREAK :
                cout << "프로그램을 종료하겠습니다" << endl;
                check = true;
                break;
            default :
                cout << "잘못된 명령어 입니다." << endl;
                break;
        }

        if(check == true) break;
    }


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




