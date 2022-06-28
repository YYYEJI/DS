#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> a;
    vector <int>:: iterator p;     // iterator 선언
    unsigned int k;
    
    a.push_back(3);
    a.push_back(4);
    a.push_back(7);

    p = a.begin()+2;
    a.insert(p,3,5);

    for(k = 0; k<a.size(); k++)            // 3:4:5:5:5:7:
        cout<<a[k]<<" : ";
    cout<<endl;

    vector <int> b(a);
    b.insert(b.begin()+3, a.begin(), a.begin()+3);

    for(k = 0; k<b.size(); k++)            // 3:4:5:3:4:5:5:5:7:
        cout << b[k] <<" : ";
    cout<<endl;

    p = b.begin()+2;
    b.erase(p,p+2);

    for(k=0; k<b.size(); k++)              // 3:4:4:5:5:5:7:
        cout<<b[k]<<" : ";
    cout<<endl;
}