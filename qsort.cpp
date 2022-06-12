// Standard libarary qsort
/*
### Standard library
#include <stdlib.h>
#include <ctdlib>

qsort(list, n, size, comp);
- list위치부터 size 크기의 단위 원소 ‘n’개에 대하여, ‘comp’라는 비교함수 적용하여 quick_sort 수행
    - list   : array
    - n      : array 수
    - size  : 원소의 단위 크기
    - comp: 비교함수
    

int comp(void *a, void *b)
{
    (ascending sort를 위하여)
    ‘a가 가르키는 곳’이 ‘b가 가르키는 곳’ 보다 **작으면** 음수(-1),
    ‘a가 가르키는 곳’이 ‘b가 가르키는 곳’ 보다 **크면** 양수(1),
    ‘a가 가르키는 곳’과 ‘b가 가르키는 곳’과 **같으면** 0 return
}

- void *a → type이 없는 위치 정보일 뿐
- void *p → p가 가르키는 공간이 정수임
- p = (int*) a;
    - casting, 원하는 type으로 해석하기 위해서 void 사용
*/
#include <iostream>
#include <cstdlib>
using namespace std;
int compare(const void* a, const void* b);
int main(){
    int t_list[10] = {25, 32, 17, 24, 22, 41, 87, 33, 16, 44};

    qsort(t_list, 10, sizeof(int), compare);
    for(int k = 0; k<10; k++){
        cout<< t_list[k]<<endl;
    }

    return 0;
}
int compare(const void* a, const void* b){
    int* p1 = (int*) a;
    int* p2 = (int*) b;

    if(*p1 == *p2) return 0;
    if(*p1<*p2) return -1;
    if(*p1>*p2) return 1;

    return 0;
}