#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;
int row,col;
int board[251][251];
bool visit[251][251];
vector<pair<int,int>> t;

int dr[4]={0,0,1,-1};
int dc[4]={1,-1,0,0};
int totalo=0, totalv=0;

void bfs(int r, int c){
    queue<pair<int,int>> q;
    q.push(make_pair(r,c));
    int cnto=0,cntv=0,cntTotal=0;
    visit[r][c]=true;
    while(!q.empty()){
        int tr=q.front().first;
        int tc=q.front().second;
        q.pop();
        
        if(board[tr][tc]==1)
            cnto+=1;
        if(board[tr][tc]==2)
            cntv+=1;

        // cout<<tr<<tc<<cnto<<cntv<<endl;

        cntTotal+=1;

        for(int i=0; i<4; i++){
        int nr=tr+dr[i];
        int nc=tc+dc[i];
            if(nr<row&&nc<col&&nr>=0&&nc>=0){
                if(board[nr][nc]!=-1&&!visit[nr][nc]){
                    q.push(make_pair(nr,nc));
                    visit[nr][nc]=true;
                }
            }
        }    
    }
    // for(int i=0; i<row; i++){
    //     for(int j=0; j<col; j++){
    //         cout<<visit[i][j];
    //     }
    //     cout<<endl;
    // }
    // cout<<cnto<<cntv<<endl;
    if(cnto>cntv){
        totalo+=cnto;
    }
    else{
        totalv+=cntv;
    }
    return;
}

int main(){
    cin>>row>>col;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            char a;
            cin>>a;
            if(a=='.')board[i][j]=0;
            if(a=='#')board[i][j]=-1;
            if(a=='o'){//양
                board[i][j]=1;
                t.push_back(make_pair(i,j));
            }
            if(a=='v'){//늑대
                board[i][j]=2;
                t.push_back(make_pair(i,j));
            }
        }
    }

    for(int i=0; i<t.size(); i++){
        if(!visit[t[i].first][t[i].second]){
            bfs(t[i].first,t[i].second);
        }
    }
    cout<<totalo<<" "<<totalv<<endl;
}
