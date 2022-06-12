#include <iostream>
using namespace std;
class element{
public:
    string name;
    int key;
};
int sequential_search(element a[], int k, int n);
int binary_search(element a[], int k, int left, int right);
int main(){
    element student[4] = {{"park", 90}, {"Song", 100}, {"Lee", 80}, {"Kim", 70}}; 
    int key;

    key = sequential_search(student, 80, 4);
    cout<<"Name: "<<student[key].name;
    cout<<"\nScore: "<<student[key].key<<endl;

    cout<<"-----------"<<endl;
    key = binary_search(student, 100, 0, 3);
    cout<<"Name: "<<student[key].name;
    cout<<"\nScore: "<<student[key].key<<endl;
    return 0;
}
int sequential_search(element a[], int k, int n){     // array, key, array_size
    int j = 0;
    while((j<n)&&(a[j].key!=k))      // array 사이즈보다 j가 작음, j번째 key가 찾는 key값과 다르면 
        j++;                         // index+1
    if(j>=n)                         // array 사이즈를 j가 넘으면 찾는 key 값 없음
        return -1;
    return j;                        // 찾았으면 index 값 return 
}
int binary_search(element a[], int k, int left, int right){
    int middle;
    while(left<=right){
        middle = (left+right)/2;     // array size의 중간 값

        if(a[middle].key==k)         // key 찾으면 index return 
            return middle;
        if(a[middle].key>k)          // 찾는 key 값이 작으면 array 반으로 자르기 (앞쪽)
            right = middle-1;
        if(a[middle].key<k)          // 찾는 key 값이 작으면 array 반으로 자르기 (뒷쪽)
            left = middle+1;
    }
    return -1;                       // 못 찾으면 -1 return 
}