#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n,m;
int board[51][51];
int visit[51][51];
int arrr[4]={0,1,0,-1};
int arrc[4]={1,0,-1,0};
queue<pair<int,int>> q;
int maxv=0;
bool isroop=false;

void move(int r, int c, int cnt){//첫 3,2에 대해
    if(isroop)return;
    maxv= cnt>maxv ? cnt : maxv;
    // cout<<r<<c<<"->"<<board[r][c]<<"cnt"<<cnt<<endl;
    if(visit[r][c]==1){
        isroop=true;
        return;
    }
    int mv=board[r][c];
    for(int i=0; i<4; i++){
        int tr= r+ mv*arrr[i];
        int tc= c+ mv*arrc[i];
        if(tr<n&&tc<m&&tr>=0&&tc>=0){
            if(board[tr][tc]!=0){
                visit[r][c]=1;
                move(tr,tc,cnt+1);
                visit[r][c]=0;
            }
        }
    }
    return;
}

int main(){
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char a;
            cin>>a;
            if(a=='H')
                board[i][j]=0;
            else
                board[i][j]=a-'0';
        }
    }

    move(0,0,1);    
    if(isroop)cout<<-1<<endl;
    else cout<<maxv<<endl;
}