#include <iostream>
using namespace std;

#define MAX 10000

template<typename T> 
class Queue
{
    private:
        int front;
        int rear;
        int size;
        T * values;
    public:

    Queue(){
        size = MAX;
        values = new T[size];
        front = 0;
        rear = 0;
    }
    ~Queue(){
        delete[] values;
    }
    void push(T value)
    {
        if(!isFull())
        {
            values[rear] = value;
            rear = (rear+1) % size;
        }
        else{
            cout<< "Queue is full"<<endl;
        }
    }
    void pop(){
        if(!empty){
            front = (front+1) %size;
        }
        else{
            cout<<"Queue is empty"<<endl;
        }
    }
    bool empty()
    {
        if(front == rear){
            return true;
        }
        else{
            return false;
        }
    }
    bool isFull(){
        if((rear+1)%size == front)
        {
            return true;
        }
        else {
            return false;
        }
    }
    int size(){
        return rear - front + 1;
    }
};