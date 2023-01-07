#include <iostream>
using namespace std;

#define Max 10000

class Deque{
    private:
        int data[Max];
        int index_front;
        int index_back;
    public:
    Deque(){
        index_front = 0;
        index_back = 0;
    }
    ~Deque(){}
    bool empty(){
        return index_front == index_back ? true : false;
    }
    bool isfull(){
        return index_front == (index_back+1) %Max ? true : false;
    }
    void push_front(int x){
        if(!isfull()){
            data[index_front] = x;
            index_front = (index_front-1 + Max) % Max;
        }
        else{
            cout<<"deque is Full"<<endl;
        }
    }
    void push_back(int x){
        if(!isfull()){
            index_back = (index_back+1) % Max;
            data[index_back] = x;
           
        }
        else{
            cout<<"deque is full"<<endl;
        }
    }
    void pop_front(){
        if(!empty())
        index_front = (index_front+1) % Max;
        else
        cout<<"deque is Empty"<<endl;
    }
    void pop_back(){
        if(!empty())
        index_back = (index_back-1+Max)%Max;
        else
        cout<<"deque is Empty"<<endl;
    }
    int front(){
        return data[(index_front + 1) % Max];
    }
    int back(){
        return data[index_back];
    }
    int size(){
        return (index_back - index_front + Max) % Max;
    }

};