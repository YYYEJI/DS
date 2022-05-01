/* stack as linked list
   Linked list의 첫 원소의 위치를 top으로 위치
   push와 pop을 모두 top에서 수행
*/
#include <iostream>
using namespace std;
#define SIZE 100
class node{
public:
    string name;
    double score;
    node *link;
    void set_data(string n, double s);
};
class my_stack{
    node *top;
public:
    my_stack();
    void push(node t);
    node pop();
    bool stack_empty();
};
int main(){
    my_stack a;
    node tmp;
    tmp.set_data("KIM", 22.2);
    a.push(tmp);
    tmp.set_data("LEE", 33.3);
    a.push(tmp);
    tmp.set_data("PARK", 44.4);
    a.push(tmp);
    tmp.set_data("CHOI", 55.5);
    a.push(tmp);
    tmp = a.pop();
    cout << tmp.name << " : " << tmp.score <<"\n";
    tmp = a.pop();
    cout << tmp.name << " : " << tmp.score <<"\n";
    
    return 0;
}
void node::set_data(string n, double s){
    name = n;
    score = s;
}
my_stack::my_stack(){
    top = NULL;
}
void my_stack::push(node t){
    node *p;
    p = new node;
    (*p) = t;
    
    p->link = top;
    top = p;
}
node my_stack::pop(){   // empty check는 main()에서 하기
    node temp;
    node *t; 

    t = top; 
    temp = *top;          
    
    top = top -> link;         
    delete t;                   

    return temp;
}
bool my_stack::stack_empty(){
    if(top == NULL) return true;
    else return false;
}