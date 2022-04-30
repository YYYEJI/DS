// stack 예제 구현
#include <iostream>
using namespace std;
#define SIZE 100

class mystack{
    int list[SIZE];
    int top;
public:
    mystack();              // stack 초기화 하는 함수, constructor
    void push(int a);       // 현재 stack에서 원소 x추가
    int pop();              // 현재 stack에 원소 한 개를 삭제
    bool stack_full();      // 현재 stack 상태가 full인지 판단
    bool stack_empty();     // 현재 stack 상태가 empty인지 판단
};
int main(){
    mystack s1;
    int list[5] = { 32, 123, 27, 131, 242 }, i, x;

    for (i = 0; i < 5; i++ ){
        if (list[i] > 100)
            s1.push( list[i] );
    }    
    while ( !s1.stack_empty( ) ){
        x = s1.pop( );
        cout << x << endl ; 
    }
    return 0;
}
mystack::mystack(){
    top = 0;
}
void mystack::push(int a){
    list[top] = a;
    top++;
}
int mystack::pop(){
    top--;
    return list[top];
}
bool mystack::stack_full(){
    if(top>=SIZE) return true;
    else return false;
}
bool mystack::stack_empty(){
    if(top == 0) return true;
    else return false;
}
