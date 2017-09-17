#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <tuple>


using namespace std;

class Graph
{
    const int INF = 1000000000;
    
    vector <vector <int> > AdjMatrix;
    vector <vector <int> >  AdjListUnweighted;
    vector <vector <pair <int,int> > >  AdjListWeighted;
    vector <pair <int,int> > ListOfEdgesUnweighted;
    vector <tuple<int,int,int> > ListOfEdgesWeighted;
    bool R,W;
    int N,M;
    char state;
public:
    Graph();
    Graph(int n);
    ~Graph();
    void readGraph(std::string fileName);
    void addEdge(int from,int to, int weight);
    void removeEdge(int from,int to);
    int changeEdge(int from,int to,int newWeight);
    void transformToAdjList();
    void transformToAdjMatrix();
    void transformToListOfEdges();
    void writeGraph(std::string fileName);
    
    Graph* getSpaingTreePrima();
    Graph* getSpaingTreeKruscal();
    Graph* getSpaingTreeBoruvka();
};
