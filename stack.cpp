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
        data[top+1] = input;
        top += 1;
     }
     T pop(){
        T res = data[top];
        top -= 1;
        return res;
     }
     int size(){
        return top +1;
     }
     bool empty(){
        return size() == 0 ? true : false;
     }
     T top(){
        T res = data[top];
        return res;
     }
};