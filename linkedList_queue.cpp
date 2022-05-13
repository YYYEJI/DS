/* queue as linked list
   Linked list의 첫 원소의 위치를 front(삭제할 위치)로 유지
   Linked list의 끝 원소의 위치를 Rear(추가할 위치)로 유지
*/
#include <iostream>
using namespace std;
class node{
public:
    string name;
    double score;
    node *link;
    void set_data(string s, double n);
};
class my_queue{
    node *front, *rear;
public:
    my_queue();
    void insert_q(node t);
    node delete_q();
    bool queue_empty();
};
int main(){
    my_queue a;
    node tmp;
    
    tmp.set_data("KIM", 22.2);
    a.insert_q(tmp);
    tmp.set_data("LEE", 33.3);
    a.insert_q(tmp);
    tmp.set_data("PARK", 44.4);
    a.insert_q(tmp);
    tmp.set_data("CHIO", 55.5);
    a.insert_q(tmp);
    tmp = a.delete_q();
    cout << tmp.name << " : " << tmp.score <<"\n";
    tmp = a.delete_q();
    cout << tmp.name << " : " << tmp.score <<"\n";
    
    return 0;
}
my_queue::my_queue(){
    front = NULL;
    rear = NULL;
}
void node::set_data(string s, double n){
    name = s;
    score = n;
}
void my_queue::insert_q(node t){
    node *p;
    p = new node;
    (*p) = t;

    p->link = NULL;
    if(rear!=NULL) rear->link = p;
    else front = p;
    
    rear = p;
}
node my_queue::delete_q(){
    node temp;
    node *t;

    t = front;
    temp = *front;
    
    front = front->link;
    delete t;
    if(front == NULL) rear = NULL;

    return temp;  
}
bool my_queue::queue_empty(){
    if(front == NULL) return true;
    else return false;
}