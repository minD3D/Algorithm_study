#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n,m;
int board[51][51];
int arrr[4]={0,1,0,-1};
int arrc[4]={1,0,-1,0};
queue<pair<int,int>> q;
int maxv=0;
void move(int r, int c, int cnt){//첫 3,2에 대해
    if(r>n||c>m||r<0||c<0||board[r][c]==0){
        maxv = (maxv<cnt-1) ? cnt:maxv;
        return;
    }
    // cout<<r<<c<<cnt<<endl;
    for(int i=0; i<4; i++){
        int mv=board[r][c];        
        int tr=r+mv*arrr[i];
        int tc=c+mv*arrc[i];
        move(tr,tc,cnt+1);
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

    move(0,0,0);    
    cout<<maxv<<endl;
}