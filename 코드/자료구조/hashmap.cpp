#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, string> m;

    m.insert(make_pair(2, "a")); 
    m.insert(make_pair(1, "b"));
    m.insert(make_pair(3, "c"));
    m.insert(make_pair(4, "d"));
    m.insert(make_pair(5, "e"));

    unordered_map<int,string>::iterator iter;

     for (iter = m.begin(); iter != m.end(); iter++) {
        cout<<iter->first;
    } 

    return 0;
 }