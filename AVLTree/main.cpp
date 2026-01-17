#include <iostream>
#include "AVLTree.h"
using namespace std;
int main()
{
	AVLTree<int> AVLBST;
	/*
	AVLBST.insert(50);
	std::cout << "--------------------------------------------------" << std::endl;
	AVLBST.insert(40);
	std::cout << "--------------------------------------------------" << std::endl;
	AVLBST.insert(70);
	std::cout << "--------------------------------------------------" << std::endl;
	AVLBST.insert(80);
	std::cout << "--------------------------------------------------" << std::endl;
	AVLBST.insert(75);
	std::cout << "--------------------------------------------------" << std::endl;
	*/
	AVLBST.myInsert(50);
	AVLBST.myInsert(40);
	AVLBST.myInsert(30);
	AVLBST.myInsert(60);
	AVLBST.myInsert(70);
	AVLBST.myInsert(20);
	AVLBST.myInsert(25);
	AVLBST.myInsert(80);
	AVLBST.myInsert(75);
	std::cout << "[SYSTEM MESSAGE] Program Terminated..." << std::endl;
	return 0;
};