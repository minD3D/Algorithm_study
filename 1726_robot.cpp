#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int m,n;
bool board[101][101];
int visit[101][101][4];
int sta,stb,ena,enb,dst,den;
int arra[4]={-1,0,1,0};
int arrb[4]={0,1,0,-1};
int arrd[4]={0,1,2,3};//북동남서
queue<pair<int,int>> q;
queue<int> dq;
// queue<int> cnt;
int res,cnt=0;

int rightturn(int d){
    if(d==3)return 0;
    else return d+1;
}
int leftturn(int d){
    if(d==0)return 3;
    else return d-1;
}

void findway(){
    int s=q.size();
    while(s--){
        int a,b,c,d;
        a=q.front().first;
        b=q.front().second;
        // c=cnt.front();
        d=dq.front();
        if(cnt>visit[a][b][d])
            break;

        visit[a][b][d]= cnt;
        // cout<<a<<b<<d<<endl;
        if(ena==a&&enb==b&&den==d){
            res=cnt;
            return;
        }

        q.pop();
        dq.pop();

        if(visit[a][b][rightturn(d)] > cnt){
            visit[a][b][rightturn(d)]=1;
            q.push(make_pair(a,b));
            dq.push(rightturn(d));
        }
        if(visit[a][b][leftturn(d)] > cnt){
            visit[a][b][leftturn(d)]=1;
            q.push(make_pair(a,b));
            dq.push(leftturn(d));
        }
        for(int i=0; i<4; i++){
            if(d==arrd[i]){
                int ta=a,tb=b;
                for(int j=0; j<3; j++){
                    ta+=arra[i];
                    tb+=arrb[i];
                    if((tb < 0) || (tb > n) || (ta < 0) || (ta > m))
                        break;
                    if(board[ta][tb]==0){
                        visit[ta][tb][d]= cnt<visit[ta][tb][d] ? cnt : visit[ta][tb][d];
                        q.push(make_pair(ta,tb));
                        dq.push(d);     
                    }
                }
            }
        }
    }
    cnt+=1;
    // cout<<cnt<<endl;
    if(!q.empty())
        findway();    
    return;
}

int changedis(int a){
    if(a==2)return 3;
    if(a==3)return 2;
    if(a==4)return 0;
}

int main(){
    cin>>m>>n;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
            for(int k=0; k<4; k++){
                visit[i][j][k]=100000;
            }
        }
    }
    int a,b;
    cin>>sta>>stb>>a;
    cin>>ena>>enb>>b;
    sta--;
    stb--;
    ena--;
    enb--;
    dst = changedis(a);
    den = changedis(b);
    q.push(make_pair(sta,stb));
    dq.push(dst);
    
    findway();
    cout<<res<<endl;
}
