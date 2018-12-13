#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int n,m,h;//세로선 , 가로선, 가로 놓을수 있는 위치수
int arr[32][32];
int isodd[32];
vector<pair<int,int>> v;
int res=100;
bool checkdirect(){

    int cur=0;
    for(int i=1; i<=n; i++){
        cur=i;
        //cur(1줄의 내려가면서 가로줄 있나 체크)
        for(int j=1; j<=m; j++){
            if(arr[j][cur]==1){
                cur+=1;
            }
            else if(arr[j][cur-1]==1){
                cur-=1;
            }
        }
        if(cur!=i)
            return false;
    }
    return true;
}

void dfs(int i, int cnt){
    if(cnt>3||i==v.size())return;
    
    if((cnt+m)%2==0){
        if(checkdirect())
            res= res>cnt ? cnt : res;       
    }
    
    if(arr[v[i].first][v[i].second-1]!=1&&arr[v[i].first][v[i].second+1]!=1&&isodd[v[i].first]%2==1){
        arr[v[i].first][v[i].second]=1;
        isodd[v[i].first]+=1;
        dfs(i+1,cnt+1);
    }
    arr[v[i].first][v[i].second]=0;
    isodd[v[i].first]-=1;
    dfs(i+1,cnt);
}

int main(){
    cin>>n>>m>>h;
    for(int i=0; i<m; i++){
        //a,b b세로선을 다음선으로 옮김 a줄에서
        int a,b; //1,2일때 1가로선에서 2에서 3 잇는 줄그음
        cin>>a>>b;
        arr[a][b]=1;
    }
    
    //추가 가능한 가로선 리스트 만들기
    for(int i=1; i<=m; i++){
        for(int j=1; j<=m; j++){
            // cout<<arr[i][j];
            if(arr[i][j]==0&&arr[i][j-1]==0&&arr[i][j+1]==0){
                v.push_back(make_pair(i,j));
                isodd[i]+=1;
                // cout<<"<";
            }
        }
        // cout<<endl;
    }

    dfs(0,0);
    if(m==0){
        cout<<0;
        return 0;
    }
    if(m==1){
        cout<<1;
        return 0;
    }
    if(res>3||res<=0)cout<<-1;
    else
        cout<<res;
}