#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<vector<int> > adj;

vector<bool> visited;
vector<int> order;

void dfs(int here)
{
    visited[here] = true;
    for(int there = 0; there < adj.size() ; there ++ )
    {
        if(adj[here][there] && !visited[there])
        {
            dfs(there);
        }
    }
    order.push_back(here);
}

void topologicalSort(){
    int n = adj.size();
    visited = vector<bool>(N,false);

    order.clear();

    for(int i=0; i<N; i++)
    {
        if(!visited[i])dfs(i);
    }
    reverse(order.begin(), order.end());
}

void printOrder(){
    for(int i = 0; i< order.size(); i++)
        printf("%c ", order[i] + 'A');
    printf("\n");
}