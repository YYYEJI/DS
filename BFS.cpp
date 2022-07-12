/* Breadth First Search */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n = 7;
int  visit[7];
vector<int> a[8];

void bfs(int start){
    queue<int> q;
    q.push(start);
    visit[start] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout<<x<<" ";

        for(int i = 0; i<a[x].size(); i++){
            int y = a[x][i];
            if(!visit[y]){
                q.push(y);
                visit[y] = true;
            }
        }
    }
}
int main(){
    a[1].push_back(2);
    a[2].push_back(1);

    a[1].push_back(3);
    a[3].push_back(1);

    a[2].push_back(3);
    a[3].push_back(2);

    a[2].push_back(4);
    a[4].push_back(2);

    a[2].push_back(5);
    a[5].push_back(2);

    a[3].push_back(6);
    a[6].push_back(3);

    a[3].push_back(7);
    a[7].push_back(3);

    a[4].push_back(5);
    a[5].push_back(4);

    a[6].push_back(7);
    a[7].push_back(6);

    bfs(1);      // start vertex    // 1 2 3 4 5 6 7
}