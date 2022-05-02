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
    int csize;          
    void adjust(int t_root);
public:
    my_heap();
    my_heap(element a[], int n);
    int h_size();          
    void insert_heap(element e);
    element delete_heap();
    bool heap_full();
    bool heap_empty();
    double score_sum();
    double score_average();
    void node_delete_by_name(string name);
};
int main()
{
    element a[10] = { {"Kim",88}, {"Lee", 77}, {"Park", 98}, {"Choi", 74}, {"Ryu",94}, {"Cho", 85}  };
    my_heap h1(a, 6);
    element temp;

    cout << "Number of nodes : " << h1.h_size() << endl;
    cout << "Score Sum = " << h1.score_sum() << endl;
    cout << "Score average = " << h1.score_average() << endl;

    h1.node_delete_by_name("Kim");
 
    cout << "\n-- After the deletion operation. --\n\n";
    cout << "Number of nodes : " << h1.h_size() << endl;
    cout << "Score Sum = " << h1.score_sum() << endl;
    cout << "Score average = " << h1.score_average() << endl;

    while (h1.h_size() > 0) {
        temp = h1.delete_heap();
        cout << temp.name << " : " << temp.score << "\n";
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
my_heap::my_heap(element a[], int n){
    int k;

    for(k = 1; k<=n; k++)     // 주어진 배열원소를 heap 공간으로 저장 (0 -> 1)
        h[k] = a[k-1];
    csize = n;                // heap size를 n으로 설정

    for(k = n/2; k>=1; k--)   // from last internal node to root, 해당 node를 root로 하는 subtree에 대여 adjust() 수행
        adjust(k);

}

int my_heap::h_size(){
    return csize;
}

void my_heap::insert_heap(element e){
    int k;
    csize++;
    k = csize;
    while((k!=1) && (e.score>h[k/2].score)){
        h[k] = h[k/2];
        k/=2;
    }

}
element my_heap::delete_heap(){
    element t;
    element temp;
    int parent, child;

    t = h[1];
    temp = h[csize];
    csize--;

    parent = 1;
    child = 2;

    while(child<=csize){
        if((child<csize)&&(h[child].score)<h[child+1].score)
            child++;
        if(temp.score>=h[child].score)
            break;
        h[parent] = h[child];
        parent = child;
        child*=2;

    }
    h[parent] = temp;
    return t;
}

bool my_heap::heap_full(){
    if(csize>=HSIZE-1) return true;   
    else return false;
}
bool my_heap::heap_empty(){
    if(csize == 0) return true;
    else return false;
}

double my_heap::score_sum(){
    double sum = 0;

    for(int i = 0; i<csize+1; i++)
        sum+=h[i].score;

    return sum;
}
double my_heap::score_average(){
    double sum = score_sum();
    return sum/csize;
}

void my_heap::adjust(int t_root){
    double tmpkey;
    int child;
    element tmp;

    tmp = h[t_root];              // root의 원소 저장
    tmpkey = h[t_root].score;     
    child = 2*t_root;             // left를 child로 선택

    while(child<=csize){
        if((child<csize)&&(h[child].score<h[child+1].score))
            child++;
        if(tmpkey>h[child].score)
            break;
        else{
            h[child/2] = h[child];
            child *= 2;
        }
    }
    h[child/2] = tmp;
}

void my_heap::node_delete_by_name(string name){
    element t;
    element temp;
    int parent, child;

    for(int i = 0; i<csize; i++){
        if(name == h[i].name){ 
            t = h[i];
            parent = i;
            break;
        }   
    }
    temp = h[csize];
    csize--;

    while(child<=csize){
        if((child<csize)&&(h[child].score)<h[child+1].score)
            child++;
        if(temp.score>=h[child].score)
            break;
        h[parent] = h[child];
        parent = child;
        child*=2;

    }
    h[parent] = temp;

}