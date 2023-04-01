#include <iostream>
#include </Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/binary_tree_linked_list/BinaryTree.h>

using namespace std;

BinaryTreeLinkedList::BinaryTreeLinkedList()
{
	printf("생성자\n");
}

BinaryTreeLinkedList::~BinaryTreeLinkedList()
{
	printf("소멸자\n");
}

Node* BinaryTreeLinkedList::CreateNode()
{
	Node* newNode = new Node;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

bool BinaryTreeLinkedList::GetData(Node* node, int& data)
{
	if (node == NULL)
		return false;

	data = node->data;
	printf("GetData : %d\n", data);
	return true;
}

bool BinaryTreeLinkedList::SetData(Node* node, int data)
{
	if (node == NULL)
		return false;

	node->data = data;
	printf("SetData : %d\n", node->data);
	return true;
}

bool BinaryTreeLinkedList::GetLeftNode(Node* parent, Node** node)
{
	if (parent == NULL || parent->left == NULL)
	{
		*node = NULL;
		return false;
	}

	*node = parent->left;
	printf("GetLeftNode : %d\n", (*node)->data);
	return true;
}

bool BinaryTreeLinkedList::GetRightNode(Node* parent, Node** node)
{
	if (parent == NULL || parent->right == NULL)
	{
		*node = NULL;
		return false;
	}

	*node = parent->right;
	printf("GetRightNode : %d\n", (*node)->data);
	return true;
}

bool BinaryTreeLinkedList::SetLeftNode(Node* parent, Node* child)
{
	if (parent == NULL || child == NULL)
		return false;

	if (parent->left != NULL)				//이미 왼쪽 자식노드가 있으면
		RemoveNode(parent->left);			//왼쪽 자식노드를 지워준다.

	parent->left = child;
	printf("Set %d Node's LeftData : %d\n", parent->data, child->data);
	return true;
}

bool BinaryTreeLinkedList::SetRightNode(Node* parent, Node* child)
{
	if (parent == NULL || child == NULL)
		return false;

	if (parent->right != NULL)				//이미 오른쪽 자식노드가 있으면
		RemoveNode(parent->right);			//오른쪽 자식 노드를 지워준다.

	parent->right = child;
	printf("Set %d Node's RightData : %d\n", parent->data, child->data);
	return true;
}

void BinaryTreeLinkedList::PreorderPrint(Node* node)
{
	if (node == NULL)
		return;

	printf("Pre : %d\n", node->data);
	PreorderPrint(node->left);
	PreorderPrint(node->right);
}

void BinaryTreeLinkedList::InorderPrint(Node* node)
{
	if (node == NULL)
		return;

	InorderPrint(node->left);
	printf("In : %d\n", node->data);
	InorderPrint(node->right);
}

void BinaryTreeLinkedList::PostorderPrint(Node* node)
{
	if (node == NULL)
		return;

	PostorderPrint(node->left);
	PostorderPrint(node->right);
	printf("Post : %d\n", node->data);
}

void BinaryTreeLinkedList::RemoveNode(Node* node)
{
	if (node == NULL)
		return;

	RemoveNode(node->left);					//지우는 방식은 후위 순회방식으로
	RemoveNode(node->right);
	printf("Delete : %d\n", node->data);
	delete node;
}