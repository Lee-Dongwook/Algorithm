#include <iostream>
using namespace std;

void Shellsort(int arr[], int len)
{
    int gap = len/2;
    int temp;
    int j;
    while(gap>0)
    {
        for(int i = gap; i<len ; i++)
        {
            temp = arr[i];
            j = i;
            while(j >= gap && arr[j-gap] > temp)
            {
                arr[j] = arr[j-gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap /= 2;
    }
}