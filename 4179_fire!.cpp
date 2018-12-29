#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;
int row,col;
vector<vector<int>> board;
queue<pair<int,int>> t;

int dr[4]={0,0,1,-1};
int dc[4]={1,-1,0,0};
int cnt=1;

int bfs(int r, int c){
    queue<pair<int,int>> q;
    q.push(make_pair(r,c));
    while(1){
        int sf=t.size();
        while(sf--){
            int tr=t.front().first;
            int tc=t.front().second;
            t.pop();
            // cout<<tr<<tc<<cnto<<cntv<<endl;
            for(int i=0; i<4; i++){
            int nr=tr+dr[i];
            int nc=tc+dc[i];
                if(nr<row&&nc<col&&nr>=0&&nc>=0){
                    if(board[nr][nc]!=-1&&board[nr][nc]!=2){
                        t.push(make_pair(nr,nc));
                        board[nr][nc]=2;
                    }
                }
            }    
        }
        int s=q.size();
        if(s==0)break;
        while(s--){
            int tr=q.front().first;
            int tc=q.front().second;
            if(tr==row-1||tc==col-1||tr==0||tc==0)
                return cnt;
            q.pop();
            // cout<<tr<<tc<<cnto<<cntv<<endl;
            for(int i=0; i<4; i++){
            int nr=tr+dr[i];
            int nc=tc+dc[i];
                if(nr<row&&nc<col&&nr>=0&&nc>=0){
                    if(board[nr][nc]!=-1&&board[nr][nc]!=2){
                        q.push(make_pair(nr,nc));
                        board[nr][nc]=1;
                        
                    }
                }
            }    
        }
        cnt+=1;

        // for(int i=0; i<row; i++){
        //     for(int j=0; j<col; j++){
        //         cout<<board[i][j];
        //     }
        //     cout<<endl;
        // }
        // cout<<cnt<<endl;
    
    }    
    
    return -1;
}

int main(){
    int n;
    cin>>n;
    while(n--){
        cin>>row>>col;
        int jc,jr;
        for(int i=0; i<row; i++){
            vector<int> b;
            for(int j=0; j<col; j++){
                char a;
                cin>>a;
                if(a=='.')b.push_back(0);
                if(a=='#')b.push_back(-1);
                if(a=='@'){//양
                    b.push_back(1);
                    jr=i;
                    jc=j;
                }
                if(a=='*'){//늑대
                    b.push_back(2);
                    t.push(make_pair(i,j));
                }
            }
            board.push_back(b);
        }
        int res=bfs(jr,jc);
        if(res<0)
            cout<<"IMPOSSIBLE"<<endl;
        else
            cout<<res<<endl;
    }
    
}
