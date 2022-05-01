/* linked list 
강의에서 설명한 구조의 linked list를 구현하고, 아래의 main function의 의도대로 동작하도록 관련 function을 작성하시오. 
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
};
my_list::my_list(){
    head = NULL;
    tail = NULL;
}
int main( ){
    my_list a;
    node tmp;

    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);

    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp);                                         // head 위치로 2개의 원소 추가
    cout << a.num_nodes() << " : " << a.score_sum() << "\n";    // 1단계 점검

    tmp.set_data("Park", 91.3);   
    a.add_to_tail(tmp);                                         // tail 위치로 1개의 원소 추가
    cout << a.num_nodes() << " : " << a.score_sum() << "\n";    //2단계 점검

    tmp = a.delete_from_head();
    cout  << tmp.name << " is deleted.\n";                      // 3단계 점검

    tmp.set_data("Choi", 85.1);   
    a.add_to_tail(tmp);        

    tmp.set_data("Ryu", 94.3);   
    a.add_to_head(tmp);                                         // 2개의 원소 추가

    cout << a.num_nodes()<< " : "  << a.score_sum() << "\n";
    cout << "Park's score : " << a.get_score("Park")<< "\n";    // 4단계 점검

    if ( a.remove_a_node("Kim") == 1)
        cout << "Kim is deleted from the list. \n";             // 5단계 점검
    cout << a.num_nodes()<< " : " << a.score_sum() << "\n";     // 최종 점검    

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

    p->link = NULL;                       // new node *link, NULL로 초기화
    if(tail!=NULL) tail->link  = p;       // pre node의 link, new node에 연결
    else head = p;                        // list가 empty 상태였으면 head, new node에 연결

    tail = p;                             // tail에 new node 값 넣기
}
node my_list::delete_from_head(){
    node temp;                            // 값 return을 위한 node
    node *t;                              // delete하기 위한 node, head가 옮겨지면 그 node는 어딘가에서 돌아댕김 

    t = head;                             // delete 될 memory 저장
    temp = *head;                         // return 될 값 delete 전 저장
    head = head -> link;                  // head에서 delete 될 다음 Node와 연결

    delete t;                             // memory 삭제 
    if(head == NULL) tail = NULL;         
 
    return temp;
}
int my_list::num_nodes(){
    node *t;
    int cnt = 0;

    for(t = head;t!=NULL; t = t->link) 
        cnt++;

    return cnt;
}
double my_list::score_sum(){
    node *t;
    double sum = 0;

    for(t = head; t!=NULL; t=t->link) 
        sum += t->score;
    
    return sum;
}
double my_list::get_score(string t_name){
    node *t;

    for(t = head; t!=NULL; t = t->link){
        if(t->name == t_name) {
            return t->score;
        }
    }

    return 0;
}
int my_list::remove_a_node(string t_name){ 
    node *pre_temp;                           
    node *t;

    for(t = head; t!=NULL; t = t->link){
        if (t->name == t_name) {
            pre_temp->link = t->link;       // 이전 node와 다음에 올  node 연결
            delete t;                       // delete 현재 node memory 
            return 0;
        }
        pre_temp = t;                       // 이전 node 저장
    }
    return 0;

}
bool my_list::list_empty(){
    if(head==NULL) return true;
    else return false;
}
