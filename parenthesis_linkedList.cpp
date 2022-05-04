/* linked list 
과제 03번 ~ 07번까지 본인에 제출한 과제 중 한 개를 선택하여,
Stack (또는 queue) 를 Linked List 를 사용하여 구현한 버전으로 수정(재작성)하여 제출

6번 풀었습니다!
*/
#include <iostream>
using namespace std;
class node {
public:
    char s;
    node *link;
    void set_data(char c);
};
class linked_stack{
    node *top;
public:
    linked_stack();
    void push(node n);
    node pop();
    bool stack_empty();
};
int main(){
    linked_stack s;   
    string input;
    node temp;
    string ch;
    int start;
    int check = 0;

    cout<<"Input something sentence > ";
    getline(cin, input); // 공백 포함 라인 받기
    
    input.erase(remove(input.begin(), input.end(), ' '), input.end());    // 공백 제거
    int length = input.size();  

    for(int i = 0; i<length/2; i++){
        temp.set_data(input[i]);
        s.push(temp);
    }
    if(length%2==0) start = length/2;
    else start = length/2+1;

    for(int i = start; i<length; i++){
        temp = s.pop();
        // cout<<temp.s;  
        if(temp.s != input[i]) check = 1;
    }
    
    if(check == 1) cout<<"It is not palindrome";
    else cout<<"It is palindrome";
    return 0;
}

void node::set_data(char c){
    s = c;
}
linked_stack::linked_stack(){
    top = NULL;
}
void linked_stack::push(node n){
    node *p;
    p = new node;
    (*p) = n;

    p->link = top;
    top = p;
}
node linked_stack::pop(){
    node temp;
    node *t;

    temp = (*top);
    t = top;

    top = top->link;
    delete t;

    return temp;
}
bool linked_stack::stack_empty(){
    if(top == NULL) return true;
    else return false;
}