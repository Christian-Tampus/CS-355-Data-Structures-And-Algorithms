// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Assignment #9
// Date due: 04/30/30
// Description: A program to handle graphs of (undirected or directed types) and to be able to find the shortest path
// ---------------------------------------------------------------------------
#ifndef H_weightedGraph
#define H_weightedGraph

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cfloat>
#include "graphType.h"

using namespace std;

class weightedGraphType: public graphType
{
public:
    void createWeightedGraph();
      //Function to create the graph and the weight matrix.
      //Postcondition: The graph using adjacency lists and
      //               its weight matrix is created.

    void shortestPath(int vertex);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*
	// ---------------------------------------------------------------------------
	// CODE IMPLEMENTATION START
	// ---------------------------------------------------------------------------
	*/
    void DijkstrasAlgorithm(int vertex);
    void DijkstrasAlgorithmRecursive(int vertex, bool *visitedVertexArray, double *vertexDistanceArray);
    void allPairsShortestPathWeights();
    /*
	// ---------------------------------------------------------------------------
	// CODE IMPLEMENTATION END
	// ---------------------------------------------------------------------------
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	*/
    
      //Function to determine the weight of a shortest path
      //from vertex, that is, source, to every other vertex
      //in the graph.
      //Postcondition: The weight of the shortest path from
      //               vertex to every other vertex in the
      //               graph is determined.

    void printShortestDistance(int vertex);
      //Function to print the shortest weight from vertex
      //to the other vertex in the graph.
      //Postcondition: The weight of the shortest path from
      //               vertex to every other vertex in the
      //               graph is printed.

    void allShortestPathWeights();
      //Function to call printShortestDistance for all vertexes

    void printWgraph();
      //Function to call to print out the weighted graph.

    weightedGraphType(int size = 0);
      //Constructor
      //Postcondition: gSize = 0; maxSize = size;
      //               graph is an array of pointers to linked
      //               lists.
      //               weights is a two-dimensional array to
      //               store the weights of the edges.
      //               smallestWeight is an array to store the
      //               smallest weight from source to vertices.

    ~weightedGraphType();
      //Destructor
      //The storage occupied by the vertices and the arrays
      //weights and smallestWeight is deallocated.

protected:
    double **weights;   //pointer to create weight matrix
    double *smallestWeight;	//pointer to create the array to
                            //store the smallest weight from
                            //source to vertices
};

void weightedGraphType::createWeightedGraph()
{
	/*
	// ---------------------------------------------------------------------------
	// CODE IMPLEMENTATION START
	// ---------------------------------------------------------------------------
	*/
	ifstream inputFile;
	std::string inputFileName;
	std::cout << "Enter Weighted Graph File Name (Example: graphtest.txt): ";
	std::getline(std::cin,inputFileName);
	inputFile.open(inputFileName);
	if (inputFile)
	{
		inputFile >> graphType::gSize;
		while (!inputFile.eof())
		{
			int vertex1;
			int vertex2;
			int edgeWeight;
			inputFile >> vertex1;
			inputFile >> vertex2;
			inputFile >> edgeWeight;
			graphType::graph[vertex1].insertLast(vertex2);
			this->weights[vertex1][vertex2] = edgeWeight;
		};
	}
	else
	{
		std::cout << "[SYSTEM ERROR] Cannot Open The Input File!" << std::endl;
	};
	inputFile.close();
	/*
	// ---------------------------------------------------------------------------
	// CODE IMPLEMENTATION END
	// ---------------------------------------------------------------------------
	*/
};

void weightedGraphType::allShortestPathWeights()
{
	/*
	// ---------------------------------------------------------------------------
	// CODE IMPLEMENTATION START
	// ---------------------------------------------------------------------------
	*/
	for (int index = 0; index < graphType::gSize; index++)
    {
		this->shortestPath(index);
		this->printShortestDistance(index);
	};
	/*
	// ---------------------------------------------------------------------------
	// CODE IMPLEMENTATION END
	// ---------------------------------------------------------------------------
	*/
};

void weightedGraphType::printWgraph()
{
    printGraph();
    cout<<"::Weight Matrix::"<<endl;
    for(int i=0; i<gSize; i++)
    {
        for(int j=0; j<gSize; j++)
        {
            if(weights[i][j] < DBL_MAX)
            {
                cout<<weights[i][j]<< " ";
            }
            else
            {
                cout<<"UN "; //UN stands for undefined (treated in code as infinity)
            }

        }
        cout<<endl;
    }
    cout<<":::::::::::::"<<endl;
}

void weightedGraphType::shortestPath(int vertex)
{
    for (int j = 0; j < gSize; j++)
        smallestWeight[j] = weights[vertex][j];

    bool *weightFound;
    weightFound = new bool[gSize];

    for (int j = 0; j < gSize; j++)
        weightFound[j] = false;

    weightFound[vertex] = true;
    smallestWeight[vertex] = 0;

    for (int i = 0; i < gSize - 1; i++)
    {
        double minWeight = DBL_MAX;
        int v;

        for (int j = 0; j < gSize; j++)
            if (!weightFound[j])
                if (smallestWeight[j] < minWeight)
                {
                    v = j;
                    minWeight = smallestWeight[v];
                }

        weightFound[v] = true;

        for (int j = 0; j < gSize; j++)
            if (!weightFound[j])
                if (minWeight + weights[v][j] < smallestWeight[j])
                    smallestWeight[j] = minWeight + weights[v][j];
    } //end for
} //end shortestPath


























/*
// ---------------------------------------------------------------------------
// CODE IMPLEMENTATION START
// ---------------------------------------------------------------------------
*/
void weightedGraphType::DijkstrasAlgorithm(int vertex)
{
	bool *visitedVertexArray = new bool[graphType::gSize];
	double *vertexDistanceArray = new double[graphType::gSize];
	for (int index = 0; index < graphType::gSize; index++)
	{
		visitedVertexArray[index] = false;
		vertexDistanceArray[index] = DBL_MAX;
	};
	visitedVertexArray[vertex] = true;
	vertexDistanceArray[vertex] = 0;
	this->DijkstrasAlgorithmRecursive(vertex, visitedVertexArray, vertexDistanceArray);
	std::cout << "[SYSTEM MESSAGE] Dijkstras Algorithm:" << std::endl;
	std::cout << "[SYSTEM MESSAGE] Source/Start Vertex: (" << vertex << ")" << std::endl;
	std::cout << "[SYSTEM MESSAGE] Shortest Distance From Source/Start Vertex To All Other Vertex:" << std::endl;
	for (int index = 0; index < gSize; index++)
	{
		std::cout << "Shortest Distance From Vertex (" << vertex << ") To Vertex: (" << index << ") Is: " << (vertexDistanceArray[index] == DBL_MAX ? "INFINITY" : std::to_string(vertexDistanceArray[index])) << std::endl;
	};
};
void weightedGraphType::DijkstrasAlgorithmRecursive(int vertex, bool *visitedVertexArray, double *vertexDistanceArray)
{
	visitedVertexArray[vertex] = true;
	for (int index = 0; index < graphType::gSize; index++)
	{
		if (visitedVertexArray[index] == false && this->weights[vertex][index] > 0 && this->weights[vertex][index] < DBL_MAX)
		{
			double currentPathWeight = vertexDistanceArray[vertex] + this->weights[vertex][index];
			if (currentPathWeight < vertexDistanceArray[index])
			{
				vertexDistanceArray[index] = currentPathWeight;
			};
		};
	};
	double smallestUnVisitedPathWeight = DBL_MAX;
	int smallestUnVisitedVertex = -1;
	for (int index = 0; index < graphType::gSize; index++)
	{
		if (visitedVertexArray[index] == false && vertexDistanceArray[index] < smallestUnVisitedPathWeight)
		{
			smallestUnVisitedPathWeight = vertexDistanceArray[index];
			smallestUnVisitedVertex = index;
		};
	};
	if (smallestUnVisitedVertex != -1)
	{
		this->DijkstrasAlgorithmRecursive(smallestUnVisitedVertex, visitedVertexArray, vertexDistanceArray);
	};
};
void weightedGraphType::allPairsShortestPathWeights()
{
	for (int index = 0; index < graphType::gSize; index++)
	{
		this->DijkstrasAlgorithm(index);
	};
};
/*
// ---------------------------------------------------------------------------
// CODE IMPLEMENTATION END
// ---------------------------------------------------------------------------
*/


























void weightedGraphType::printShortestDistance(int vertex)
{
    cout << "Source Vertex: " << vertex << endl;
    cout << "Shortest Distance from Source to each Vertex."
         << endl;
    cout << "Vertex Shortest_Distance" << endl;

    for (int j = 0; j < gSize; j++){
        if(smallestWeight[j]<DBL_MAX)
        {
            cout << setw(4) << j << setw(12) << smallestWeight[j]<< endl;
        }
        else
        {
            cout << setw(4) << j << setw(12) << "UN"<< endl;
        }

    }
    cout << endl;
} //end printShortestDistance

    //Constructor
weightedGraphType::weightedGraphType(int size)
                  :graphType(size)
{
    weights = new double*[size];

    for (int i = 0; i < size; i++)
        weights[i] = new double[size];

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++)
        {
            weights[i][j] = DBL_MAX;
        }
    }

    smallestWeight = new double[size];
}

    //Destructor
weightedGraphType::~weightedGraphType()
{
    for (int i = 0; i < gSize; i++)
       delete [] weights[i];

    delete [] weights;
    delete smallestWeight;
}

#endif