#include <iostream>
using namespace std;

void QuickSort(int data[],int left, int right)
{
    int L = left, R = right;
    int pivot = (L+R)/2;
    if(L<R)
    {
        while(L<R){
            while(data[L]<= data[pivot])L++;
            while(data[R]>data[pivot])R--;
            if(L<R) swap(data[L],data[R]);

        }
        swap(data[R], data[pivot]);
        pivot = R;
        QuickSort(data,left, pivot-1);
        QuickSort(data,pivot+1,right);
    }
}