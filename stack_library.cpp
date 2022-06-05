// Stack class
/*
- empty stack 생성 
  * stack <int>         s1
  * stack <double>      s2
  * stack <s_record>    s3
  
- stack class의 member functions
  * push(): 원소를 넣는 함수, void type
  * pop() : 원소를 삭제하는 함수, void type 임에 유의
  * top() : 현재 top 위치의 원소를 읽는 함수
  * size(): 현재 원소 개수를 return 
*/
#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <int> s1;

    s1.push(3);
    s1.push(4);
    s1.push(5);

    s1.pop();
    int n1 = s1.top();
    int n2 = s1.size();

    cout<<n1<<", "<<n2<<endl;
}