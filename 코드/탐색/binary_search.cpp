#include <iostream>
using namespace std;

int binarysearch(int arr[],int key, int left, int right)
{
    int mid = (left+right)/2;
    if(left<=right)
    {
        if(key==arr[mid])return 1;
        else if(key<arr[mid])return binarysearch(arr,key,left, mid-1);
        else return binarysearch(arr,key,mid+1,right);
    }
    else return 0;
}