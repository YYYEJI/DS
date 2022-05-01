// recursion 예제 : 1부터 n까지 정수의 합 (AP: arithmetic progression)
#include <iostream>
using namespace std;
#define SIZE 100
int num_sum(int n);

int main(){
    int num, s;
    cout<<"Enter a number > ";
    cin>>num;

    s = num_sum(num);

    cout << s;
    return 0;
}
int num_sum(int n){
    if (n==1) return 1; 
    else return (n+num_sum(n-1));
}