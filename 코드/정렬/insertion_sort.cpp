#include <iostream>
using namespace std;

void insertion_sort(int list[], int n)
{
    int key;
    for(int i=1; i<n; i++)
    {
        key = list[i];
        for(int j=i-1;j>=0 && list[j] > key; j-- )
        {
            list[j+1] = list[j];
        }
        list[i+1] = key;
    }
}