#include <iostream>
#include <list>
using namespace std;

int main(){
    list <int> a;
    list <int>::iterator p;

    a.push_back(25);
    a.push_back(17);
    a.push_back(33);
    a.push_back(19);

    a.sort();

    for(p = a.begin(); p!=a.end(); p++)      // 17 : 19 : 25 : 33 : 
        cout<<*p<<" : ";
    cout<<endl;
}