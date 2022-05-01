// list를 이용한 recursion
// '주어진 array의 n개 정수 원소 중 가장 큰 값을 찾는  프로그램'
// list의 뒤에서부터 check
// 
#include <iostream>
using namespace std;
int find_max(int list[], int n);
int main()
{
    int a[10] = { 24, 12, 33, 27, 41, 15, 84, 52, 16, 72 };
    int m;

    m = find_max(a, 10);
    cout << m;

    return 0;

}
int find_max(int list[],int n)
{
    if(n==1)                             
        return list[0];                         // n은 원소의 갯수 즉, 1일 때 liss[0] 번째 return 
    else{
        if(find_max(list, n-1) > list[n-1])     // list[n-2]와 list[n-1] 비교
            return find_max(list, n-1);         // list[n-2]>list[n-1]
        else
            return list[n-1];                   // list[n-2]>list[n-1]
    }
}