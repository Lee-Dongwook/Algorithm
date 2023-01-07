#include <iostream>
using namespace std;

void bubble_sort(int list[], int n)
{
    for(int i= n-1; i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(list[j]<list[j+1])
            {
                swap(list[j],list[j+1]);
            }
        }
    }
}