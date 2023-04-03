#include <iostream>
#include <cstdlib>

using namespace std;

struct data{
    char token;
};


class Node{
    private:
        struct data a;
    public:
        Node *link;
        bool setData(struct data p);
        struct data getData();
};

class LinkedList{
    private:
        Node *head, *tail;
    public:
        LinkedList();
        void add_to_head(Node t);
        Node delete_from_head();
        int num_nodes();
        bool list_empty();
        void get_all();
        Node get_head();
};

class LinkedListStack{
    private:
        LinkedList _p;
    public:
        LinkedListStack();
        void push(struct data p);
        struct data pop();
        struct data top();
        int get_len();
        void get_dataes();
        bool stack_empty();

};

bool check_panlindrome(string s,LinkedListStack stack);

string preprocess_string(string str);


int main(void){

    string s;

    LinkedListStack stack = LinkedListStack();

    cout << " 문장을 입력해주세요. :  " ;

    getline(cin,s);

    s = preprocess_string(s);

    cout <<  s << endl;

    cout << "본 문장은 회문이 " << (check_panlindrome(s,stack)? "맞습니다." : "아닙니다.") << endl;

    return EXIT_SUCCESS;
}

string preprocess_string(string str){

    string result;

    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    
    for(int i =0; i<str.size(); i++){
        if(isalpha(str[i])!=0)
            result += tolower(str[i]);
    
    }

    return result;
}

bool check_panlindrome(string s, LinkedListStack stack){

    int str_len = s.size();    
    struct data indata;
    char out;

    for(int i = 0; i< (str_len)/2 ; i++) {
        
        indata.token = s[i];
        stack.push(indata);
    }
    
    for(int i = ((str_len % 2 ==0)? str_len/2 : str_len/2 +1);  i < s.size();  i++){

        if(stack.pop().token != s[i]) return false;
        
    }

    return true;

}



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