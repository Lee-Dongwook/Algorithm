#include <iostream>
#define MAX 10000
using namespace std;

void merge(int left, int right)
{
    int sorted[MAX];
    int arr[MAX];
    int mid = (left+right) / 2;

    int i = left, j= mid + 1, k = left;
    while(i <= mid && j <= right)
    {
        sorted[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];

    }
    int tmp = (i>mid)? j : i;
    while (k<=right)
    {
        sorted[k++] = arr[tmp++];
    }

    for(int i = left; i <= right; i++)
    {
        arr[i] = sorted[i];
    }
}

void merge_sort(int left, int right)
{
    int mid;
    if(left<right)
    {
        mid = (left + right)/2;
        merge_sort(left, mid);
        merge_sort(mid+1,right);
        merge(left,right);
    }
}