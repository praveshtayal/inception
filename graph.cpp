#include<iostream>
#include<climits>
#include<vector>
#include<queue>
using namespace std;

class graph {
  /* We maintain the adjacency matrix of integers. We do not use nEdges as of
   * now. We have given [] operator to access and update the edges using pair
   * */
  int nVertices, nEdges;
  int **adjacencyMatrix;
  class comp {
    public:
      bool operator()(const pair<pair<int,int>,int>& p1, const pair<pair<int,int>,int>& p2) {
        return p1.second>p2.second;
      }
  };
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

  int shortestPath(int source, int dest) const
  {
    /* Dijiktra's Algorithm: Here, we try to calculate the shortest distance of
     * every node from source till we reach dest */
    vector<bool> nodesVisited(nVertices);
    vector<int> distance(nVertices, INT_MAX);

    int visitCount = 1;
    nodesVisited[source]=true;
    distance[source]=0;
    // dest cannot be visited if its unreachable from source
    while(nodesVisited[dest]!=true)
    {
      int nextNode=source;
      for (int j=0; j<nVertices; j++)
        if(!nodesVisited[j])
        {
          if(nextNode==source) nextNode=j;
          if(adjacencyMatrix[source][j])
            if(distance[j]>distance[source]+adjacencyMatrix[source][j])
              distance[j] = distance[source]+adjacencyMatrix[source][j];
          if(distance[nextNode]>distance[j]) nextNode = j;
        }
      if(nextNode==source) break;  // No next node found
      source = nextNode;
      nodesVisited[source]=true;
      visitCount++;
    }
    return distance[dest];
  }

  vector<int> shortestPathCodeZen(int source) const
  {
    /* Dijiktra's Algorithm: Here, we try to calculate the shortest distance of
     * every node from source till we reach dest */
    vector<bool> nodesVisited(nVertices);
    vector<int> distance(nVertices, INT_MAX);

    int visitCount = 1;
    nodesVisited[source]=true;
    distance[source]=0;
    while(visitCount!=nVertices)
    {
      int nextNode=source;
      for (int j=0; j<nVertices; j++)
        if(!nodesVisited[j])
        {
          if(nextNode==source) nextNode=j;
          if(adjacencyMatrix[source][j])
            if(distance[j]>distance[source]+adjacencyMatrix[source][j])
              distance[j] = distance[source]+adjacencyMatrix[source][j];
          if(distance[nextNode]>distance[j]) nextNode = j;
        }
      if(nextNode==source) break;  // No next node found
      source = nextNode;
      nodesVisited[source]=true;
      visitCount++;
    }
    return distance;
  }

  // 6 10 0 1 1 0 2 2 2 4 5 4 5 4 5 3 9 3 1 6 2 3 7 0 3 3 1 2 3 2 5 8 3 4 10
  void mstKruskal(vector<pair<pair<int,int>,int> >& edges) {
    /* here we need to pick edges with minimum weight. So, lets add all the
     * edges to a min priority queue */
    priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int,int>,int> >,
      comp> pq; 
    for(int i=0; i<nVertices; i++)
      for(int j=0; j<i; j++) // Note we all only adding lower part of matrix
        if(adjacencyMatrix[i][j]) {
          // Add the edge
          pair<int, int> p(i, j);
          pair<pair<int,int>,int> p2(p, adjacencyMatrix[i][j]);
          pq.push(p2);
        }

    vector<int> parent;
    for(int j=0; j<nVertices; j++) parent.push_back(j);
    vector<bool> visited(nVertices, false);

    while(edges.size()!=nVertices-1)
    {
      // pick the edge with minimum weight
      pair<pair<int,int>,int> p2 = pq.top();
      pq.pop();
      int from=p2.first.first, to=p2.first.second;

      // Can this edge be added to MST
      if(visited[from] && visited[to])
      {
        // Both nodes of edge already exist
        // Calculate parent of from and to
        int parentFrom = parent[from], parentTo = parent[to];
        while(parentFrom!=parent[parentFrom]) parentFrom = parent[parentFrom];
        while(parentTo!=parent[parentTo]) parentTo = parent[parentTo];
        if(parentFrom==parentTo) continue; // Cycle exist
      }
      // Add the edge
      edges.push_back(p2);
      visited[from] = visited[to] = true;
      if(from<to) parent[to] = from;
      else parent[from] = to;
    }
  }

  // 6 8 0 1 3 0 3 5 1 2 1 3 2 8 3 4 7 3 5 1 2 5 4 4 5 1
  void mstPrim(vector<pair<pair<int,int>,int> >& edges, int source=0) {
    vector<int> parent(nVertices, -1);
    vector<int> cost(nVertices, INT_MAX);
    vector<bool> visited(nVertices, false);
    //parent[source] = -1;
    cost[source]=0;
    while(source!=-1)
    {
      visited[source]=true;
      for(int j=0; j<nVertices; j++)
        if(!visited[j] && adjacencyMatrix[source][j])
          if(adjacencyMatrix[source][j] < cost[j])
          {
            cost[j] = adjacencyMatrix[source][j];
            parent[j] = source;
          }

      // Chose the next unvisited vertex with minimum cost
      source=-1;
      for(int j=0; j<nVertices; j++)
        if(!visited[j])
        {
          if(source == -1) source=j;
          else if(cost[j]<cost[source]) source = j;
        }
    }
    for(int j=0; j<nVertices; j++)
    {
      if(parent[j]==-1) continue;  // No edge for source
      // Add the edge
      pair<int, int> p(parent[j], j);
      pair<pair<int,int>,int> p2(p, adjacencyMatrix[p.first][p.second]);
      edges.push_back(p2);
    }
  }
};

class undirectedGraph: public graph {
  public:
    undirectedGraph(int nVertices)
      : graph(nVertices)
    {
    }

    void setEdge(pair<int,int> p, int weight=1) {
      graph::operator[](p) = weight;
      swap<int>(p.first, p.second);
      graph::operator[](p) = weight;
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
  int nVertices, nEdges, weight;
  cin >> nVertices >> nEdges;
  //graph g(nVertices);
  undirectedGraph g(nVertices);
  //vector<int> u, v;
  for(int i=0; i<nEdges; i++)
  {
    cin >> edge.first >> edge.second >> weight;
    g.setEdge(edge, weight);
    //u.push_back(edge.first);
    //v.push_back(edge.second);
    //g[edge] = weight;
    //swap<int>(edge.first, edge.second);
    //g[edge] = weight;
  }
  /*
  vector<int> distance = g.shortestPathCodeZen(0);
  copy(distance.begin(), distance.end(), ostream_iterator<int>(cout, " "));
  */

  vector<pair<pair<int,int>,int> > v;
  //g.mstPrim(v, 0);
  g.mstKruskal(v);
  for(int i=0; i<v.size(); i++)
  {
    int from = v[i].first.first, to = v[i].first.second, w = v[i].second;
    if(from<to) cout << from << ' ' << to << ' ' << w << endl;
    else cout << to << ' ' << from << ' ' << w << endl;
  }
  //cout << solve(nVertices, nEdges, u, v) << endl;
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
