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
    int node_delete_by_name(string name);
};
double summation(element e[], int troot, int n);
int delete_node(element e[], int troot, string tname, int n);
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
    return summation(h,1,csize);
}
double summation(element e[], int troot, int n){
    if(troot>n)
        return 0;
    return (e[troot].score+summation(e, 2*troot, n)+summation(e, 2*troot +1, n)); // root + left subtree + right subtree
}
double my_heap::score_average(){
    return score_sum()/csize;
}

void my_heap::adjust(int t_root){
    element tmp;
    double tmpkey;
    int child;

    tmp = h[t_root];              // root의 원소 저장
    tmpkey = h[t_root].score;     
    child = t_root*2;             // left를 child로 선택

    while(child<=csize){
        if((child<csize)&&(h[child].score<h[child+1].score))
            child++;
        if(tmpkey>=h[child].score)
            break;
        h[child/2] = h[child];
        child *= 2;
    }
    h[child/2] = tmp;
}

int my_heap::node_delete_by_name(string tname){
    if(csize == 0)
        return 0;
    
    if(delete_node(h, 1, tname, csize)==1){
        csize--;
        return 1;
    }
    else
        return 0;
}


int delete_node(element e[], int troot, string tname, int n){
    element t;            // parent node
    element tmp;          // last node
    int parent, child;
    int csize = n;

    for(int i = 0; i<csize; i++){
        if(e[i].name == tname){ 
            t = e[i];
            parent = i;   // i번째 node 부터 조정
            break;        // 찾으면 for문 종료
        }   
    }
    child = parent*2;
    tmp = e[csize];
    csize--;

    while(child<=csize){
        if((child<csize)&&(e[child].score)<e[child+1].score)
            child++;
        if(tmp.score>=e[child].score)
            break;
        e[parent] = e[child];
        parent = child;
        child*=2;

    }
    e[parent] = tmp;

    return 1;
}