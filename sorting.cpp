// Sorting , g++ -std=c++11 sorting.cpp 
#include <iostream>
using namespace std;
#define S_SIZE 100
class s_record {
public:
    string s_id;
    string name;
    double score;
    s_record();
    s_record(string a, string b, double n);
};
void show_thelist(s_record a[], int n);
void insertion_sort(s_record a[], int n);                                  // Insertion sort
void bubble_sort (s_record a[], int n);                                    // Bubble sort
void selection_sort(s_record a[], int n);                                  // Selection sort
void quick_sort(s_record a[], int left, int right);                        // Quick sort
void adjust(s_record a[], int troot, int size);
void heap_sort(s_record a[], int n);                                       // Heap sort
void merge(s_record a[], s_record b[], int n1, int n2, int n3, int n4);    // Merge sort
void merge_pass(s_record a[], s_record b[], int n, int s);
void merge_sort(s_record a[], int n);
 
int main() {
    s_record s_list[12] = {{"21900013", "Kim ", 6.5}, {"21900136", "Lee ", 8.8}, 
                           {"21900333", "Park", 9.2}, {"21800442", "Choi", 7.1}, 
                           {"21900375", "Ryu ", 5.4}, {"21700248", "Cho ", 6.3},
                           {"21700302", "Jung", 8.3}, {"21800255", "Han ", 6.9}, 
                           {"21800369", "Kang", 6.3}, {"21900401", "Yang", 9.1}, 
                           {"21800123", "Moon", 8.1}, {"21700678", "Seo ", 7.9}};
    int n = 12;
    // insertion_sort(s_list, n);
    // bubble_sort(s_list, n);
    // selection_sort(s_list, n);
    // quick_sort(s_list, 0, n-1);
    // merge_sort(s_list, n);
    heap_sort(s_list, n);
    
    cout << "< The result of the sorting >" << endl;
    show_thelist(s_list, n);
    return 0;
}
s_record::s_record(string a, string b, double n) {
    s_id = a;
    name = b;
    score = n;
}
s_record::s_record() {
    s_id = "00000000";
    name = "None";
    score = 0;
}
void insertion_sort(s_record a[], int n) {
    for(int i = 1; i < n; i++) {
        s_record tmp = a[i];
        int k = i-1;            // tmp 앞 원소
        while ((k >= 0) && (a[k].s_id > tmp.s_id)) {
            a[k+1] = a[k];
            k--;
        }
        a[k+1] = tmp;
    }
}
void bubble_sort (s_record a[], int n) {
    s_record tmp;
    for (int j = n-1; j >= 1; j--)             // array 범위를 하나씩 줄여줌
        for (int k = 0; k<j ; k++)             // 위에서 정의된 array 범위만큼 for문
            if (a[k].s_id > a[k+1].s_id) {
                tmp = a[k];
                a[k] = a[k + 1];
                a[k + 1] = tmp;
            }
}
void selection_sort(s_record a[], int n) {
    s_record tmp;
    for (int j = 0; j < n; j++) {
        int min_i = j;
        for (int k = j + 1; k < n; k++)
            if (a[k].s_id < a[min_i].s_id)
                min_i = k;
        tmp = a[j];
        a[j] = a[min_i];
        a[min_i] = tmp;
    }
}
void quick_sort(s_record a[], int left, int right) {
    s_record pivot;                    // pivot은 array의 첫 번째 원소, pivot은 array key 값중 중간 값
    int i, j;                          // left, right
    if (left >= right)                 // 교차되면 종료
        return;
    i = left;                    
    j = right + 1;
    pivot = a[left];              
    do {
        do {
            i++;
        } while ((i <= right) && (a[i].s_id < pivot.s_id));   // pivot 원소보다 작으면 앞으로 전진
        do {
            j--;
        } while (a[j].s_id > pivot.s_id);                     // pivot 원소보다 크면 앞으로 전진
        if(i < j)                // 교차되면 swap 시키면 안됨.
            swap(a[i], a[j]);
    } while(i<j);
    swap(a[left], a[j]);
    quick_sort(a, left, j-1);         // Pivot 원소를 기준으로 앞쪽 quict sort 수행 
    quick_sort(a, j+1, right);        // Pivot 원소를 기준으로 뒷쪽 quict sort 수행 
}
void heap_sort(s_record a[], int n) {
    int i;
    s_record b[S_SIZE], tmp;
    for (i = 0; i < n; i++)           // array 1번째부터 원소값 지정
        b[i + 1] =  a[i];

    for (i = n / 2; i > 0; i--)       // 초기 heap 구성
        adjust(b, i, n);

    for (i = n - 1; i > 0; i--) {     
        tmp = b[1];                  // 마지막 값이랑 첫 번재 값 교환
        b[1] = b[i + 1];
        b[i + 1] = tmp;
        adjust(b, 1, i);              // n-1번째까지 adjust
    }
    for(i = 0; i < n; i++) {          // array a로 copy
        a[i] = b[i+1];
    }
}
void adjust(s_record a[], int troot, int size) {
    string tmpkey;
    int child;
    s_record tmp;
    tmp = a[troot];
    tmpkey = a[troot].s_id;
    child = 2*troot;
    while(child <= size) {
        if((child < size) && (a[child].s_id < a[child+1].s_id))
            child++;
        if(tmpkey >= a[child].s_id)
            break;
        else {
            a[child/2] = a[child];
            child *= 2;
        }
    }
    a[child/2] = tmp;
}
void merge(s_record a[], s_record b[], int n1, int n2, int n3, int n4) {    // 이미 sort 된 array를 merge
    int i, j, k, t;                                                         // a[] -> b[]
    i = n1;                                // 첫 번째 array의 첫 번째 index
    j = n3;                                // 두 번째 array의 첫 번째 index
    k = n1;                                // 빈 array의 첫 번재 index
    while ((i <= n2) && (j <= n4)) {       // 두 array 중 한 array가 한 쪽 끝에 닫지 않으면 while
        if (a[i].s_id <= a[j].s_id)
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    if (i > n2)                            // 두 번째 sort안 된 array copy
        for (t = j; t <= n4; t++)
            b[t] = a[t];
    else                                   // 첫 번째 sort안 된 array copy
        for (t = i; t <= n2; t++)
            b[k-i+t] = a[t];
}

void merge_pass(s_record a[], s_record b[], int n, int s) {
    int i, j;
    for (i = 0; i < (n-2*s+1); i+=2*s )        // 전체사이즈-범위(2s)+1
        merge(a, b, i, i+s-1, i+s, i+2*s-1);
    if (i+s <= n)                             // 짜투리가 범위보다 클 때 
        merge(a, b, i, i+s-1, i+s, n);
    else                                      // 짜투리가 범위보다 작을 때
        for (j=i; j<= n; j++)
            b[j] = a[j];                      // copy
}

void merge_sort(s_record a[], int n) {
    int s = 1;                                // array 범위
    s_record b[S_SIZE];                       // 빈 array 생성
    
    while(s < n) {                           // 전체 구간보다 작으면
        merge_pass(a, b, n-1, s);    
        s*=2;                                // 범위 증가 (*=2)
        merge_pass(b, a, n-1, s);
        s*=2;                                // 범위 증가 (*=2)
    }
}

void show_thelist(s_record a[], int n) {
    for(int i = 0; i<n; i++) {
        cout << a[i].s_id << " : ";
        cout << a[i].name << " : ";
        cout << a[i].score << endl;
    }
}

