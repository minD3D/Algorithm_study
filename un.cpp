#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int V_size;
vector< vector<int> > adjacent; //인접 행렬의 표현
vector<bool> visited(V_size, false);
stack<int> mem;
 
void dfs(int start) {
    int current = start;
    mem.push(current); 
    visited[current]=true;
    cout << "VISIT : " << start << '\n';
    while(mem.size()){
        current = mem.top();
        for(int i = 0; i < V_size; i++){
            if(adajacent[current][i]!=0 && !visited[i]){
                current = i;
                mem.push(current);
                visited[current]=true;
                cout << "VISIT : " << current << '\n';
                break;
            }else if(i == V_size-1){
                //연결된 정점이 없거나 정점 중 방문할 정점이 없는 경우
                mem.pop();
            }
        }
    }
}
 
int main(void)
{    visited = vector<bool>(adjacent.size(),false);
    for(int i = 0; i < adjacent.size(); i++){
        if(!visited[i])
            dfs(i);
    }
}
