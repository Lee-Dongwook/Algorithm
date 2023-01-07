#include <iostream>
#include <string>
using namespace std;

#define MAX 10000

template<typename T>
class stack{
    private:
        T_data[MAX];
        int top;
    public:
     stack(){
        top = -1;
     }
     ~stack(){

     }
     void push(T input)
     {
        if(!isfull()){
        data[top+1] = input;
        top += 1;
        }
        else{
            cout<<"stack is Full"<<endl;
        }
     }
     T pop(){
        if(!empty()){
        T res = data[top];
        top -= 1;
        return res;
        }
        else{
            return -1;
        }
     }
     int size(){
        return top +1;
     }
     bool empty(){
        return size() == 0 ? true : false;
     }
     bool isfull(){
        return top>=size() ? true : false; 
     }
     T top(){
        T res = data[top];
        return res;
     }
};