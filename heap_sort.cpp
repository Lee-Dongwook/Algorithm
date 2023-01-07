#include <iostream>
using namespace std;

int arr[1000];

void swap(int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}


void makeheap(int root, int n)
{
    int temp = arr[root];
    int child = root * 2;
    while (child <= n)
    {
        if(child < n && arr[child]< arr[child+1])
        {
            child++;
        }
        if(temp < arr[child])
        {
            arr[child/2] = arr[child];
            child *= 2;
        }
        else break;
    }
    arr[child/2] = temp;
}

void heapsort(int n)
{
    for(int i = n/2 ; i > 0 ; i--)
    {
        makeheap(i,n);
    }
    int temp;
    for(int i=n; i>0; i--)
    {
        swap(1,i);
        makeheap(1,i-1);
    }
}