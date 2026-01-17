#ifndef H_AVLTREE
#define H_AVLTREE
#include <iostream>
#include <iomanip>
template <class dataType>
struct AVLNode
{
	dataType info;
	int balanceFactor;
	AVLNode<dataType>* leftLink;
	AVLNode<dataType>* rightLink;
};
template <class dataType>
class AVLTree
{
	public:
		AVLTree();
		void insert(const dataType &newInfo);
		
		
		
		
		
		void myInsert(const dataType newInfo);
		void myInsertRecursive(const dataType newInfo, AVLNode<dataType>* &currentAVLNode);
		int fixBalanceFactors(AVLNode<dataType>* &currentAVLNode);
		
		
		void printTree() const;
		void printTree(AVLNode<dataType>* node, int indent) const;
	private:
		AVLNode<dataType>* rootAVLNode;
		void insertIntoAVL(AVLNode<dataType>* &currentAVLNode, AVLNode<dataType> *newNode, bool &isTaller);
		void balanceFromLeft(AVLNode<dataType>* &currentAVLNode);
		void balanceFromRight(AVLNode<dataType>* &currentAVLNode);
		void rotateToLeft(AVLNode<dataType>* &currentAVLNode);
		void rotateToRight(AVLNode<dataType>* &currentAVLNode);
};











template <class dataType>
void AVLTree<dataType>::myInsert(const dataType newInfo)
{
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "INSERTING NEW NODE: " << newInfo << std::endl;
	this->myInsertRecursive(newInfo, this->rootAVLNode);
	//INEFFICIENT & HACKY METHOD TO FIX ALL BALANCE FACTORS!
	if (this->rootAVLNode != nullptr)
	{
		this->rootAVLNode->balanceFactor = this->fixBalanceFactors(this->rootAVLNode->rightLink) - this->fixBalanceFactors(this->rootAVLNode->leftLink);
		std::cout << "(HACKY & INEFFICIENT) FIX BALANCE FACTORS!" << std::endl;
	};
	this->printTree();
	std::cout << "--------------------------------------------------" << std::endl;
};
template <class dataType>
void AVLTree<dataType>::myInsertRecursive(const dataType newInfo, AVLNode<dataType>* &currentAVLNode)
{
	if (currentAVLNode == nullptr)
	{
		AVLNode<dataType> *newAVLNode = new AVLNode<dataType>;
		newAVLNode->info = newInfo;
		newAVLNode->balanceFactor = 0;
		newAVLNode->leftLink = nullptr;
		newAVLNode->rightLink = nullptr;
		currentAVLNode = newAVLNode;
		std::cout << "--------------------------------------------------" << std::endl;
		std::cout << "NEW NODE INSERTED: " << newInfo << std::endl;
		this->printTree();
		std::cout << "--------------------------------------------------" << std::endl;
	}
	else if (currentAVLNode->info == newInfo)
	{
		std::cout << "[SYSTEM ERROR] No Duplicates Allowed! Attempted To Insert: " << newInfo << std::endl;	
	}
	else if (newInfo < currentAVLNode->info)
	{
		this->myInsertRecursive(newInfo, currentAVLNode->leftLink);
		if (currentAVLNode->balanceFactor == 0)
		{
			currentAVLNode->balanceFactor = -1;
		}
		else if (currentAVLNode->balanceFactor == 1)
		{
			currentAVLNode->balanceFactor = 0;
		}
		else if (currentAVLNode->balanceFactor == -1)
		{
			if (currentAVLNode->leftLink->balanceFactor == -1)
			{
				//LEFT ROTATION!
				std::cout << "(LL) LEFT-LEFT IMBALANCE! PERFORM A RIGHT ROTATION!" << std::endl;
				currentAVLNode->balanceFactor = 0;
				AVLNode<dataType> *tempAVLNode = currentAVLNode->leftLink;
				tempAVLNode->balanceFactor = 0;
				currentAVLNode->leftLink = tempAVLNode->rightLink;
				tempAVLNode->rightLink = currentAVLNode;
				currentAVLNode = tempAVLNode;
				std::cout << "--------------------------------------------------" << std::endl;
				std::cout << "LEFT ROTATION!" << std::endl;
				this->printTree();
				std::cout << "--------------------------------------------------" << std::endl;
			}
			else if (currentAVLNode->leftLink->balanceFactor == 1)
			{
				std::cout << "(LR) LEFT-RIGHT IMBALANCE! PERFORM A LEFT-RIGHT ROTATION!" << std::endl;
				//LEFT ROTATION ON LEFT CHILD!
				currentAVLNode->balanceFactor = 0;
				currentAVLNode->leftLink->balanceFactor = 0;
				AVLNode<dataType> *tempLeftChildAVLNode = currentAVLNode->leftLink;
				currentAVLNode->leftLink = tempLeftChildAVLNode->rightLink;
				tempLeftChildAVLNode->rightLink->leftLink = tempLeftChildAVLNode;
				tempLeftChildAVLNode->rightLink = nullptr;
				std::cout << "--------------------------------------------------" << std::endl;
				std::cout << "LEFT ROTATION!" << std::endl;
				this->printTree();
				std::cout << "--------------------------------------------------" << std::endl;
				//RIGHT ROTATION ON CURRENT AVL NODE!
				AVLNode<dataType> *tempAVLNode = currentAVLNode->leftLink;
				currentAVLNode->leftLink = tempAVLNode->rightLink;
				tempAVLNode->rightLink = currentAVLNode;
				currentAVLNode = tempAVLNode;
				std::cout << "--------------------------------------------------" << std::endl;
				std::cout << "RIGHT ROTATION!" << std::endl;
				this->printTree();
				std::cout << "--------------------------------------------------" << std::endl;
			};
		};
	}
	else if (newInfo > currentAVLNode->info)
	{
		this->myInsertRecursive(newInfo, currentAVLNode->rightLink);
		if (currentAVLNode->balanceFactor == 0)
		{
			currentAVLNode->balanceFactor = 1;
		}
		else if (currentAVLNode->info == -1)
		{
			currentAVLNode->balanceFactor = 0;
		}
		else if (currentAVLNode->balanceFactor == 1)
		{
			if (currentAVLNode->rightLink->balanceFactor == 1)
			{
				//RIGHT ROTATION!
				std::cout << "(RR) RIGHT-RIGHT IMBALANCE! PERFORM A LEFT ROTATION!" << std::endl;
				currentAVLNode->balanceFactor = 0;
				AVLNode<dataType> *tempAVLNode = currentAVLNode->rightLink;
				tempAVLNode->balanceFactor = 0;
				currentAVLNode->rightLink = tempAVLNode->leftLink;
				tempAVLNode->leftLink = currentAVLNode;
				currentAVLNode = tempAVLNode;
				std::cout << "--------------------------------------------------" << std::endl;
				std::cout << "RIGHT ROTATION!" << std::endl;
				this->printTree();
				std::cout << "--------------------------------------------------" << std::endl;
			}
			else if (currentAVLNode->rightLink->balanceFactor == -1)
			{
				std::cout << "(RL) RIGHT-LEFT IMBALANCE! PERFORM A RIGHT-LEFT ROTATION!" << std::endl;
				//RIGHT ROTATION ON RIGHT CHILD!
				currentAVLNode->balanceFactor = 0;
				currentAVLNode->rightLink->balanceFactor = 0;
				AVLNode<dataType> *tempRightChildAVLNode = currentAVLNode->rightLink;
				currentAVLNode->rightLink = tempRightChildAVLNode->leftLink;
				tempRightChildAVLNode->leftLink->rightLink = tempRightChildAVLNode;
				tempRightChildAVLNode->leftLink = nullptr;
				std::cout << "--------------------------------------------------" << std::endl;
				std::cout << "RIGHT ROTATION!" << std::endl;
				this->printTree();
				std::cout << "--------------------------------------------------" << std::endl;
				//LEFT ROTATION ON CURRENT AVL NODE!
				AVLNode<dataType> *tempAVLNode = currentAVLNode->rightLink;
				currentAVLNode->rightLink = tempAVLNode->leftLink;
				tempAVLNode->leftLink = currentAVLNode;
				currentAVLNode = tempAVLNode;
				std::cout << "--------------------------------------------------" << std::endl;
				std::cout << "LEFT ROTATION!" << std::endl;
				this->printTree();
				std::cout << "--------------------------------------------------" << std::endl;
			};
		};
	};
};
template <class dataType>
int AVLTree<dataType>::fixBalanceFactors(AVLNode<dataType>* &currentAVLNode)
{
	if (currentAVLNode == nullptr)
	{
		return 0;
	};
	int rightChildHeight = this->fixBalanceFactors(currentAVLNode->rightLink);
	int leftChildHeight = this->fixBalanceFactors(currentAVLNode->leftLink);
	currentAVLNode->balanceFactor = rightChildHeight - leftChildHeight;
	return 1 + std::max(rightChildHeight,leftChildHeight);
};















template <class dataType>
void AVLTree<dataType>::printTree() const {
    printTree(rootAVLNode, 0);
}

template <class dataType>
void AVLTree<dataType>::printTree(AVLNode<dataType>* node, int indent) const {
    if (node != nullptr) {
        if (node->rightLink) {
            printTree(node->rightLink, indent + 4);
        }

        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }

        std::cout << node->info << " (BF=" << node->balanceFactor << ")" << std::endl;

        if (node->leftLink) {
            printTree(node->leftLink, indent + 4);
        }
    }
}






template <class dataType>
AVLTree<dataType>::AVLTree()
{
	this->rootAVLNode = nullptr;
};
template <class dataType>
void AVLTree<dataType>::insert(const dataType &newInfo)
{
	bool isTaller = false;
	AVLNode<dataType> *newNode = new AVLNode<dataType>;
	newNode->info = newInfo;
	newNode->balanceFactor = 0;
	newNode->leftLink = nullptr;
	newNode->rightLink = nullptr;
	std::cout << "INSERTING: " << newInfo << " INTO AVL BST!" << std::endl;
	this->insertIntoAVL(this->rootAVLNode, newNode, isTaller);
	std::cout << "AFTER BALANCING: " << std::endl;
	this->printTree();
};
template <class dataType>
void AVLTree<dataType>::insertIntoAVL(AVLNode<dataType>* &currentAVLNode, AVLNode<dataType> *newNode, bool &isTaller)
{
	if (currentAVLNode == nullptr)
	{
		currentAVLNode = newNode;
		isTaller = true;
		std::cout << "BEFORE BALANCING: " << std::endl;
		this->printTree();
	}
	else if (currentAVLNode->info == newNode->info)
	{
		std::cout << "NO DUPLICATES ARE ALLOWED!" << std::endl;
	}
	else if (newNode->info < currentAVLNode->info)
	{
		//INSERT ITEM INTO LEFT SUBTREE OF currentAVLNode!
		this->insertIntoAVL(currentAVLNode->leftLink, newNode, isTaller);
		if (isTaller)
		{
			//right subtree height - left subtree height (LEFT MINUS RIGHT SUBTREE HEIGHTS!)
			switch(currentAVLNode->balanceFactor)
			{
				case 0:
					currentAVLNode->balanceFactor = -1;
					isTaller = true;
					break;
				case 1:
					currentAVLNode->balanceFactor = 0;
					isTaller = false;
					break;
				case -1:
					this->balanceFromLeft(currentAVLNode);
					isTaller = false;
					break;
			};
		};
	}
	else if (newNode->info > currentAVLNode->info)
	{
		//INSERT ITEM INTO RIGHT SUBTREE OF currentAVLNode!
		this->insertIntoAVL(currentAVLNode->rightLink, newNode, isTaller);
		if (isTaller)
		{
			//right subtree height - left subtree height (LEFT MINUS RIGHT SUBTREE HEIGHTS!)
			switch(currentAVLNode->balanceFactor)
			{
				case 0:
					currentAVLNode->balanceFactor = 1;
					isTaller = true;
					break;
				case -1:
					currentAVLNode->balanceFactor = 0;
					isTaller = false;
					break;
				case 1:
					this->balanceFromRight(currentAVLNode);
					isTaller = false;
					break;
			};
		};
	};	
};
template <class dataType>
void AVLTree<dataType>::balanceFromLeft(AVLNode<dataType>* &currentAVLNode)
{
	AVLNode<dataType> *leftChildAVLNode = currentAVLNode->leftLink;
	AVLNode<dataType> *rightChildOfLeftChildAVLNode = leftChildAVLNode->rightLink;
	switch(leftChildAVLNode->balanceFactor)
	{
		case 0:
			std::cout << "ERROR: CANNOT BALANCE FROM THE LEFT!" << std::endl;
			break;
		case -1:
			currentAVLNode->balanceFactor = 0;
			leftChildAVLNode->balanceFactor = 0;
			this->rotateToRight(currentAVLNode);
			break;
		case 1:
			switch(rightChildOfLeftChildAVLNode->balanceFactor)
			{
				case 0:
					currentAVLNode->balanceFactor = 0;
					leftChildAVLNode->balanceFactor = 0;
					break;
				case -1:
					currentAVLNode->balanceFactor = 1;
					leftChildAVLNode->balanceFactor = 0;
					break;
				case 1:
					currentAVLNode->balanceFactor = 0;
					leftChildAVLNode->balanceFactor = -1;
					break;
			};
			rightChildOfLeftChildAVLNode->balanceFactor = 0;
			this->rotateToLeft(leftChildAVLNode);
			currentAVLNode->leftLink = leftChildAVLNode;//THEN WHY IS THIS NESSARY? AFTER THE ROTATE TO LEFT FUNCTION???
	        this->rotateToRight(currentAVLNode);
			break;
	};
};
template <class dataType>
void AVLTree<dataType>::balanceFromRight(AVLNode<dataType>* &currentAVLNode)
{
	AVLNode<dataType> *rightChildAVLNode = currentAVLNode->rightLink;
	AVLNode<dataType> *leftChildOfRightChildAVLNode = rightChildAVLNode->leftLink;
	switch(rightChildAVLNode->balanceFactor)
	{
		case 0:
			std::cout << "ERROR: CANNOT BALANCE FROM THE RIGHT!" << std::endl;
			break;
		case 1:
			currentAVLNode->balanceFactor = 0;
			rightChildAVLNode->balanceFactor = 0;
			this->rotateToLeft(currentAVLNode);
			break;
		case -1:
			switch(leftChildOfRightChildAVLNode->balanceFactor)
			{
				case 0:
					currentAVLNode->balanceFactor = 0;
	            	rightChildAVLNode->balanceFactor = 0;
	            	break;
	            case -1:
	            	currentAVLNode->balanceFactor = 0;
	            	rightChildAVLNode->balanceFactor = 1;
	            	break;
	            case 1:
	            	currentAVLNode->balanceFactor = -1;
		            rightChildAVLNode->balanceFactor = 0;
		            break;
			};
			leftChildOfRightChildAVLNode->balanceFactor = 0;
			this->rotateToRight(rightChildAVLNode);
			currentAVLNode->rightLink = rightChildAVLNode;
			this->rotateToLeft(currentAVLNode);
			break;
	};
};




template <class dataType>
void AVLTree<dataType>::rotateToLeft(AVLNode<dataType>* &currentAVLNode)
{
	std::cout << "currentAVLNode: " << currentAVLNode->info << std::endl;
	std::cout << "-------------------------BEFORE ROTATE TO LEFT-------------------------" << std::endl;
	this->printTree();
	std::cout << "-------------------------BEFORE ROTATE TO LEFT-------------------------" << std::endl;
	AVLNode<dataType> *rightChildAVLNode;
	if (currentAVLNode == nullptr)
	{
		std::cout << "ERROR IN THE TREE!" << std::endl;
	}
	else if (currentAVLNode->rightLink == nullptr)
	{
		std::cout << "ERROR IN THE TREE! NO RIGHT SUBTREE TO ROTATE!" << std::endl;
	}
	else
	{
		rightChildAVLNode = currentAVLNode->rightLink;
		std::cout << "-------------------------AFTER rightChildAVLNode = currentAVLNode->rightLink;-------------------------" << std::endl;
		this->printTree();
		std::cout << "-------------------------AFTER rightChildAVLNode = currentAVLNode->rightLink;-------------------------" << std::endl;
		std::cout << "RIGHT CHILD OF ROOT: " << this->rootAVLNode->rightLink->info << std::endl;
		currentAVLNode->rightLink = rightChildAVLNode->leftLink;
		std::cout << "-------------------------AFTER currentAVLNode->rightLink = rightChildAVLNode->leftLink;-------------------------" << std::endl;
		this->printTree();
		std::cout << "-------------------------AFTER currentAVLNode->rightLink = rightChildAVLNode->leftLink;-------------------------" << std::endl;
		std::cout << "RIGHT CHILD OF ROOT: " << this->rootAVLNode->rightLink->info << std::endl;
		rightChildAVLNode->leftLink = currentAVLNode;
		std::cout << "11111. currentAVLNode: " << currentAVLNode->info << std::endl;
		std::cout << "22222. RIGHT CHILD OF ROOT: " << this->rootAVLNode->rightLink->info << std::endl;
		std::cout << "33333. rightChildAVLNode->leftLink: " << rightChildAVLNode->leftLink->info << std::endl;
		std::cout << "-------------------------AFTER rightChildAVLNode->leftLink = currentAVLNode;-------------------------" << std::endl;
		this->printTree();
		std::cout << "-------------------------AFTER rightChildAVLNode->leftLink = currentAVLNode;-------------------------" << std::endl;
		std::cout << "RIGHT CHILD OF ROOT 1.: " << this->rootAVLNode->rightLink->info << std::endl;
		currentAVLNode = rightChildAVLNode; //I DO NOT UNDERSTAND WHAT IS HAPPENING HERE, WHY IS THIS ESSENTIALLY OVERRITING A NODE'S POINTER SIMILAR TO currentAVLNode->child = pointer
		std::cout << "11111. currentAVLNode: " << currentAVLNode->info << std::endl;
		std::cout << "22222. RIGHT CHILD OF ROOT: " << this->rootAVLNode->rightLink->info << std::endl;
		std::cout << "33333. rightChildAVLNode->leftLink: " << rightChildAVLNode->leftLink->info << std::endl;
		std::cout << "RIGHT CHILD OF ROOT 2.: " << this->rootAVLNode->rightLink->info << std::endl;
		std::cout << "-------------------------AFTER currentAVLNode = rightChildAVLNode;-------------------------" << std::endl;
		this->printTree();
		std::cout << "-------------------------AFTER currentAVLNode = rightChildAVLNode;-------------------------" << std::endl;
		std::cout << "RIGHT CHILD OF ROOT: " << this->rootAVLNode->rightLink->info << std::endl;
	};
	std::cout << "-------------------------AFTER ROTATE TO LEFT-------------------------" << std::endl;
	this->printTree();
	std::cout << "-------------------------AFTER ROTATE TO LEFT-------------------------" << std::endl;
	std::cout << "RIGHT CHILD OF ROOT: " << this->rootAVLNode->rightLink->info << std::endl;
};
template <class dataType>
void AVLTree<dataType>::rotateToRight(AVLNode<dataType>* &currentAVLNode)
{
	std::cout << "-------------------------BEFORE ROTATE TO RIGHT-------------------------" << std::endl;
	this->printTree();
	std::cout << "-------------------------BEFORE ROTATE TO RIGHT-------------------------" << std::endl;
	AVLNode<dataType> *leftChildAVLNode;
	if (currentAVLNode == nullptr)
	{
		std::cout << "ERROR IN THE TREE!" << std::endl;
	}
	else if (currentAVLNode->leftLink == nullptr)
	{
		std::cout << "ERROR IN THE TREE! NO LEFT SUBTREE TO ROTATE!" << std::endl;
	}
	else
	{
		leftChildAVLNode = currentAVLNode->leftLink;
		currentAVLNode->leftLink = leftChildAVLNode->rightLink;
		leftChildAVLNode->rightLink = currentAVLNode;
		currentAVLNode = leftChildAVLNode;
	};
	std::cout << "-------------------------AFTER ROTATE TO RIGHT-------------------------" << std::endl;
	this->printTree();
	std::cout << "-------------------------AFTER ROTATE TO RIGHT-------------------------" << std::endl;
};
#endif