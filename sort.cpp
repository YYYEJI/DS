// selection sort 예제 구현
#include <iostream>
using namespace std;
void my_sort(int list[], int n);

int main(){
    int  list[10] = { 23, 11, 15, 8, 17, 33, 7, 14, 19, 21 };
    int  i ;

    my_sort(list, 10);   //  배열 list의 원소 10개를 sort하는 함수

    for (i = 0; i< 10; i++)
        // cout << list[i] << endl;    // endl은 줄바꿈
        // cout << list[i] << "\n";    // \n은 줄바꿈
        cout << list[i] << " "; 
    return 0;
    return 0;
}
void my_sort(int list[], int n){
    int temp;
    int min;

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(list[i]>=list[j]){
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}