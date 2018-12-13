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

void lbfs(int a, int cnt, int from){
    if(!visit[a]){
        cout<<a<<endl;
        visit[a]=true;
        cnt+=1;
        if(loser_list[a].size()==0){
            ranked[from][1]= cnt>ranked[from][1] ? cnt : ranked[from][1];
            return;
        }
    }
    for(int i=0; i<loser_list[a].size(); i++){
        lbfs(loser_list[a][i],cnt, from);
    }
    return;
}

void wbfs(int a, int cnt, int from){
    if(!visit[a]){
        cout<<a<<endl;
        visit[a]=true;
        cnt+=1;
        if(winner_list[a].size()==0){
            ranked[from][0]= cnt>ranked[from][0] ? cnt : ranked[from][0];
            return;
        }
    }
    for(int i=0; i<winner_list[a].size(); i++){
        wbfs(winner_list[a][i],cnt, from);
    }
    return;
}

int solution(int n, vector<vector<int>> r) {
    int answer = 0;
    for(int i=0; i<r.size(); i++){
        loser_list[r[i][0]].push_back(r[i][1]);
        winner_list[r[i][1]].push_back(r[i][0]);
        link[r[i][1]][r[i][0]]=1;//1은 a에서 b로
        link[r[i][0]][r[i][1]]=2;//2은 b에서 a로
    }
    bool arr[101];
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n; j++)
            visit[j]=false;
        lbfs(i,-1,i);
        cout<<i<<"l"<<ranked[i][1]<<endl;    

        for(int j=0; j<=n; j++)
            visit[j]=false;
        wbfs(i,-1,i);
        cout<<i<<"w"<<ranked[i][0]<<endl;    
    }
    cout<<ranked[4][1]<<ranked[4][0]<<endl;
    return answer;
}

int main(){
    vector<vector<int>> r = {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}};
    solution(5,r);
}