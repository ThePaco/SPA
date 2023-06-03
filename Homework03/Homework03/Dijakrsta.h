#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
#include <list>
#include <set>
#include <random>
#include <limits> 
#include <utility> 

using namespace std;

typedef int vertexT;
typedef double weightT;

const weightT maxWeight = numeric_limits<double>::infinity();

struct Neighbor {
    vertexT target;
    weightT weight;
    Neighbor(vertexT argTarget, weightT argWeight) : target(argTarget), weight(argWeight) {}
};

typedef vector <vector<Neighbor>> chanceOfLifeT;

class Dijakrsta
{
private:
    bool walls = true;
    int rowA;
    int columnA;
    int rowB;
    int columnB;
    unsigned static const int rows = 20;
    unsigned static const int columns = 40;
    int map[rows][columns];

    list <vertexT> path;

    list <vertexT> GetShortestPath(vertexT vertex, const vector<vertexT>& previous);
    void ComputePaths(vertexT source, const chanceOfLifeT& adjacencyList, vector<vertexT>& previous, vector <weightT>& minDistance);

public:
    Dijakrsta(int rowA, int columnA, int rowB, int columnB);
    void drawMap(int rowA, int columnA, int rowB, int columnB, const list <vertexT>& adjustedPath, int map[20][40]);
};




