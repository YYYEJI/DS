// recursion 예제 : 주어진 array의 앞 쪽 n개 원소의 합
#include <iostream>
using namespace std;
int array_sum(int a[], int n);

int main(){
    int list[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int sum = array_sum(list, 3);

    cout<<sum;
    return 0;
}
int array_sum(int a[], int n){
    if(n==0) return 0;
    return a[n-1] + array_sum(a, n-1);
    //     index num           원소의 갯수
}