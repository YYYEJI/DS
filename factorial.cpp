// recursion 예제 : Factorial
#include <iostream>
using namespace std;
int factorial(int n);

int main(){
    int num, f;  
    cout << "Enter a number > ";
    cin>>num;

    f = factorial(num);
    
    cout<<f;
    return 0;
}
int factorial(int n){
    if(n == 0) return 1;
    else return (n*factorial(n-1));
}