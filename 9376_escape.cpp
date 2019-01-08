#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> board;
vector<vector<int>> board2;
bool visit[101][101];
bool visit2[101][101];
pair<int,int> pin[2];
int addr[4]={0,0,1,-1};
int addc[4]={1,-1,0,0};
int t_min=100000;
bool is_first_dfs;
//dfs 
void dfs2(int r, int c, int total){
    // cout<<r<<c<<endl;
    // cout<<"t"<<total<<endl;
    visit2[r][c]=true;
    if(r==0||c==0||r==board2.size()-1||c==board2[0].size()-1){
        if(t_min>total){
            t_min=total;
        }
        return;
    }
    else{
        for(int i=0; i<4; i++){
            int tr=r+addr[i];
            int tc=c+addc[i];
            if(tr>=0&&tc>=0&&tr<board2.size()&&tc<board2[0].size()){
                if(board2[tr][tc]>=0&&!visit2[tr][tc]){
                    if(board2[tr][tc]==1){
                        int tn=board2[r][c];
                        board2[tr][tc]=0;
                        // cout<<"open"<<tr<<tc<<total+1<<endl;
                        dfs2(tr,tc,total+1);
                        board2[tr][tc]=1;
                    }
                    else
                        dfs2(tr,tc,total);
                }

            }
        }
    }
    visit2[r][c]=false;
    return;
}

void dfs(int r, int c, int total){
    // cout<<r<<c<<endl;
    visit[r][c]=true;
    if(r==0||c==0||r==board.size()-1||c==board[0].size()-1){
        // cout<<"!!!!!!!!!!!!"<<total<<endl;
        board2=board;
        for(int i=0; i<100; i++){
            for(int j=0; j<100; j++){
                visit2[i][j]=false;
            }
        }
        dfs2(pin[1].first,pin[1].second,total);
        return;
    }
    else{
        for(int i=0; i<4; i++){
            int tr=r+addr[i];
            int tc=c+addc[i];
            if(tr>=0&&tc>=0&&tr<board.size()&&tc<board[0].size()){
                if(board[tr][tc]>=0&&!visit[tr][tc]){
                    if(board[tr][tc]==1){
                        int tn=board[r][c];
                        board[tr][tc]=0;
                        // cout<<"open"<<tr<<tc<<total+1<<endl;
                        dfs(tr,tc,total+1);
                        board[tr][tc]=1;
                    }
                    else
                        dfs(tr,tc,total);
                }

            }
        }
    }
    visit[r][c]=false;
    return;
}

int main(){
    int n;
    int h,w;
    cin>>n;
    while(n--){
        vector<vector<int>> tboard;
        cin>>h>>w;
        bool is_first_pin=true;
        for(int i=0; i<h; i++){
            vector<int> a;
            for(int j=0; j<w; j++){
                char b;
                cin>>b;
                int c;
                if(b=='.')//빈칸
                    c=0;
                if(b=='*')//벽
                    c=-1;
                if(b=='#')//문
                    c=1;
                if(b=='$'){//핀
                    c=2;                
                    if(is_first_pin){
                        pin[0]=make_pair(i,j);
                        is_first_pin=false;
                    }
                    else{
                        pin[1]=make_pair(i,j);
                    }    
                }
                a.push_back(c);

            }
            tboard.push_back(a);
        }
        board.swap(tboard);
        t_min=100000;
        dfs(pin[0].first,pin[0].second,0);   
        cout<<t_min<<endl;     
    }
}