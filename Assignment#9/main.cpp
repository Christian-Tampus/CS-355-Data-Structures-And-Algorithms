// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Assignment #9
// Date due: 04/30/30
// Description: A program to handle graphs of (undirected or directed types) and to be able to find the shortest path
// ---------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include "weightedGraph.h"
using namespace std;
int main()
{
	std::cout << "[SYSTEM MESSAGE] Program Start!" << std::endl;
	weightedGraphType wG(20);
	wG.createWeightedGraph();
    wG.printWgraph();
    wG.shortestPath(0);
    wG.printShortestDistance(0);
    std::cout << "++++++++++++++" << std::endl << std::endl;
    wG.allShortestPathWeights();
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "[SYSTEM MESSAGE]  wG.DijkstrasAlgorithm(0):" << std::endl;
    wG.DijkstrasAlgorithm(0);
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "[SYSTEM MESSAGE] wG.allPairsShortestPathWeights():" << std::endl;
    wG.allPairsShortestPathWeights();
    std::cout << "[SYSTEM MESSAGE] Program Terminated..." << std::endl;
	return 0;
};