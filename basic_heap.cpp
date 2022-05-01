#include <iostream>
using namespace std;
#define HSIZE 100

class element{
public:
    string name;
    double score;
    void set_data(string s, double d);
};
class my_heap{
    element h[HSIZE];
    int csize;           // The number of elements
public:
    my_heap();
    int h_size();          // heap size
    void insert_heap(element e);
    element delete_heap();
    bool heap_full();
    bool heap_empty();
};
int main(){
    my_heap h;

    element temp;

    temp.set_data("kim", 88);
    h.insert_heap(temp);
    temp.set_data("Lee", 77);
    h.insert_heap(temp);
    temp.set_data("Park", 98);
    h.insert_heap(temp);
    temp.set_data("Choi", 74);
    h.insert_heap(temp);
    temp.set_data("Ryu", 94);
    h.insert_heap(temp);
    temp.set_data("cho", 85);
    h.insert_heap(temp);

    while(h.h_size()>0){
        temp = h.delete_heap();
        cout<<temp.name<<" : "<<temp.score<<"\n";
    }

    return 0;
}


void element::set_data(string s, double d){
    name = s;
    score = d;
}
my_heap::my_heap(){
    csize = 0;
}
int my_heap::h_size(){
    return csize;
}
void my_heap::insert_heap(element e){
    int k;
    csize++;
    k = csize;

    while((k!=1)&&(e.score>h[k/2].score)){   // k!=1 -> root X
        h[k] = h[k/2];
        k/=2;
    }
    h[k] = e;
}
element my_heap::delete_heap(){
    element t;
    element temp;
    int parent, child;         // 위치정보 기억

    t = h[1];                  // for return value, 첫원소
    temp = h[csize];           // end of element, 끝원소
    csize--;
    parent = 1;                // root
    child = 2;                 // left child of root
    while(child<=csize){       // there is child
        if((child<csize)&&(h[child].score<h[child+1].score))  // right child 존재하고, right child가 크면
            child++;           // choose the right child
        if(temp.score>=h[child].score)      // 기존 원소의 score value와 선택한 child의 score value 비교해서 기존 value가 크면
            break;
        h[parent] = h[child];  // child 값 parent 자리로 끌어올림
        parent = child;
        child *= 2; 
    } 
    h[parent] = temp;

    return t;
}
bool my_heap::heap_full(){
    if(csize>=HSIZE-1) return true;   // Because we don't use index 0 of array
    else return false;
}
bool my_heap::heap_empty(){
    if(csize == 0) return true;
    else return false;
}