#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n = 10;
int h = (int)ceil(log2(n));
int tree_size = (1 << (h+1));

long long init(vector<long long> & arr, vector<long long> &tree, int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;

    return tree[node] = init(arr,tree,node *2, start , mid ) + init(arr, tree, node * 2 +1, mid + 1, end);
}

long long sum(vector<long long> &tree, int node, int start, int end, int left, int right)
{
    if(left > end || right < start ) return INT_MAX;
    if(left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;

    return sum(tree, node*2, start, mid, left, right) + sum(tree, node*2+1, mid+1, end, left, right);
}

void update(vector<long long> &tree, int node, int start, int end, int index, long long diff)
{
    if(index < start || index > end)return;
    tree[node] = tree[node] + diff;

    if(start!= end)
    {
        int mid = (start + end) /2;
        update(tree, node*2, start, mid, index, diff);
        update(tree, node*2+1, mid+1, end, index, diff);
    }

}