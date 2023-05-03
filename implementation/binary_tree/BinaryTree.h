#include <iostream>
using namespace std;

#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__


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

		int n_d1_nodes();
        int n_d2_nodes();
        int n_leaf_nodes();

		double get_score_by_name(string name);

		double score_sum();
		double score_average();
		double score_max();

		void print_data_inorder();
		void print_data_preorder();
		void print_data_postorder();

};

int node_insert_left(Node *p, string tname, Node t);
int node_insert_right(Node *p, string tname, Node t);
int node_find_node(Node *p, string tname,Node *t);

int count_d1_nodes(Node *p);
int count_d2_nodes(Node *p);
int count_leaf_nodes(Node *p);

int sum_all_nodes(Node *p);
double max_of_nodes(Node *p);

void print_inorder(Node *p);
void print_preorder(Node *p);
void print_postorder(Node *p);
		
double node_data_find(Node *p, string tname);


#endif