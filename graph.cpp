#include <iostream>
#include <vector>
using namespace std;

const int N = 10;
const int M = 10;

void graph1(){
    /*행렬을 이용한 구현*/

    int graph[N+1][N+1];

    for(int i=0;i<= N; i++)
    {
        for(int j=0;j<=N;j++)
        {
            graph[i][j] = -1;
        }
    }

    for(int i=0; i<M; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
}

void graph2(){
    /*vector로 linked list 구현*/

    vector<int> graph[N+1];

    for(int i=0; i<M;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

}