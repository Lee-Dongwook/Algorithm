#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge_sort(vector<int>& data, int left, int right)
{
    if(left>=right)return;
    
       int mid = (left + right)/2;
       merge_sort(data,left, mid);
       merge_sort(data,mid+1,right);
      
    vector<int> temp(right-left+1);
    int i= left, j = mid +1;

    for(int k=0;k<temp.size();k++)
    {
        if(i<=mid && j<=right)
        {
            temp[k] = data[i]<=data[j] ? data[i++]:data[j++];

        }
        else{
            temp[k] = i <= mid ? data[i++] : data[j++];
        }
    }
    for(int k = 0; k<temp.size(); k++)
    {
        data[left++] = temp[k];
    }
}