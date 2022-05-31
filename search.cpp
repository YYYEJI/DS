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
int sequential_search(element a[], int k, int n){
    int j = 0;
    while((j<n)&&(a[j].key!=k))
        j++;
    if(j>=n)
        return -1;
    return j;
}
int binary_search(element a[], int k, int left, int right){
    int middle;
    while(left<=right){
        middle = (left+right)/2;

        if(a[middle].key==k)
            return middle;
        if(a[middle].key>k)
            right = middle-1;
        if(a[middle].key<k)
            left = middle+1;
    }
    return -1;
}