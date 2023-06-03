#include "Dijakrsta.h"

list<vertexT> Dijakrsta::GetShortestPath(vertexT vertex, const vector<vertexT>& previous)
{
    list <vertexT> path;
    for (; vertex != -1; vertex = previous[vertex])
        path.push_front(vertex);
    return path;
}

void Dijakrsta::ComputePaths(vertexT source, const chanceOfLifeT& adjacencyList, vector<vertexT>& previous, vector <weightT>& minDistance)
{
    minDistance.clear();
    minDistance.resize(adjacencyList.size(), maxWeight);
    minDistance[source] = 0;
    previous.clear();
    previous.resize(adjacencyList.size(), -1);

    set <pair <weightT, vertexT>> vertexQueue;
    vertexQueue.insert(make_pair(minDistance[source], source));

    while (!vertexQueue.empty())
    {
        weightT dist = vertexQueue.begin()->first;
        vertexT u = vertexQueue.begin()->second;
        vertexQueue.erase(vertexQueue.begin());

        const vector <Neighbor>& Neighbors = adjacencyList[u];
        for (const Neighbor& Neighbor_iter : Neighbors)
        {
            vertexT v = Neighbor_iter.target;
            weightT weight = Neighbor_iter.weight;

            if (weight == maxWeight)
                continue;

            weightT distance_through_u = dist + weight;
            if (distance_through_u < minDistance[v])
            {
                vertexQueue.erase(std::make_pair(minDistance[v], v));

                minDistance[v] = distance_through_u;
                previous[v] = u;
                vertexQueue.insert(make_pair(minDistance[v], v));
            }
        }
    }
}

Dijakrsta::Dijakrsta(int rowA, int columnA, int rowB, int columnB)
{
    this->walls = true;
    this->rowA = rowA;
    this->columnA = columnA;
    this->rowB = rowB;
    this->columnB = columnB;

    for (int j = 0; j < 15; ++j) {
        map[j][10] = 1;
    }

    for (int j = 0; j < 10; ++j) {
        map[j][20] = 1;
    }

    chanceOfLifeT adjacencyList(rows * columns + 1);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {

            if (map[i][j] == 1) {
                continue;
            }

            if (i > 0 && map[i - 1][j] != 1) {
                adjacencyList[i * columns + j].push_back(Neighbor((i - 1) * columns + j, 1));
            }

            if (j > 0 && map[i][j - 1] != 1) {
                adjacencyList[i * columns + j].push_back(Neighbor(i * columns + j - 1, 1));
            }

            if (j < columns - 1 && map[i][j + 1] != 1) {
                adjacencyList[i * columns + j].push_back(Neighbor(i * columns + j + 1, 1));  
            }

            if (i < rows - 1 && map[i + 1][j] != 1) {
                adjacencyList[i * columns + j].push_back(Neighbor((i + 1) * columns + j, 1));  
            }
        }
    }

    vector<weightT> minDistance;
    vector<vertexT> previous;
    ComputePaths((rowA - 1) * columns + columnA - 1, adjacencyList, previous, minDistance);

    list <vertexT> path = GetShortestPath((rowB - 1) * columns + columnB - 1, previous);
    list<vertexT> adjustedPath = path;

    drawMap(rowA, columnA, rowB, columnB, adjustedPath, map);
    Sleep(100);

    for (const vertexT& vertex : adjustedPath)
    {
        int row = vertex / columns;
        int column = vertex % columns;
        map[row][column] = 2;
        drawMap(rowA, columnA, rowB, columnB, adjustedPath, map);
        Sleep(100);
    }
}

void Dijakrsta::drawMap(int rowA, int columnA, int rowB, int columnB, const list<vertexT>& adjustedPath, int map[20][40])
{
    system("cls");

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            if (i == rowA - 1 && j == columnA - 1)
                cout << "S ";                           
            else if (i == rowB - 1 && j == columnB - 1)
                cout << "D ";                           
            else if (map[i][j] == 2)
                cout << "x ";                           
            else if (map[i][j] == 1)
                cout << "| ";                           
            else
                cout << ". ";                           
        }
        cout << endl;
    }
}
