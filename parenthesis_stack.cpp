/* stack
세가지 유형의 괄호,  ( ),  { }, [ ] 를 사용하는 수식 표현에서,
괄호 사용의 오류를 점검하는 프로그램을 작성하시오.

Ex) 
(a + b) - [ c * {x - (a / b) } ]   ==> 정상
(a + b) - [ c * {x - (a / b} } ] ==> 괄호 불일치 ( }
(a + b) - [ c * {x - (a / b) }  ==> 닫는 괄호 누락
*/
#include <iostream>
using namespace std;
#define SIZE 100

class parenthesis{
    int list[SIZE];
    int top;
public:
    parenthesis();
    void push(char s);
    char pop();
    bool stack_full();
    bool stack_empty();
};
int main(){
    parenthesis s;
    string input;
    char t;
    cout << "Enter an infix expression : ";
    cin >> input;
    int length = input.size();
    int cnt = 0;                             // 괄호 개수 확인
    int p1 = 0, p2 = 0, p3 = 0;              // p1 '(', p2 '{', p3 '['
    int check1 = 0, check2 = 0, check3 = 0;  // check1 ')', check2 '}' check3 ']'
    
    for(int i = 0; i<length; i++){
        if(input[i] == '(' || input[i] == '{' || input[i] == '[')
            s.push(input[i]);    
    }
    for(int i = 0; i<length; i++){
        if(input[i]=='(' || input[i]=='{' || input[i]=='[' || input[i]==')' || input[i]=='}' || input[i]==']') 
            cnt++;   
    }

    if(cnt%2 == 1) cout << "닫는 괄호 누락\n";
    else{
        for(int i = 0; i<cnt/2; i++){
            t = s.pop();
            if(t == '(') p1 = 1;
            else if(t == '{') p2 = 1;
            else if(t == '[') p3 = 1;
            for(int j=length/2; j<length; j++){
                if(t == '(' && input[j] == ')') check1 = 1;
                else if(t == '{' && input[j] == '}') check2 = 1;
                else if(t == '[' && input[j] == ']') check3 = 1;
                else continue;  
            }
        }
    }
    // cout<<p1<<" "<<p2<<" "<<p3<<endl;                   // 확인용
    // cout<<check1<<" "<<check2<<" "<<check3<<endl;       // 확인용
    if(cnt%2==0){
        if((p1 == 1 && check1 == 0) || (p2 == 1 && check2 == 0) || p3 == 1 && check3 == 0) {
            cout << "괄호 불일치";
        }
        else cout << "정상";
    }
    return 0;
}

parenthesis::parenthesis(){
    top = 0;
}
void parenthesis::push(char s){
    list[top] = s;
    top++;
}
char parenthesis::pop(){
    top--;
    return list[top];
}
bool parenthesis::stack_full(){
    if(top>=SIZE) return true;
    else return false;
}
bool parenthesis::stack_empty(){
    if(top==0) return true;
    else return false;
}