/* circular queue
Array를 사용한 Circular queue의 구현 예제:
- 도서정보 = {도서명, 페이지수, 가격} 로 이루어진 원소를 저장하는 circular queue를 구현하고,
다음 main function 이 수행되도록 프로그램을 완성하시오.
*/
#include <iostream>
using namespace std;
#define Q_SIZE 100

class element{
public:
    string s_title;
    int npages;
    int price;
    void set_data(string s1, int n1, int n2);
};
class my_queue{
    element q[Q_SIZE];
    int front, rear;
public:
    my_queue();
    void insert_q(element e);
    element delete_q();
    bool queue_full();
    bool queue_empty();
};
int main(){
    my_queue  a;
    element  tmp;

    tmp.set_data("C++ Programming", 534, 35000);
    a.insert_q(tmp);
    tmp.set_data("Data Structure", 621, 42000);
    a.insert_q(tmp);
    tmp.set_data("JAVA Programming", 485, 38000);
    a.insert_q(tmp);
    tmp.set_data("Logic Design", 532, 44000);
    a.insert_q(tmp);

    while (!a.queue_empty() ) {
        tmp = a.delete_q();
        cout << tmp.s_title << " : " << tmp.npages  << " : " << tmp.price << "\n";
    }

    return 0;

}
void element::set_data(string s1, int n1, int n2){
    s_title = s1;
    npages = n1;
    price = n2;
}
my_queue::my_queue(){
    front = 0;
    rear = 0;
}
void my_queue::insert_q(element e){
    if(!queue_full()){
       q[rear] = e;    
     rear = (rear+1)%Q_SIZE;
    }
}
element my_queue::delete_q(){
    element temp;
    if(!queue_empty()){
        temp = q[front];
        front  = (front+1)%Q_SIZE;
    }
    return temp;
}
bool my_queue::queue_full(){
    if((rear+1)%Q_SIZE == front) return true;
    else return false;
}
bool my_queue::queue_empty(){
    if(front == rear) return true;
    else return false;
}