// recursion 예제 : 순열(Permutation)
#include <iostream>
using namespace std;
int permutation(int n, int m);

int main(){
    int p;
    p = permutation(8,2);

    cout<<p;
    
    return 0;
}
int permutation(int n, int m){
    if(m == 0) return 1;
    else return (n*permutation(n-1, m-1));
}