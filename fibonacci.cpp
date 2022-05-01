// recursion 예제 : Fibonacci number
#include <iostream>
using namespace std;
int fib_no(int n);

int main(){
    int num, f;
    cout<<"Enter a number > ";
    cin>>num;

    f = fib_no(num);

    cout<<f;
    return 0;
}
int fib_no(int n){
    if(n == 0) return 0;
    else if(n==1) return 1;
    return (fib_no(n-1)+fib_no(n-2));
}