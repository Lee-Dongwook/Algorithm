/*
    우선순위 큐는 Container의 한 종류이며
    설정된 우선순위에 따라 가장 Top을 유지하고 먼저 Out(pop)
    하는 방식이다.
*/

#include <iostream>
#include <queue>
#include <utility> //pair 사용
using namespace std;

struct cmp{
    bool operator() (int a, int b)
    {
        return a > b;
    }
};

int main(void)
{
    priority_queue<int, vector<int>, cmp> pq;

    pq.push(5);
    pq.push(3);
    pq.push(6);
    pq.push(1);
    pq.push(2);

    while(!pq.empty())
    {
        int temp = pq.top();
        cout<<temp;
        pq.pop();
    }

    return 0;

}

