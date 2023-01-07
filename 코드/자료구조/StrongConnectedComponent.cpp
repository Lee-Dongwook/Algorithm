#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX  = 10001;

int v,e,id;
int d[MAX];
int sccNum; // scc 개수
int sn[MAX]; // i가 속한 SCC 번호
vector<int> a[MAX];
bool finished[MAX]; // SCC가 성립되면 true
stack<int> s;
vector<vector <int> > SCC;

int DFS(int c)
{
    d[c] = ++id;
    s.push(c);

    int result = d[c];
    for(int next : a[c])
    {
        if(d[next] == 0) result = min(result , DFS(next));
        else if(!finished[next])result = min(result, d[next]);
    }
    if(result == d[c])
    {
        vector<int> scc;
        while(1)
        {
            int t = s.top();
            s.pop();
            scc.push_back(t);
            finished[t] = true;
            sn[t] = sccNum;
            if(t==c)break;
        }
        sort(scc.begin(), scc.end());
        SCC.push_back(scc);
        sccNum++;
    }
    return result;
}