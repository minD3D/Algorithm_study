#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int>loser_list[101]; //loser[1]=>234;
vector<int>winner_list[101];
int link[101][101];
int ranked[100][2];//winner num , loser num
queue<int> q;
bool visit[101];
using namespace std;
int cnt=0;
void lbfs(int a, int from){
    if(!visit[a]){
        visit[a]=true;
        if(from!=a)
            ranked[from][1]+=1;
        if(loser_list[a].size()==0){
            return;
        }
    }
    else 
        return;
    for(int i=0; i<loser_list[a].size(); i++){
        lbfs(loser_list[a][i], from);
    }
    return;
}

void wbfs(int a, int from){
    if(!visit[a]){
        visit[a]=true;
        if(from!=a)
            ranked[from][0] +=1;
        if(winner_list[a].size()==0){
            return;
        }
    }
    else 
        return;
    for(int i=0; i<winner_list[a].size(); i++){
        wbfs(winner_list[a][i], from);
    }
    return;
}

int solution(int n, vector<vector<int>> r) {
    int answer = 0;
    for(int i=0; i<r.size(); i++){
        //그래프 리스트구현
        loser_list[r[i][0]].push_back(r[i][1]);
        winner_list[r[i][1]].push_back(r[i][0]);
        //그래프 행렬구현
        link[r[i][1]][r[i][0]]=1;//1은 a에서 b로
        link[r[i][0]][r[i][1]]=2;//2은 b에서 a로
    }
    bool arr[101];
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n; j++)
            visit[j]=false;
        lbfs(i,i);

        for(int j=0; j<=n; j++)
            visit[j]=false;
        wbfs(i,i);
        if(ranked[i][0]+ranked[i][1]==n-1)
            answer++;    
    }
    return answer;
}

int main(){
    vector<vector<int>> r = {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}};
    cout<<solution(5,r);
}