
/*
    단일점 알고리즘 : 다익스트라 알고리즘
    시작 정점에서 다른 모든 정점까지 가는 최단 거리를 구함

    다익스트라 알고리즘
    1. 시작 정점에서 아직 방문하지 않은 정점 중 가장 거리가 가까운 정점을 찾음
    2. 시작 정점에서 다른 모든 정점까지의 최단 거리를 저장하는 dist 배열
    3. 방문한 정점에 대해서 기록하는 visited 배열이 필요

*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

#define MAX_VERTICES 100
#define INF 987654321

vector< pair<int,int> > graph[MAX_VERTICES];

void dijkstra(int start)
{
    vector<int> distance(MAX_VERTICES, INF);
    vector<bool> visited(MAX_VERTICES, false);

    distance[start] = 0;
    visited[start] = true;

    while(1)
    {
        int closest = INF, here;
        for(int i=0; i<MAX_VERTICES; i++)
        {
            if(!visited[i] && distance[i]<closest)
            {
                here = i;
                distance[i] = closest;
            }
            if(closest == INF)break;

            for(int i=0; i<graph[here].size(); i++)
            {
                int next = graph[here][i].first;
                if(visited[next])continue;
                int nextDist = distance[here] + graph[here][i].second;
                distance[next] = min(distance[next],nextDist);
            }
        }
    }

}

void priority_dijkstra(int start)
{
    //우선순위 큐를 이용한 다익스트라 알고리즘 코드 구현
    vector<int> distance(MAX_VERTICES, INF);
    distance[start] = 0;
    priority_queue<pair<int,int> > pq;
    pq.push({0,start});
    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(distance[here] < cost) continue;
        for(int i=0;i<graph[here].size(); i++)
        {
            int next = graph[here][i].first;
            int nextDist = cost + graph[here][i].second;

            if(nextDist <distance[next])
            {
                distance[next] = nextDist;
                pq.push({-nextDist, next});
            }
        }
    }

}

