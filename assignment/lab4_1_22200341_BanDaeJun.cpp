#include <iostream>


using namespace std;

struct data{
	string name;
    double score;
};

class Node
{
	private:
		struct data _d;
	public:
		Node *_left, *_right;
		void set_data(struct data t);
		void set_data(string name, double score);
		struct data get_data();
};

class  BinaryTree {
	public :
		Node* _root;
		int _node_num;
	
		BinaryTree();
		~BinaryTree();
		int insert_root(Node t);
		int insert_left(string name, Node t);
		int insert_right(string name, Node t);

		double score_sum();
		double score_average();

		void print_data_inorder();
		void print_data_preorder();
		void print_data_postorder();

};

int node_insert_left(Node *p, string tname, Node t);
int node_insert_right(Node *p, string tname, Node t);

int node_find_node(Node *p, string tname,Node *t);

int sum_all_nodes(Node *p);


void print_inorder(Node *p);
void print_preorder(Node *p);
void print_postorder(Node *p);


int main()
{
        BinaryTree  thetree;
        Node  tmp;

        tmp.set_data("Kim", 81.1);
        thetree.insert_root(tmp);
        tmp.set_data("Lee", 86.2);
        thetree.insert_left("Kim", tmp);
        tmp.set_data("Park", 79.4);
        thetree.insert_right("Kim", tmp);
        tmp.set_data("Choi", 77.8);
        thetree.insert_left("Lee", tmp);
        tmp.set_data("Ryu", 92.2);
        thetree.insert_right("Lee", tmp);
        tmp.set_data("Cho", 68.6);
        thetree.insert_right("Park", tmp);
        tmp.set_data("Yang", 72.8);
        thetree.insert_left("Ryu", tmp);
        tmp.set_data("Jung", 62.3);
        thetree.insert_left("Cho", tmp);       
        cout<< "Score Sum : " << thetree.score_sum() << "\n";
        cout<< "Score Average : " << thetree.score_average() << "\n";
        cout <<"\n Inorder Traversal Result \n";
        thetree.print_data_inorder();
        cout << "\n Preorder Traversal Result \n";
        thetree.print_data_preorder();
        cout << "\n Postorder Traversal Result \n";
        thetree.print_data_postorder();

        return 0;

}        



void Node::set_data(struct data t){
    _d = t;
}

void Node::set_data(string name, double score){
    _d.name = name;
    _d.score = score;
}

struct data Node:: get_data(){
    return _d;
}

BinaryTree::BinaryTree(){
    _root = NULL;
    _node_num = 0;
}

BinaryTree::~BinaryTree(){
    delete _root;
}

int BinaryTree::insert_root(Node t){
    if(_root != NULL) return 0;

    Node *temp = new Node;

    *temp = t;

    temp->_left = NULL;

    temp->_right = NULL;

    _root = temp;

    _node_num++;

    return 1;
}

int BinaryTree::insert_left(string name, Node t){
    int result;

    result = node_insert_left(_root,name,t);

    if(result == 1)
        _node_num ++;
    return result;
}

int BinaryTree::insert_right(string name, Node t){
    int result;

    result = node_insert_right(_root,name,t);

    if(result == 1)
        _node_num ++;
    return result;
}

double BinaryTree::score_sum(){
    return sum_all_nodes(_root);
}

double BinaryTree::score_average(){
    return score_sum() / _node_num;
}


void BinaryTree::print_data_inorder(){
    print_inorder(_root);
}

void BinaryTree::print_data_preorder(){
    print_preorder(_root);
}

void BinaryTree::print_data_postorder(){
    print_postorder(_root);
}

int node_insert_left(Node *p, string tname, Node tnode){

    if(p == NULL) return 0;
    if(p ->get_data().name == tname){
        if( p -> _left != NULL){
            return -1;
        }
        Node *t = new Node;

        *t = tnode;

        t -> _right = NULL;

        t -> _left = NULL;
        
        p-> _left = t;

        return 1;
    }
    else{
            int result = node_insert_left(p -> _left, tname, tnode);
            if(result != 0)
                return result;
            return node_insert_left(p -> _right, tname, tnode);

    }
}

int node_insert_right(Node *p, string tname, Node tnode){

    if(p == NULL) return 0;
    if(p ->get_data().name == tname){
        if( p -> _right != NULL){
            return -1;
        }
        Node *t = new Node;

        *t = tnode;

        t -> _right = NULL;

        t -> _left = NULL;
        
        p-> _right = t;

        return 1;
    }
    else{
            int result = node_insert_right(p -> _left, tname, tnode);
            if(result != 0)
                return result;
            return node_insert_right(p -> _right, tname, tnode);

    }
}

int sum_all_nodes(Node *p){

    if(p == NULL) return 0;

    return p->get_data().score + sum_all_nodes(p -> _left ) + sum_all_nodes(p -> _right);
}

void print_inorder(Node *p){

    if(p == NULL) return;

    print_inorder(p -> _left);

    cout << p->get_data().name << " : " << p->get_data().score << endl;

    print_inorder(p -> _right);
}

void print_preorder(Node *p){
    if(p == NULL) return;

    cout << p->get_data().name << " : " << p->get_data().score << endl;
    
    print_preorder(p -> _left);
    
    print_preorder(p -> _right);
}

void print_postorder(Node *p){

    if(p == NULL) return;

    print_postorder(p -> _left);
    
    print_postorder(p -> _right);

    cout << p->get_data().name << " : " << p->get_data().score << endl;
}