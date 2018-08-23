#include<iostream>
#include<vector>
#include<queue>
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
  ~graph() {
    for(int i=0; i<nVertices; i++)
      delete [] adjacencyMatrix[i];
    delete [] adjacencyMatrix;
  }

  void printAdjacency() const {
    for(int i=0; i<nVertices; i++)
    {
      for(int j=0; j<nVertices; j++)
        cout << adjacencyMatrix[i][j] << ' ';
      cout << endl;
    }
  }

  int& operator[](pair<int,int> p) {
    return adjacencyMatrix[p.first][p.second];
  }

  bool hasPath(int source, int dest) const {
    vector<bool> nodesVisited(nVertices);
    int visitCount = 0;
    /* Queue of Nodes */
    queue<int> q;
    //cout << "Nodes Visited in Depth First traversal are : ";
    q.push(source);
    while(!q.empty())
    {
      source = q.front();
      if(adjacencyMatrix[source][dest]) return true;
      q.pop();
      nodesVisited[source] = true;
      visitCount++;
      for (int j=0; j<nVertices; j++)
        if(adjacencyMatrix[source][j] && !nodesVisited[j])
          q.push(j);
    }
    return false;
  }

  bool DFSPath(int source, int dest, vector<int>& path) const
  {
    vector<bool> nodesVisited(nVertices);
    int visitCount = 0;
    /* Queue of Nodes */
    queue<int> q;
    //cout << "Nodes Visited in Depth First traversal are : ";
    q.push(source);
    path.push_back(source);
    while(!q.empty())
    {
      source = q.front();
      path.push_back(source);
      if(adjacencyMatrix[source][dest])
      {
        path.push_back(dest);
        return true;
      }
      q.pop();
      nodesVisited[source] = true;
      visitCount++;
      for (int j=0; j<nVertices; j++)
        if(adjacencyMatrix[source][j] && !nodesVisited[j])
          q.push(j);
    }
    return false;
  }

  bool getPathDFS(int source, int dest, vector<bool>& nodesVisited, 
      vector<int>& path) const {
    if(adjacencyMatrix[source][dest])
    {
      path.push_back(dest);
      return true;
    }
    if(nodesVisited[source]) return false;
    nodesVisited[source] = true;
    for (int j=0; j<nVertices; j++)
      if(adjacencyMatrix[source][j] && !nodesVisited[j])
        if(getPathDFS(j, dest, nodesVisited, path))
        {
          path.push_back(j);
          return true;
        }
    return false;
  }
  bool hasPathDFS(int source, int dest, vector<bool>& nodesVisited) const {
    if(adjacencyMatrix[source][dest]) return true;
    if(nodesVisited[source]) return false;
    nodesVisited[source] = true;
    for (int j=0; j<nVertices; j++)
      if(adjacencyMatrix[source][j] && !nodesVisited[j])
        if(hasPathDFS(j, dest, nodesVisited)) return true;
    return false;
  }

  void printDepthFirst(int node, vector<bool>& nodesVisited) const
  {
    if(nodesVisited[node]) return;
    nodesVisited[node] = true;
    cout << node << ' ';
    for (int j=0; j<nVertices; j++)
      if(adjacencyMatrix[node][j] && !nodesVisited[j])
        printDepthFirst(j, nodesVisited);
  }

  void printDepthFirst(int node=0) const
  {
    vector<bool> nodesVisited(nVertices);
    int visitCount = 0;
    /* Queue of Nodes */
    queue<int> q;
    //cout << "Nodes Visited in Depth First traversal are : ";
    q.push(node);
    while(visitCount!=nVertices)
    {
      while(!q.empty())
      {
        node = q.front();
        q.pop();
        nodesVisited[node] = true;
        visitCount++;
        for (int j=0; j<nVertices; j++)
          if(adjacencyMatrix[node][j] && !nodesVisited[j])
            q.push(j);
        cout << node << ' ';
      }
      if(visitCount!=nVertices)
      {
        for (node=0; node<nVertices && nodesVisited[node]; node++);
        q.push(node);
      }
    }
    cout << endl;
  }
  void printBreadthFirst(int node=0) const
  {
    vector<bool> nodesVisited(nVertices);
    int visitCount = 0;
    /* Queue of Nodes */
    queue<int> q;
    //cout << "Nodes Visited in Breadth First traversal are : ";
    nodesVisited[node] = true;
    visitCount++;
    cout << node << ' ';
    q.push(node);
    while(visitCount!=nVertices)
    {
      while(!q.empty())
      {
        node = q.front();
        q.pop();
        for (int j=0; j<nVertices; j++)
          if(adjacencyMatrix[node][j] && !nodesVisited[j])
          {
            nodesVisited[j] = true;
            visitCount++;
            cout << j << ' ';
            q.push(j);
          }
      }
      if(visitCount!=nVertices)
      {
        for (node=0; node<nVertices && nodesVisited[node]; node++);
        nodesVisited[node] = true;
        visitCount++;
        cout << node << ' ';
        q.push(node);
      }
    }
    cout << endl;
  }
};

int solve(int n,int m,vector<int>u,vector<int>v)
{
  graph g(n);
  for(int i=0; i<m; i++)
  {
    pair<int,int> edge1(u[i]-1, v[i]-1);
    g[edge1] = 1;
    pair<int,int> edge2(v[i]-1, u[i]-1);
    g[edge2] = 1;
  }
  int count=0;
  vector<bool> nodesVisited(n);
  for(int i=0; i<m; i++)
  {
    if(nodesVisited[i]) continue;
    count++;
    g.printDepthFirst(i, nodesVisited);
  }
  return count;
}

int main()
{
  pair<int,int> edge;
  int nVertices, nEdges;
  cin >> nVertices >> nEdges;
  graph g(nVertices);
  vector<int> u, v;
  for(int i=0; i<nEdges; i++)
  {
    cin >> edge.first >> edge.second;
    u.push_back(edge.first);
    v.push_back(edge.second);
    /*
    g[edge] = 1;
    swap<int>(edge.first, edge.second);
    g[edge] = 1;
    */
  }
  cout << solve(nVertices, nEdges, u, v) << endl;
  return 0;
  cin >> edge.first >> edge.second;
  vector<bool> nodesVisited(nVertices);
  /*
  if(g.hasPathDFS(edge.first, edge.second, nodesVisited))
    cout << "true" << endl;
  else
    cout << "false" << endl;
    */
  vector<int> path;
  if(g.getPathDFS(edge.first, edge.second, nodesVisited, path))
  {
    copy(path.begin(), path.end(), ostream_iterator<int>(cout, " "));
    cout << edge.first << endl;
  }
  //g.printAdjacency();
  //g.printDepthFirst(nVertices-1);
  //g.printBreadthFirst(0);
  return 0;
}
