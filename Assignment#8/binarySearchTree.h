// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Assignment #8
// Date due: 04/11/2025
// Description: A BST Program...
// ---------------------------------------------------------------------------
#ifndef H_BINARYSEARCHTREE
#define H_BINARYSEARCHTREE
#include <iostream>
#include <vector>
using namespace std;
template <class elemType>
struct nodeType
{
	elemType info;
	nodeType<elemType> *lLink;
	nodeType<elemType> *rLink;
	/*
	// --------------------------------------------------
	// Code Implementation Start
	// --------------------------------------------------
	*/
	int level; //level is used to store the information of the node's current depth level in the BST (starts at 0 for root)
	/*
	// --------------------------------------------------
	// Code Implementation End
	// --------------------------------------------------
	*/
};
template <class elemType>
class bSearchTreeType
{
	public:
		/*
		// --------------------------------------------------
		// Code Implementation Start
		// --------------------------------------------------
		*/
		int minValue() const; //returns min value in BST
		int maxValue() const; //returns max value in BST
		void displayBST() const; //displays all nodes in the BST
		/*
		// --------------------------------------------------
		// Code Implementation End
		// --------------------------------------------------
		*/
		bSearchTreeType();
		bSearchTreeType(const bSearchTreeType<elemType>& otherTree);
		const bSearchTreeType<elemType>& operator=(const bSearchTreeType<elemType>&);
		~bSearchTreeType();
		bool isEmpty() const;
		void inorderTraversal() const;
		void preorderTraversal() const;
		void postorderTraversal() const;
		int treeHeight() const;
		int treeNodeCount() const;
		int treeLeavesCount() const;
		void destroyTree();
		bool search(const elemType& searchItem) const;
		void insert(const elemType& insertItem);
		void deleteNode(const elemType& deleteItem);
	private:
		/*
		// --------------------------------------------------
		// Code Implementation Start
		// --------------------------------------------------
		*/
		int depthFirstSearch(std::string direction, nodeType<elemType> *nodePointer) const; //helper recursive function for minValue() & maxValue() methods
		void getNodeData(std::vector<nodeType<elemType>*> &nodeDataVector, nodeType<elemType> *nodePointer, nodeType<elemType> *parentNodePointer) const; //helper recursive function for displayBST() method
		/*
		// --------------------------------------------------
		// Code Implementation End
		// --------------------------------------------------
		*/
		nodeType<elemType> *root;
		void copyTree(nodeType<elemType>* &copiedTreeRoot, nodeType<elemType>* otherTreeRoot);
		void destroy(nodeType<elemType>* &p);
		void inorder(nodeType<elemType> *p) const;
		void preorder(nodeType<elemType> *p) const;
		void postorder(nodeType<elemType> *p) const;
		int height(nodeType<elemType> *p) const;
		int max(int x, int y) const;
		int nodeCount(nodeType<elemType> *p) const;
		int leavesCount(nodeType<elemType> *p) const;
		void deleteFromTree(nodeType<elemType>* &p);
};
/*
// --------------------------------------------------
// Code Implementation Start
// --------------------------------------------------
*/
/*
// ---------------------------------------------------------------------------
Description: int bSearchTreeType<elemType>::minValue() const, returns the min value in the BST using depthFirstSearch recursive function
Incoming Data: None
Outgoing Data: this->depthFirstSearch("Left",this->root) (Integer)
// ---------------------------------------------------------------------------
*/
template <class elemType>
int bSearchTreeType<elemType>::minValue() const
{
	return this->depthFirstSearch("Left",this->root);
};
/*
// ---------------------------------------------------------------------------
Description: int bSearchTreeType<elemType>::maxValue() const, returns the max value in the BST using depthFirstSearch recursive function
Incoming Data: None
Outgoing Data: this->depthFirstSearch("Right",this->root) (Integer)
// ---------------------------------------------------------------------------
*/
template <class elemType>
int bSearchTreeType<elemType>::maxValue() const
{
	return this->depthFirstSearch("Right",this->root);
};
/*
// ---------------------------------------------------------------------------
Description: void bSearchTreeType<elemType>::displayBST() const, displays the BST, calls getNodeData to set all node level values & append them to the vector, then creates a 2d array that holds the level (Row) & nodes per level (Column), then does a nested for loop to print each level (Row) of nodes (Column)
Incoming Data: None
Outgoing Data: this->depthFirstSearch("Right",this->root) (Integer)
// ---------------------------------------------------------------------------
*/
template <class elemType>
void bSearchTreeType<elemType>::displayBST() const
{
	if (this->root == nullptr)
	{
		std::cout << "[SYSTEM ERROR] There Are No Nodes To This Binary Search Tree To Display The BST!" << std::endl;
	}
	else
	{
		std::vector<nodeType<elemType>*> nodeDataVector;
		this->getNodeData(nodeDataVector, this->root, nullptr);
		int maxLevel = this->treeHeight();
		std::vector<nodeType<elemType>*> nodeDataArray[maxLevel];
		for (int index = 0; index < nodeDataVector.size(); index++)
		{
			nodeDataArray[nodeDataVector[index]->level].push_back(nodeDataVector[index]);
		};
		std::cout << "--------------------------------------------------" << std::endl;
		for (int level = 0; level < maxLevel; level++)
		{
			std::cout << "Level: [" << level << "]";
			for (int node = 0; node < nodeDataArray[level].size(); node++)
			{
				std::cout << "; [Node Value: " << nodeDataArray[level][node]->info << ", Left Child: " << (nodeDataArray[level][node]->lLink == nullptr ? "NULL" : std::to_string(nodeDataArray[level][node]->lLink->info)) << ", Right Child: " << (nodeDataArray[level][node]->rLink == nullptr ? "NULL" : std::to_string(nodeDataArray[level][node]->rLink->info)) << "]";	
			};
			std::cout << std::endl;
		};
		std::cout << std::endl;
		std::cout << "--------------------------------------------------" << std::endl;
	};
};
/*
// ---------------------------------------------------------------------------
Description: int bSearchTreeType<elemType>::depthFirstSearch(std::string direction, nodeType<elemType> *nodePointer) const, performs a depthFirstSearch recursive algorithm for the min & max value functions, if direction is left, traverses only left nodes and vise versa
Incoming Data: direction (String), nodePointer (nodeType<elemType> Pointer)
Outgoing Data: nodePointer->info (Integer)
// ---------------------------------------------------------------------------
*/
template <class elemType>
int bSearchTreeType<elemType>::depthFirstSearch(std::string direction, nodeType<elemType> *nodePointer) const
{
	if (nodePointer == nullptr)
	{
		std::cout << "[SYSTEM ERROR] There Are No Nodes In This Binary Search Tree To Get The Min/Max Value!" << std::endl;
		return -1;
	}
	else if (direction == "Left" && nodePointer->lLink != nullptr)
	{
		return this->depthFirstSearch(direction,nodePointer->lLink);
	}
	else if (direction == "Right" && nodePointer->rLink != nullptr)
	{
		return this->depthFirstSearch(direction,nodePointer->rLink);
	};
	return nodePointer->info;
};
/*
// ---------------------------------------------------------------------------
Description: void bSearchTreeType<elemType>::getNodeData(std::vector<nodeType<elemType>*> &nodeDataVector, nodeType<elemType> *nodePointer, nodeType<elemType> *parentNodePointer) const, sets the level value of each node and appends it to the nodeDataVector
Incoming Data: nodeDataVector (nodeType<elemType>* Pass By Reference Vector), nodePointer (nodeType<elemType> Pointer For Current Pointer), parentNodePointer (nodeType<elemType> Pointer For Parent Node)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
template <class elemType>
void bSearchTreeType<elemType>::getNodeData(std::vector<nodeType<elemType>*> &nodeDataVector, nodeType<elemType> *nodePointer, nodeType<elemType> *parentNodePointer) const
{
	if (nodePointer != nullptr)
	{
		nodePointer->level = (parentNodePointer == nullptr ? 0 : parentNodePointer->level + 1);
		nodeDataVector.push_back(nodePointer);
		this->getNodeData(nodeDataVector, nodePointer->lLink, nodePointer);
		this->getNodeData(nodeDataVector, nodePointer->rLink, nodePointer);
	};
};
/*
// --------------------------------------------------
// Code Implementation End
// --------------------------------------------------
*/
template <class elemType>
bSearchTreeType<elemType>::bSearchTreeType()
{
	this->root = nullptr;
};
template <class elemType>
bSearchTreeType<elemType>::bSearchTreeType(const bSearchTreeType<elemType>& otherTree)
{
	if (otherTree.root == nullptr)
	{
		this->root = nullptr;
	}
	else
	{
		this->copyTree(this->root, otherTree.root);
	};
};
template <class elemType>
const bSearchTreeType<elemType>& bSearchTreeType<elemType>::operator=(const bSearchTreeType<elemType>& otherTree)
{
	if (this != &otherTree)
	{
		if (this->root != nullptr)
		{
			this->destroy(this->root);
		};
		if (otherTree.root == nullptr)
		{
			this->root = nullptr;
		}
		else
		{
			this->copyTree(this->root, otherTree.root);
		};
	};
	return *this;
};
template <class elemType>
bSearchTreeType<elemType>::~bSearchTreeType()
{
	this->destroy(this->root);
};
template <class elemType>
bool bSearchTreeType<elemType>::isEmpty() const
{
	return (this->root == nullptr);
};
template <class elemType>
void bSearchTreeType<elemType>::inorderTraversal() const
{
	this->inorder(this->root);
};
template <class elemType>
void bSearchTreeType<elemType>::preorderTraversal() const
{
	this->preorder(this->root);
};
template <class elemType>
void bSearchTreeType<elemType>::postorderTraversal() const
{
	this->postorder(this->root);
};
template <class elemType>
int bSearchTreeType<elemType>::treeHeight() const
{
	return this->height(this->root);
};
template <class elemType>
int bSearchTreeType<elemType>::treeNodeCount() const
{
	return this->nodeCount(this->root);
};
template <class elemType>
int bSearchTreeType<elemType>::treeLeavesCount() const
{
	return this->leavesCount(this->root);
};
template <class elemType>
void  bSearchTreeType<elemType>::destroyTree()
{
	this->destroy(this->root);
};
template <class elemType>
bool bSearchTreeType<elemType>::search(const elemType& searchItem) const
{
	nodeType<elemType> *current;
    bool found = false;
    if (this->root == nullptr)
    {
    	std::cout << "Cannot Search An Empty Tree!" << std::endl;
	}
	else
	{
		current = this->root;
		while (current != nullptr && !found)
		{
			if (current->info == searchItem)
			{
				found = true;
			}
			else if (current->info > searchItem)
			{
				current = current->lLink;
			}
			else
			{
				current = current->rLink;
			};
		};
	};
    return found;
};
template <class elemType>
void bSearchTreeType<elemType>::insert(const elemType& insertItem)
{
	nodeType<elemType> *current;
	nodeType<elemType> *trailCurrent = nullptr;
	nodeType<elemType> *newNode;
	newNode = new nodeType<elemType>;
	newNode->info = insertItem;
	newNode->lLink = nullptr;
	newNode->rLink = nullptr;
	if (this->root == nullptr)
	{
		this->root = newNode;
	}
	else
	{
		current = this->root;
		while (current != nullptr)
		{
			trailCurrent = current;
			if (current->info == insertItem)
			{
				std::cout << "The Item To Be Inserted Is Already In The Tree! Duplicates Are Not Allowed!" << std::endl;
				return;
			}
			else if (current->info > insertItem)
			{
				current = current->lLink;
			}
			else
			{
				current = current->rLink;
			};
		};
		if (trailCurrent->info > insertItem)
		{
			trailCurrent->lLink = newNode;
		}
		else
		{
			trailCurrent->rLink = newNode;
		};
	};
};
template <class elemType>
void bSearchTreeType<elemType>::deleteNode(const elemType& deleteItem)
{
	nodeType<elemType> *current;
	nodeType<elemType> *trailCurrent;
	bool found = false;
	if (this->root == nullptr)
	{
		std::cout << "Cannot Delete From An Empty Tree!" << std::endl;
	}
	else
	{
		current = this->root;
		trailCurrent = this->root;
		while (current != nullptr && !found)
		{
			if (current->info == deleteItem)
			{
				found = true;
			}
			else
			{
				trailCurrent = current;
				if (current->info > deleteItem)
				{
					current = current->lLink;
				}
				else
				{
					current = current->rLink;
				};
			};
		};
		if (current == nullptr)
		{
			std::cout << "The Item To Be Deleted Is Not In The Tree." << std::endl;
		}
		else if (found)
		{
            if (current == this->root)
            {
            	deleteFromTree(this->root);
			}
			else if (trailCurrent->info > deleteItem)
			{
				deleteFromTree(trailCurrent->lLink);
			}
			else
			{
				deleteFromTree(trailCurrent->rLink);
			};  
		}
		else
		{
			std::cout << "The Item To Be Deleted Is Not In The Tree." << std::endl;
		};	
	};
};
template <class elemType>
void  bSearchTreeType<elemType>::copyTree(nodeType<elemType>* &copiedTreeRoot, nodeType<elemType>* otherTreeRoot)
{
	if (otherTreeRoot == nullptr)
	{
		copiedTreeRoot = nullptr;
	}
	else
	{
		copiedTreeRoot = new nodeType<elemType>;
		copiedTreeRoot->info = otherTreeRoot->info;
		this->copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
		this->copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
	};
};
template <class elemType>
void  bSearchTreeType<elemType>::destroy(nodeType<elemType>* &p)
{
	if (p != nullptr)
	{
		this->destroy(p->lLink);
		this->destroy(p->rLink);
		delete p;
		p = nullptr;
	};
};
template <class elemType>
void bSearchTreeType<elemType>::inorder(nodeType<elemType> *p) const
{
	if (p != nullptr)
	{
		this->inorder(p->lLink);
		std::cout << p->info << " ";
		this->inorder(p->rLink);
	};
};
template <class elemType>
void bSearchTreeType<elemType>::preorder(nodeType<elemType> *p) const
{
	if (p != nullptr)
	{
		std::cout << p->info << " ";
		this->preorder(p->lLink);
		this->preorder(p->rLink);
	};
};
template <class elemType>
void bSearchTreeType<elemType>::postorder(nodeType<elemType> *p) const
{
	if (p != nullptr)
	{
		this->postorder(p->lLink);
		this->postorder(p->rLink);
		std::cout << p->info << " ";
	};
};
template<class elemType>
int bSearchTreeType<elemType>::height(nodeType<elemType> *p) const
{
	if (p == nullptr)
	{
		return 0;
	}
	else
	{
		return 1 + this->max(this->height(p->lLink), this->height(p->rLink));
	};
};
template <class elemType>
int bSearchTreeType<elemType>::max(int x, int y) const
{
	if (x >= y)
	{
		return x;
	}
	else
	{
		return y;
	};
};
template <class elemType>
int bSearchTreeType<elemType>::nodeCount(nodeType<elemType> *p) const
{
	std::cout << "Write The Definition Of The Function nodeCount!" << std::endl;
	return 0;
};
template <class elemType>
int bSearchTreeType<elemType>::leavesCount(nodeType<elemType> *p) const
{
	std::cout << "Write The Definition Of The Function leavesCount!" << std::endl;
	return 0;
};
template <class elemType>
void bSearchTreeType<elemType>::deleteFromTree(nodeType<elemType>* &p)
{
	nodeType<elemType> *currentNode = p;
	nodeType<elemType> *parentNode = nullptr;
	nodeType<elemType> *tempNode = nullptr;
	if (p == nullptr)
	{
		std::cout << "[SYSTEM ERROR] No Node To Delete!" << std::endl;
	}
	else if (p->lLink == nullptr && p->rLink == nullptr)
	{
		tempNode = p;
		p = nullptr;
		delete tempNode;
	}
	else if (p->lLink == nullptr && p->rLink != nullptr)
	{
		tempNode = p;
		p = p->rLink;
		delete tempNode;
	}
	else if (p->lLink != nullptr && p->rLink == nullptr)
	{
		tempNode = p;
		p = p->lLink;
		delete tempNode;
	}
	else if (p->lLink != nullptr && p->rLink != nullptr)
	{
		currentNode = p->lLink;
		while (currentNode->rLink != nullptr)
		{
			parentNode = currentNode;
			currentNode = currentNode->rLink;
		};
		p->info = currentNode->info;
		if (parentNode != nullptr)
		{
			parentNode->rLink = currentNode->lLink;
		}
		else
		{
			p->lLink = currentNode->rLink;	
		};
		delete currentNode;
	};
};
#endif