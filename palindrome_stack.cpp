/* stack
 어떤 주어진 string이 Palindrome(좌우 대칭인 string)인지 여부를 판단하는 프로그램을,  stack를 사용하여 구현하시오.

* 영문자만 고려하며, 두 단어 이상의 string에서도 가능하도록 함,  띄어쓰기(space)는 무시할 것,
  예를 들어 'race car' 도 palindrome으로 판단
*/
#include <iostream>
using namespace std;
#define SIZE 100

class palindrome{
    char list[SIZE];
    int top;
public:
    palindrome();
    void push(char s);
    char pop();
    bool stack_full();
    bool stack_empty();
};
int main(){
    palindrome p;
    string stc;
    char t;
    int start;
    int check = 0;

    cout << "Enter something sentence > ";
    getline(cin, stc);       // 공백 포함 라인 받기

    stc.erase(remove(stc.begin(), stc.end(), ' '), stc.end());       // 공백 제거
    int length = stc.size();

    for(int i = 0; i<length/2; i++){
        p.push(stc[i]);
    }
    if(length%2 == 0) start = length/2;
    else start = length/2+1;

    for(int i = start; i<length; i++){
        t = p.pop();
        if(t != stc[i]) check = 1;
    }

    if(check == 1) cout<<"It is not palindrome";
    else cout<<"It is palindrome";

    return 0;
}
palindrome::palindrome(){
    top = 0;
}
void palindrome::push(char s){
    list[top] = s;
    top++;
}
char palindrome::pop(){
    top--;
    return list[top];
}
bool palindrome::stack_full(){
    if(top>=SIZE) return true;
    else return false;
}
bool palindrome::stack_empty(){
    if(top == 0) return true;
    else return false;
}
