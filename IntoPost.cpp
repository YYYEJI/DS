// infix -> postfix 변환 예제 (stack)
#include <iostream>
using namespace std;
#define SIZE 100
class IntoPost{
    char list[SIZE];
    int top;
public:
    IntoPost();
    void push(char s);
    char pop();
    bool stack_full();
    bool stack_empty();
    char top_element();        // stack top 위치의 element return
};
bool is_operand(char s);       // s가 operand이면 true return
int get_precedence(char s);    // operator의 precedence return 

int main(){
    IntoPost s;
    string input, output;
    char t;                    // pop해서 character 저장할 공간
    cout<<"Enter an infix expression to convert : ";
    cin>>input;
    input+='$';                // EOS(End of String)
    s.push('$');               // EOS(End of String)


    for(int i = 0; i<input.size(); i++){
        if(is_operand(input[i])) output+=input[i];
        else if(input[i] == '(') s.push(input[i]);
        else if(input[i] == ')') {
            for(int j = 0; j<input.size(); j++){
                if(s.top_element()=='(') {
                    t = s.pop();
                    break;
                }
                else output+=s.pop();
            }
        }
        else if(input[i]=='+'||input[i]=='-'||input[i] == '*'||input[i]=='/'||input[i]=='%'){
            for(int j = 0; j<input.size(); j++){
                if(get_precedence(input[i])>get_precedence(s.top_element())){
                    s.push(input[i]);
                    break;                    
                }
                else {
                    output+=s.pop();    
                }
            }
        }
        else{
            for(int j = 0; j<input.size(); j++){
                if(s.top_element()=='$') break;
                else output+=s.pop();
            }
        }
    }
    cout<<output;
    return 0;
}
IntoPost::IntoPost(){
    top = 0;
}
void IntoPost::push(char s){
    list[top] = s;
    top++;
}
char IntoPost::pop(){
    top--;
    return list[top];
}
bool IntoPost::stack_full(){
    if (top>=SIZE) return true;
    else return false;
}
bool IntoPost::stack_empty(){
    if(top == 0) return true;
    else return false;
}
char IntoPost::top_element(){
    return list[top-1];         
}
bool is_operand(char s){
    if((s == '(') || (s == ')')||
       (s == '+') || (s == '-')||
       (s == '*') || (s == '/')||
       (s == '%') || (s == '$'))
       return false;
    else return true;
}
int get_precedence(char s){
    if((s == '$')||(s=='(')) return 0;
    else if ((s=='+')||(s=='-')) return 1;
    else if ((s=='+')||(s=='/')||(s=='%')) return 2;
    return 3;
}