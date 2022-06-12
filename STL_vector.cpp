// Vector class
/*
- 임의 type의 원소를 저장할 수 있는 dynamic array
    -> 원소 개수 제약이 없음 -> 수시로 자동 relocation
    -> 원소의 type 제약이 없음
    -> indexing 기능
    -> 끝위치에 Insert delete가 효율절
    -> 중간 insert/delete가 비효율적
    -> 원소 개수가 증가하면 relocation 발생 > iterator 사용에 유의

- empty vector 생성 
#include <vector>
  * vector <int>         a;
  * vector <double>      b;
  * vector <s_record>    c;
  
  vector<int> a(5);      // 원소 5개를 갖는 vector a
  vector<int> a(5,0);    // 원소 5개를 0으로 초기화
  vector<int> a(b);      // vector b와 동일 내용을 갖는 a 생성

  * push_back(): 끝 위치에 원소 추가
  * pop_back(): 끝 위치 원소 삭제
  * back(): 끝 위치 원소 읽기
  * front(): 첫 위치 원소 읽기
  * begin(): 첫 원소의 위치(iterator)
  * end(): 끝위치(끝원소의 다음위치)
  * clear(): 모든 원소 삭제 -> empty vector
  * empty(): empty check
  * size(): 현재 원소 수
  * insert(): 원소 추가 -> 다양한 형태의 overloading
  * erase(): 원소 삭제
  
  * subscriptiong operator 사용 가능:[]   //indexing
  * index 변수는 unsigned int type
  
  * Iterator: vector, list 등 container class의 원소를 가리키는 일종의 pointer

  - vector class의 member functions
  * a.insert(p, t);        // p의 앞쪽에 t추가
  * a.insert(p, n, t);     // p의 앞쪽에 n개의 t추가
  * a.insert(p, p1, p2);   // p의 앞쪽에 [p1, p2]범위의 원소 추가
  * a.erase(p);            // p의 위치의 원소 삭제
  * a.erase(p1, p2);       // p1부터 p2까지(p2의 이전까지 )원소 삭제
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> a;
    vector <int>:: iterator p;     // iterator 선언
    a.push_back(2);
    a.push_back(4);
    a.push_back(6);
    cout<<a.size()<<endl;   // 3
    cout<<a[1]<<endl;       // 4

    a.pop_back();
    a.push_back(8);
    cout<<a.front()<<endl;  // 2
    cout<<a.back()<<endl;   // 8

    cout<<"\n--print element using for loop--"<<endl;
    unsigned int k;
    for(k = 0;k<a.size(); k++)
        cout<<a[k]<<endl;

    cout<<"\n--print element using iterator--"<<endl;
    for (p=a.begin();p<a.end();p++)
        cout<<*p<<endl;
}