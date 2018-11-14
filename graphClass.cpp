#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class graph {
    public:
        graph(int vertices);
        void setEdge(int a, int b, int cost=1);
        friend ostream& operator<<(ostream &cout, const graph &g);
        void DFT(int vertex=0) const;
        void BFT(int vertex=0) const;
        bool pathDFT(int a, int b, vector<int>& path) const;
        bool pathBFT(int a, int b, vector<int>& path) const;
    private:
        const int nVertices;
        int **adjacency;
        void DFT(int vertex, vector<bool>& visited) const;
        bool pathDFT(int a, int b, vector<bool>& visited, vector<int>& path) const;
};
graph::graph(int vertices)
    : nVertices(vertices)
{
    adjacency = new int* [nVertices];
    for(int i=0; i<nVertices; i++)
    {
        adjacency[i] = new int [nVertices];
        for(int j=0; j<nVertices; j++)
            adjacency[i][j] = 0;
    }
}
void graph::setEdge(int a, int b, int cost)
{
    adjacency[a][b] = adjacency[b][a] = cost;
}
ostream& operator<<(ostream &cout, const graph &g)
{
    for(int i=0; i<g.nVertices; i++)
    {
        for(int j=0; j<g.nVertices; j++)
            cout << g.adjacency[i][j] << ' ';
        cout << endl;
    }
    return cout;
}
void graph::DFT(int vertex) const
{
    vector<bool> visited(nVertices, false);
    DFT(vertex, visited);
    cout << endl;
}
void graph::DFT(int vertex, vector<bool>& visited) const
{
    if(visited[vertex]) return;
    cout << vertex << ' ';
    visited[vertex]=true;
    for(int i=0; i<nVertices; i++)
        if(adjacency[vertex][i])
            DFT(i, visited);
}
void graph::BFT(int vertex) const
{
    vector<bool> visited(nVertices, false);
    queue<int> q;
    q.push(vertex);
    visited[vertex]=true;
    while(!q.empty())
    {
        vertex = q.front();
        q.pop();
        cout << vertex << ' ';
        for(int i=0; i<nVertices; i++)
            if(adjacency[vertex][i] && !visited[i])
            {
                q.push(i);
                visited[i]=true;
            }
    }
    cout << endl;
}
bool graph::pathBFT(int a, int b, vector<int>& path) const
{
    if(b==a) return true;
    vector<bool> visited(nVertices, false);
    unordered_map<int, int> m;
    queue<int> q;
    q.push(a);
    visited[a]=true;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        for(int i=0; i<nVertices; i++)
            if(adjacency[front][i] && !visited[i])
            {
                if(i==b)
                {
                    path.push_back(b);
                    i=front;
                    // Update path
                    while(i!=a)
                    {
                        path.push_back(i);
                        i = m[i];
                    }
                    path.push_back(a);
                    return true;
                }
                q.push(i);
                visited[i]=true;
                m[i] = front;
            }
    }
    return false;
}
bool graph::pathDFT(int a, int b, vector<int>& path) const
{
    vector<bool> visited(nVertices, false);
    bool ans = pathDFT(a, b, visited, path);
    if(ans)
        path.push_back(a);
    return ans;
}
bool graph::pathDFT(int a, int b, vector<bool>& visited, vector<int>& path)const
{
    if(b==a) return true;
    if(visited[a]) return false;
    visited[a]=true;
    for(int i=0; i<nVertices; i++)
        if(adjacency[a][i])
        {
            if(i==b)
            {
                path.push_back(i);
                return true;
            }
            bool ans = pathDFT(i, b, visited, path);
            if(ans)
            {
                path.push_back(i);
                return true;
            }
        }
    return false;
}

int main()
{
    graph g1(9);
    g1.setEdge(0,1);
    g1.setEdge(0,2);
    g1.setEdge(3,1);
    //g1.setEdge(2,4);
    g1.setEdge(3,5);
    g1.setEdge(5,6);
    g1.setEdge(5,7);
    g1.setEdge(5,8);
    g1.setEdge(7,8);


    // Another Graph g2
    graph g2(7);
    g2.setEdge(0,1);
    g2.setEdge(0,2);
    g2.setEdge(5,1);
    g2.setEdge(2,3);
    g2.setEdge(2,6);
    g2.setEdge(4,5);

    graph& g=g2;

    cout << g;
    g.DFT();
    g.BFT();
    vector<int> path;
    bool hasPath = g.pathBFT(4, 6, path);
    if(hasPath)
    {
        copy(path.begin(), path.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}

