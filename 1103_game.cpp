#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n,m;
int board[51][51];
int dp[51][51];
bool visit[51][51];

int arrr[4]={0,1,0,-1};
int arrc[4]={1,0,-1,0};

int move(int r, int c){//첫 3,2에 대해
    if(r>=n||c>=m||r<0||c<0||board[r][c]==0)
        return 0;
    if(visit[r][c]==true){
        cout<<-1<<endl;
        exit(0);
    }    
    int &res=dp[r][c];
    if(res != -1)return res;

    int mv=board[r][c];
    // int add=0;
    for(int i=0; i<4; i++){
        int tr= r+ mv*arrr[i];
        int tc= c+ mv*arrc[i];
        visit[r][c]=1;
        res= max(res,move(tr,tc));
        visit[r][c]=0;
    }

    return res;
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

            dp[i][j]=-1;
        }
    }

    cout<<move(0,0)<<endl;    
}