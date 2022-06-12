// Queue class
/*
- empty queue 생성 
  * queue <int>         q1       
  * queue <double>      q2
  * queue <s_record>    q3
  
- queue class의 member functions
  * push(): 원소를 넣는 함수, void type
  * front(): 현재 front 원소를 읽는 함수
  * back() : 현재 back(rear)원소를 읽는 함수
  * size(): 현재 원소 개수를 return 
*/
#include <iostream>
#include <queue>
using namespace std;
class s_record{
public:
    string s_id;
    string name;
    double score;
    s_record();
    void set_data(string s1, string s2, double n);
};
int main(){
    queue <s_record> q1;

    s_record tmp;
    tmp.set_data("21900013", "Kim ", 6.5);
    q1.push(tmp);
    tmp.set_data("21900333", "Park", 9.2);
    q1.push(tmp);
    tmp.set_data("21900136", "Lee", 8.8);
    q1.push(tmp);
    tmp.set_data("21800442", "Choi", 7.1);
    q1.push(tmp);

    q1.pop();
    tmp = q1.front();
    cout << tmp.name << endl;    // Park 출력
    tmp = q1.back(); 
    cout << tmp.name << endl;    // Choi 출력
}
s_record::s_record(){
    s_id = "00000000";
    name = "None";
    score = 0;
}
void s_record::set_data(string s1, string s2, double n){
    s_id = s1;
    name = s2;
    score = n;
}