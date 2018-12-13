#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

class Pos{
    public:
        int r,c,dir,cnt=0;
    Pos(){};
    Pos(int rv, int cv, int dirv, int cntv) : r(rv), c(cv), dir(dirv), cnt(cntv){};  
};

int n,m;
int map[102][102];
int visit[101][101][4];
int arrr[5]={0,0,0,1,-1};
int arrc[5]={0,1,-1,0,0};
Pos st,en;
queue<Pos> q;

int opposite(int a){
    if(a==1)return 2;
    if(a==2)return 1;
    if(a==3)return 4;
    if(a==4)return 3;
}

int main(){
    cin>>m>>n;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin>>map[i][j];
        }
    }
    cin>>st.r>>st.c>>st.dir>>en.r>>en.c>>en.dir;
    q.push(st);
    visit[st.r][st.c][st.dir]=1;

    while(!q.empty()){
        int r=q.front().r,c=q.front().c,dir=q.front().dir,cnt=q.front().cnt;
        q.pop();
        // cout<<r<<c<<dir<<endl;
        if(r==en.r && c==en.c && dir==en.dir){
            cout<<cnt;
            return 0;
        }
        int tr,tc;
        for(int i=1; i<=3; i++){
            tr=r+arrr[dir]*i;
            tc=c+arrc[dir]*i;
            if(tr<1||tr>m||tc<1||tc>n||map[tr][tc])break;
            if(visit[tr][tc][dir])continue;
            visit[tr][tc][dir]=1;
            q.push(Pos(tr,tc,dir,cnt+1));
        }
        for(int i=1; i<=4; i++){
            if(i==dir || i==opposite(dir))continue;
            if(visit[r][c][i])continue;
            visit[r][c][i]=1;
            q.push(Pos(r,c,i,cnt+1));
        }
    }
    return 0;
}
