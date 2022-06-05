// C(C++)언어의 standard library를 이용한 sorting
/*
#include <stdlib.h>
#include <cstdlib>

qsort(list, n, size, comp);
  -> list: name of array
  -> n: number of element
  -> size: size of element type
  -> comp: function of comparision

int comp(void *a, void *b)
{   (ascending sort를 위해서)
    'a가 가리키는 곳'이 'b가 가르키는 곳'보다 작으면 음수(-1);     // (*a) < (*b)
    'a가 가리키는 곳'이 'b가 가르키는 곳'보다 크면 양수(1);       // (*a) > (*b)
    'a가 가리키는 곳'이 'b가 가르키는 곳'과 같으면 0을 return;    // (*a) == (*b) 
    (비교 대상은 응용에 따라 지정)
}
  -> 원하는 type으로 해석하기 위해서 void 사용
  -> void *a: type이 없는 위치 정보일 뿐
  -> void *p: p가 가르키는 공간이 정수임
  -> p = (int*) a;     // Casting: type 변환
*/
#include <iostream>
#include <cstdlib>
using namespace std;
int compare(const void* a, const void* b);

int main(){
    int t_list[10] = {25, 32, 17, 24, 22, 41, 87, 33, 16, 44};

    qsort(t_list, 10, sizeof(int), compare);
    for(int k = 0; k<10; k++)
        cout<<t_list[k]<<endl;

    return 0;
}
int compare(const void* a, const void* b){
    int *p1 = (int*) a;
    int *p2 = (int*) b;

    if(*p1 == *p2) 
        return 0;
    if(*p1 < *p2)
        return -1;
    if(*p1 > *p2)
        return 1;

    return 0;
}