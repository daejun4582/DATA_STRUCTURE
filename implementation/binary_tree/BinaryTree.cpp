#include <iostream>
#include </Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/binary_tree/BinaryTree.h>

using namespace std;


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

int BinaryTree::n_d1_nodes(){
    return count_d1_nodes(_root);
}
int BinaryTree::n_d2_nodes(){
    return count_d2_nodes(_root);
}
int BinaryTree::n_leaf_nodes(){
    return count_leaf_nodes(_root);
}


double BinaryTree::get_score_by_name(string name){
    return node_data_find(_root,name);    
}

double BinaryTree::score_sum(){
    return sum_all_nodes(_root);
}

double BinaryTree::score_average(){
    return score_sum() / _node_num;
}

double BinaryTree::score_max(){
    return max_of_nodes(_root);
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

double node_data_find(Node *p, string tname){
    if(p == NULL) return -1;

    if(p ->get_data().name == tname){

        return p->get_data().score;
    }
    else{
            int result = node_data_find(p -> _left, tname);

            if(result != 0)
                return result;
            return node_data_find(p -> _right, tname);

    }
}

int count_d1_nodes(Node *p){
    if(p == NULL) return 0;
    if(p ->_left == NULL && p->_right == NULL) return 0;

    
    int value = 0;

    if(p -> _left != NULL && p ->_right == NULL){
        value = 1;
    } 
    else if(p -> _right != NULL && p ->_left == NULL) {
        value = 1;
    }

    return value + count_d1_nodes(p->_left) + count_d1_nodes(p->_right);
    
    
}

int count_d2_nodes(Node *p){
    if(p == NULL) return 0;
    if(p ->_left == NULL && p->_right == NULL) return 0;

    int value = 0;

    if(p -> _left != NULL && p ->_right != NULL) value = 1;
    

    return value + count_d2_nodes(p->_left) + count_d2_nodes(p->_right);
}
int count_leaf_nodes(Node *p){
    if(p == NULL) return 0;

    if(p ->_left == NULL && p->_right == NULL) return 1;

    return count_leaf_nodes(p->_left) + count_leaf_nodes(p->_right);
}

int sum_all_nodes(Node *p){

    if(p == NULL) return 0;

    return p->get_data().score + sum_all_nodes(p -> _left ) + sum_all_nodes(p -> _right);
}

double max_of_nodes(Node *p){

    if(p == NULL) return -1;
    if(p ->_left == NULL && p->_right == NULL) return p->get_data().score;

    double reuslt_l = max_of_nodes(p->_left);
    double result_r = max_of_nodes(p ->_right);

    double result = (reuslt_l >  result_r)? reuslt_l : result_r;

    return (p->get_data().score > result) ? p ->get_data().score : result;

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