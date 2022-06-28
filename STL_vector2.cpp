#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> a;
    unsigned int k;

    a.push_back(3);
    a.push_back(4);
    a.push_back(7);

    vector <int> b(a);        
    if(a==b)                       // YES
        cout<<"YES\n";
    else    
        cout<<"NO\n";

    b.push_back(8);
    if(a==b)                       // NO
        cout<<"YES\n";
    else    
        cout<<"NO\n";

    a.swap(b);                     // 3:4:7:8:
    for(k = 0; k<a.size(); k++)
        cout<<a[k]<<" : ";
    cout<<endl;                    // 3:4:7:
    for(k = 0; k<b.size(); k++)
        cout<<b[k]<<" : ";
    cout<<endl;
}