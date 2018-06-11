#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class graph {
  /* We maintain the adjacency matrix of integers. We do not use nEdges as of
   * now. We have given [] operator to access and update the edges using pair
   * */
  int nVertices, nEdges;
  int **adjacencyMatrix;
  public:
  graph(int _nVertices)
    :nVertices(_nVertices), nEdges(0)
  {
    //adjacencyMatrix = (int **)new int[nVertices*nVertices];
    adjacencyMatrix = new int*[nVertices];
    for(int i=0; i<nVertices; i++)
    {
      adjacencyMatrix[i] = new int[nVertices];
      for(int j=0; j<nVertices; j++)
        adjacencyMatrix[i][j] = 0;
    }
  }
  ~graph()
  {
    for(int i=0; i<nVertices; i++)
      delete [] adjacencyMatrix[i];
    delete [] adjacencyMatrix;
  }
  void printAdjacency() const
  {
    for(int i=0; i<nVertices; i++)
    {
      for(int j=0; j<nVertices; j++)
        cout << adjacencyMatrix[i][j] << ' ';
      cout << endl;
    }
  }
  int& operator[](pair<int,int> p)
  {
    return adjacencyMatrix[p.first][p.second];
  }
  void printDepthFirst(int node=0) const
  {
    vector<bool> nodesVisited(nVertices);
    int visitCount = 0;
    /* Stack of Nodes */
    stack<int> s;
    cout << "Nodes Visited in Depth First traversal are : ";
    s.push(node);
    while(visitCount!=nVertices)
    {
      while(!s.empty())
      {
        node = s.top();
        s.pop();
        nodesVisited[node] = true;
        visitCount++;
        for (int j=0; j<nVertices; j++)
          if(adjacencyMatrix[node][j] && !nodesVisited[j])
            s.push(j);
        cout << node << ' ';
      }
      if(visitCount!=nVertices)
      {
        for (node=0; node<nVertices && nodesVisited[node]; node++);
        s.push(node);
      }
    }
    cout << endl;
  }
  void printBreadthFirst(int node=0) const
  {
    vector<bool> nodesVisited(nVertices);
    int visitCount = 0;
    /* Stack of Nodes */
    stack<int> s;
    cout << "Nodes Visited in Breadth First traversal are : ";
    nodesVisited[node] = true;
    visitCount++;
    cout << node << ' ';
    s.push(node);
    while(visitCount!=nVertices)
    {
      while(!s.empty())
      {
        node = s.top();
        s.pop();
        for (int j=0; j<nVertices; j++)
          if(adjacencyMatrix[node][j] && !nodesVisited[j])
          {
            nodesVisited[j] = true;
            visitCount++;
            cout << j << ' ';
            s.push(j);
          }
      }
      if(visitCount!=nVertices)
      {
        for (node=0; node<nVertices && nodesVisited[node]; node++);
        nodesVisited[node] = true;
        visitCount++;
        cout << node << ' ';
        s.push(node);
      }
    }
    cout << endl;
  }
};

int main()
{
  pair<int,int> edge;
  int nVertices, nEdges;
  cin >> nVertices >> nEdges;
  graph g(nVertices);
  for(int i=0; i<nEdges; i++)
  {
    cin >> edge.first >> edge.second;
    g[edge] = 1;
  }
  g.printAdjacency();
  g.printDepthFirst(nVertices-1);
  g.printBreadthFirst(0);
  return 0;
}
