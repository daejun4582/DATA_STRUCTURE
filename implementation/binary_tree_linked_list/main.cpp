#include <iostream>
#include <cstdlib>
#include </Users/bandaejun/Documents/GitHub/DATA_STRUCTURE/implementation/binary_tree_linked_list/BinaryTree.h>

using namespace std;

int main(void){

   BinaryTreeLinkedList* ListBinaryTree = new BinaryTreeLinkedList();

	Node* tempANode = ListBinaryTree->CreateNode();
	Node* tempBNode = ListBinaryTree->CreateNode();
	Node* tempCNode = ListBinaryTree->CreateNode();
	Node* tempDNode = ListBinaryTree->CreateNode();
	Node* tempENode = ListBinaryTree->CreateNode();
	Node* tempFNode;

	ListBinaryTree->SetData(tempANode, 1);
	ListBinaryTree->SetData(tempBNode, 2);
	ListBinaryTree->SetData(tempCNode, 3);
	ListBinaryTree->SetData(tempDNode, 4);
	ListBinaryTree->SetData(tempENode, 5);

	printf("\n");
	ListBinaryTree->SetLeftNode(tempANode, tempBNode);
	ListBinaryTree->SetRightNode(tempANode, tempCNode);
	ListBinaryTree->SetData(tempANode->left, 20);		//왼쪽 자식 노드 값 변경

	printf("\n");
	ListBinaryTree->GetRightNode(tempANode, &tempFNode);	//오른쪽 자식 노드 가져와서
	ListBinaryTree->SetData(tempFNode, 30);			//그 노드의 값 변경

	printf("\n");
	ListBinaryTree->GetLeftNode(tempANode, &tempFNode);
	ListBinaryTree->SetLeftNode(tempFNode, tempDNode);
	ListBinaryTree->SetRightNode(tempFNode, tempENode);

	printf("\n");

	int data;
	ListBinaryTree->GetData(tempANode, data);
	ListBinaryTree->GetData(tempBNode, data);
	ListBinaryTree->GetData(tempCNode, data);
	ListBinaryTree->GetData(tempDNode, data);
	ListBinaryTree->GetData(tempENode, data);
	ListBinaryTree->GetData(tempFNode, data);

	printf("\n");
	ListBinaryTree->PreorderPrint(tempANode);
	printf("\n");
	ListBinaryTree->InorderPrint(tempANode);
	printf("\n");
	ListBinaryTree->PostorderPrint(tempANode);

	printf("\n");
	ListBinaryTree->RemoveNode(tempANode);
	delete ListBinaryTree;


    return EXIT_SUCCESS;
}