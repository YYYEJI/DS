/*
강의에서 설명한 구조의 linked list를 구현하고, 아래의 main function의 의도대로 동작하도록

관련 function을 작성하시오. 
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
class my_list{
    node *head, *tail;
public:
    my_list();
    void add_to_head(node t);
    void add_to_tail(node t);
    node delete_from_head();
    int num_nodes();
    double score_sum();
    double get_score(string t_name);
    int remove_a_node(string t_name);
    bool list_empty();
    void invert();                 // node 역방향으로 바꾸기
    friend bool list_equal(my_list a, my_list b);    // 두 개의 list equality check
};
bool list_equal(my_list a, my_list b);
bool is_equal(node *p1, node *p2);
bool equal_data(node t1, node t2);

my_list::my_list(){
    head = NULL;
    tail = NULL;
}
int main(){
    my_list a,b;
    node   tmp;
    
    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp);
    tmp.set_data("Park", 91.3);
    a.add_to_head(tmp);
    tmp.set_data("Choi", 85.1);
    a.add_to_head(tmp);
    tmp.set_data("Choi", 85.1);
    b.add_to_head(tmp);
    tmp.set_data("Park", 91.3);
    b.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    b.add_to_head(tmp);
    tmp.set_data("Kim", 83.5);
    b.add_to_head(tmp);
    b.invert();
    
    if (list_equal(a, b))cout << "Yes, the two lists are identical. \n";
    else
        cout << "No, They are not identical.\n";
    
    tmp= b.delete_from_head();
    cout << tmp.name << " : " << tmp.score<< "\n";
    
    return 0;
}
void node::set_data(string s, double n){
    name = s;
    score = n;
}
void my_list::add_to_head(node t){
    node *p;
    p = new node;
    (*p) = t;

    p->link = head;
    head = p;
    if(tail == NULL) tail = p;
}
void my_list::add_to_tail(node t){
    node *p;
    p = new node;
    (*p) = t;

    p->link = NULL;         
    if(tail!=NULL) tail -> link  = p;
    else head = p;

    tail = p;
}
node my_list::delete_from_head(){
    node temp;
    node *t;                    // delete하기 위해서 기억하는 장소, head가 옮겨지면 그 node는 어딘가에서 돌아댕김 
   
    t = head;        
    temp = *head;               // return 될 값 삭제 전 저장
    head = head -> link;        // head에서 삭제된 다음 Node와 연결
   
    delete t;                   // node 삭제 
    if(head == NULL) tail = NULL;
 
    return temp;
}
int my_list::num_nodes(){
    node *t;
    int cnt = 0;
    for(t = head;t!=NULL; t = t->link) cnt++;

    return cnt;
}
double my_list::score_sum(){
    node *t;
    double sum = 0;
    for(t = head; t!=NULL; t=t->link) {
        sum += t->score;
    }
    return sum;
}
double my_list::get_score(string t_name){
    node *t;
    for(t = head; t!=NULL; t = t->link){
        if(t->name == t_name) 
            return t->score;

    }
    return 0;
}
int my_list::remove_a_node(string t_name){ 
    node *pre_node;    // 진행하고 있는 상황에서 앞 전 노드/ *를 지워야되나요?
    node *t;
    for(t = head; t!=NULL; t = t->link){
        if (t->name == t_name) {
            // t = t->link;
            pre_node->link = t->link;
            delete t;
            return 1;
        }
        pre_node = t;
    }
    return 0;

}
bool my_list::list_empty(){
    if(head==NULL) return true;
    else return false;
}
void my_list::invert(){
    node *newhead;
    node *oldhead;
    node *tmp;

    newhead = NULL;
    oldhead = head;

    while(oldhead != NULL){
        tmp = newhead;
        newhead = oldhead;
        oldhead = oldhead->link;
        newhead->link = tmp;
    }
 
    tail = head;
    head = newhead;
    
}
bool list_equal(my_list a, my_list b){
    return is_equal(a.head, b.head);
}
bool is_equal(node *p1, node *p2){
    if((p1 == NULL) && (p2 == NULL)) return true;     // 둘 다 null 이면 true
    if((p1 == NULL) || (p2 == NULL)) return false;    // 하나만 null 이면 false
    if(equal_data(*p1, *p2)) return (is_equal(p1->link, p2->link));
    else return false;
}
bool equal_data(node t1, node t2){
    if(t1.name != t2.name) return false;
    if(t1.score != t2.score) return false;
    return true;
}