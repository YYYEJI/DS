// recursion 예제 : 1에서 n까지 정수 범위에서 짝수의 합
#include <iostream>
using namespace std;
int even_sum(int n);
int main(){
    int num, f;
    cout<<"Enter a number > ";
    cin>>num;

    f = even_sum(num);

    cout<<f;
    return 0;
}
int even_sum(int n){
    if(n==1) return 0;
    else{
        if(n%2==0) return n + even_sum(n-1);
        else return even_sum(n-1);
    }
}