// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Assignment #8
// Date due: 04/11/2025
// Description: A BST Program...
// ---------------------------------------------------------------------------
//Dependencies
#include <iostream>
#include "binarySearchTree.h"
//Namespaces
using namespace std;
//Driver
int main()
{
	int temp;
	int nodes;
	bSearchTreeType<int> bst;
	//Test minValue(), maxValue() & displayBST() On An Empty Binary Search Tree
	std::cout << "[SYSTEM MESSAGE] Test minValue() & maxValue() With Empty Binary Search Tree:" << std::endl;
	std::cout << "[SYSTEM MESSAGE] Min Value:" << std::endl;
	bst.minValue();
	std::cout << "[SYSTEM MESSAGE] Max Value:" << std::endl;
	bst.maxValue();
	std::cout << "[SYSTEM MESSAGE] Test displayBST() With Empty Binary Search Tree:" << std::endl;
	bst.displayBST();
	//Prompt User To Input Number Of Nodes To Insert
	std::cout << "[SYSTEM MESSAGE] Please Enter The Number Of Nodes To Insert Into Binary Tree: ";
	std::cin >> nodes;
	//Prompt User To Input The Values For Each Node
	for (int index = 0; index < nodes; index++)
	{
		std::cout << "[SYSTEM MESSAGE] Please Enter The Value For Node [" << index + 1 << "/" << nodes << "] To Insert Into Binary Search Tree: ";
		std::cin >> temp;
		bst.insert(temp);
	};
	//Test Traversals
	std::cout << "In-Order Traversal:" << std::endl;
	bst.inorderTraversal();
	std::cout << std::endl;
	std::cout << "Pre-Order Traversal:" << std::endl;
	bst.preorderTraversal();
	std::cout << std::endl;
	std::cout << "Post-Order Traversal:" << std::endl;
	bst.postorderTraversal();
	std::cout << std::endl;
	//Test minValue(), maxValue() & displayBST() On A Non-Empty Binary Search Tree
	std::cout << "[SYSTEM MESSAGE] Test minValue() & maxValue() With Non-Empty Binary Search Tree:" << std::endl;
	std::cout << "[SYSTEM MESSAGE] Min Value: " << bst.minValue() << std::endl;
	std::cout << "[SYSTEM MESSAGE] Max Value: " << bst.maxValue() << std::endl;
	std::cout << "[SYSTEM MESSAGE] Test displayBST():" << std::endl;
	bst.displayBST();
	std::cout << "[SYSTEM MESSAGE] Program Terminated..." << std::endl;
	return 0;
};