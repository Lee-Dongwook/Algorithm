#include <iostream>
using namespace std;

void selection_sort(int list[], int n)
{
    int least;
    for(int i=0; i<n-1; i++)
    {
        least = i;
        for(int j=i+1;j<n;j++){
        if(list[j]<list[least])
        {
            least = j;
        }
        }

        if(i == least)
        {
            swap(list[i],list[least]);
        }
    }
}