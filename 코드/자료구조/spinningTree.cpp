
/*
    최소 비용 신장 트리 Minimum Spanning Tree
    - 가장 적은 비용으로 모든 노드를 연결하고자 할 때 
    모두 연결하되 최소 비용으로 연결하는 BST를 만들고
    크루스칼 알고리즘 혹은 프림 알고리즘으로 MST를 만든다

    크루스칼 알고리즘(Kruskal)
    - 무조건 가장 비용이 작은 간선부터 선택에 나간다는 점에서 Greedy한 알고리즘
    - 선택한 간선이 사이클을 이루지 않도록 한다

    프림 알고리즘(Prim)
    - 시작 할 때 시작 정점만 MST 집합에 포함시키고 
    현재까지의 MST 집합에 포함된 정점들 중에서 인접한 정점들 중
    가중치 최소 간선으로 연결된 정점을 선택하여 트리를 확장
    사이클이 생기지 않는다.


*/


//1. 크루스칼 알고리즘
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int getRoot(vector<int> & parent, int x) //부모 노드 가져옴
{
    if(parent[x] == x) return x;
    return parent[x] = getRoot(parent, parent[x]);
}

void unionParent(vector<int>& parent, int a, int b)//부모 노드를 병합
{
    int par_a = getRoot(parent, a);
    int par_b = getRoot(parent, b);
    if(par_a < par_b)parent[par_b] = par_a;
    else parent[par_a] = par_b;
}

bool find(vector<int> & parent, int a, int b)// 같은 부모를 가지는지 확인
{
    int par_a = getRoot(parent, a);
    int par_b = getRoot(parent, b);
    if(par_a == par_b) return true;
    else return false;
}

//간선 클래스 구현
class Edge{
    public:
     int node[2];
     int distance;
     Edge(int a, int b, int distance)
     {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
     }
     bool operator <(Edge &edge){
        return this->distance < edge.distance;
     }
};

bool compare(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {	
    int answer = 0;
    
	sort(costs.begin(), costs.end(), compare);
    
    vector<int> parents(n);
    
    for(int i = 0; i < parents.size(); i++)
        parents[i] = i;
    
    for(int i = 0; i < costs.size(); i++)
    {
        if(!find(parents, costs[i][0], costs[i][1]))
        {
            unionParent(parents, costs[i][0], costs[i][1]);
            answer += costs[i][2];
        }
    }

	return answer;
}


//2. 프림 알고리즘

int solution2(int n, vector<vector<int>> costs) {
	int answer = 0;

	vector<vector<int>> graph(n, vector<int>(n));
	for (int i = 0; i < costs.size(); i++)
	{
		graph[costs[i][0]][costs[i][1]] = costs[i][2];
		graph[costs[i][1]][costs[i][0]] = costs[i][2];
	}

	vector<int> visited;
	vector<int> unvisited;

	visited.push_back(0);
	for (int i = 1; i < n; i++)
		unvisited.push_back(i);

	for (int i = 1; i < n; i++)
	{
		int min = INT_MAX;
		int min_index = 0;

		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < n - i; k++)
			{
				if (graph[visited[j]][unvisited[k]] > 0 && min > graph[visited[j]][unvisited[k]])
				{
					min = graph[visited[j]][unvisited[k]];
					min_index = k;
				}
			}
		}

		visited.push_back(unvisited[min_index]);
		unvisited.erase(unvisited.begin() + min_index);
		answer += min;
	}

	return answer;
}