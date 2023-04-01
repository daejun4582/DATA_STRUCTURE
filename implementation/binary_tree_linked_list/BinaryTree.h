#include <iostream>
using namespace std;

#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

struct Node
{
	int data;		//데이터
	Node* left;		//왼쪽 자식노드
	Node* right;		//오른쪽 자식노드
};

class BinaryTreeLinkedList
{
public:
	BinaryTreeLinkedList();				//생성자
	~BinaryTreeLinkedList();			//소멸자
	
	Node* CreateNode();						//노드 생성
	bool GetData(Node* node, int& data);	//값 반환
	bool SetData(Node* node, int data);		//값 지정

	bool GetLeftNode(Node* parent, Node** node);	//노드의 왼쪽 자식노드 반환
	bool GetRightNode(Node* parent, Node** node);	//노드의 오른쪽 자식노드 반환

	bool SetLeftNode(Node* parent, Node* child);	//노드의 왼쪽 자식노드 지정
	bool SetRightNode(Node* parent, Node* child);	//노드의 오른쪽 자식노드 지정

	void PreorderPrint(Node* node);			//전위 순회
	void InorderPrint(Node* node);			//중위 순회
	void PostorderPrint(Node* node);		//후위 순회

	void RemoveNode(Node* node);			//노드 제거
};



#endif