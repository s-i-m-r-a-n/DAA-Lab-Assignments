#include<iostream>
#include<vector>
#include<queue>
#include<fstream>
using namespace std;
bool isbipartite(vector<vector<int>>& graph, int s)
{
    int V = graph.size();
    vector<int> visited(V);
    for(int i=0; i<V;i++)
        visited[i] = -1;
    visited[s] = 1;
    queue<int> qu;
    qu.push(s);
    while(!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        if(graph[u][u] == 1)
            return false;
        for(int v=0; v<V;v++)
        {
            if(graph[u][v] && visited[v] == -1)
            {
                visited[v] = 1 - visited[u];
                qu.push(v);
            }
            else if(graph[u][v] && visited[v] == visited[u])
                return false;
        }
    }
    return true;
}
int main()
{
    int n;
    ifstream file;
    file.open("input2.txt");
    if(!file)
    {
        cout<<"File not found";
        return 0;
    }
    file>>n;
    vector<vector<int>> graph(n,vector<int> (n,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            file>>graph[i][j];
    if(isbipartite(graph,0))
        cout<<"Bipartite"<<endl;
    else
        cout<<"Not Bipartite"<<endl;
    return 0;
}