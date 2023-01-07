#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visited[10];
vector<int>graph[10];

void dfs(int x)
{
    visited[x] = true;
    cout<<x<<" ";
    for(int i =0; i<graph[x].size(); i++)
    {
        int y = graph[x][i];
        if(!visited[y])
        {
            dfs(y);
        }
  }
}

void bfs(int start)
{   
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        cout<<x<<" ";
        for(int i=0;i<graph[x].size();i++)
        {
            int y = graph[x][i];
            if(!visited[y])
            {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}