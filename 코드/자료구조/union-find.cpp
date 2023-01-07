/*
    서로소 집합(disjoint-set) 자료구조
    합집합 찾기(union- find) 자료구조
    병합 찾기(merge-find set) 자료구조

*/

#include <iostream>
using namespace std;

int parent[100];
int n = 100;

void init()
{
    for(int i=1; i<=n; i++)
    parent[i] = i;
}

int Find(int x)
{
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if(x!=y)
    {
        if(x<y)
        {
            parent[y] = x;
        }
        else{
            parent[x] = y;
        }
    }
}