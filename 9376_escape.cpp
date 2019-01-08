#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> board;
vector<vector<int>> board_s;
pair<int,int> pin[2];
int addr[4]={0,0,1,-1};
int addc[4]={1,-1,0,0};
int t_min=100000;
bool is_first_open_door_func;
//open_door_func 
void open_door_func(int fr, int fc, int sr, int sc, int total){
    // int fsb=board[fr][fc];
    // int ssb=board[sr][sc];
    // board[fr][fc]=-1;
    // board[sr][sc]=-1;
    if(fr==0||fc==0||fr==board.size()-1||fc==board[0].size()-1){

        if(sr==0||sc==0||sr==board.size()-1||sc==board[0].size()-1){
            cout<<total<<"!!!!"<<endl;
            return;
        }
    }
    for(int i=0; i<4; i++){
        int tfr=fr+addr[i];
        int tfc=fc+addc[i];
        if(tfr>=0&&tfc>=0&&tfr<board.size()&&tfc<board[0].size()){
            for(int j=0; j<4; j++){
                int tsr=sr+addr[j];
                int tsc=sc+addc[j];
                
                if(tsr>=0&&tsc>=0&&tsr<board.size()&&tsc<board[0].size()){
                    if(board[tfr][tfc]>=0&&board[tsr][tsc]>=0){
                        cout<<tfr<<tfc;
                        cout<<tsr<<tsc<<endl;
                    
                        if(board[tfr][tfc]==1){
                            if(board[tsr][tsc]==1){
                                board[tfr][tfc]=0;
                                board[tsr][tsc]=0;
                                open_door_func(tfr,tfc,tsr,tsc,total+2);
                                board[tfr][tfc]=1;
                                board[tsr][tsc]=1;                           
                            }
                            else{
                                board[tfr][tfc]=0;
                                open_door_func(tfr,tfc,tsr,tsc,total+1);
                                board[tfr][tfc]=1;   
                            }
                            // board[tfr][tfc]=0;
                            // open_door_func(tr,tc,total+1);
                            // board[tr][tc]=1;
                            // open_door_func(tr,tc,total);
                        }
                        else{
                            if(board[tsr][tsc]==1){
                                board[tsr][tsc]=0;
                                open_door_func(tfr,tfc,tsr,tsc,total+1);
                                board[tsr][tsc]=1;   
                            }
                            else{
                                open_door_func(tfr,tfc,tsr,tsc,total);
                            }
                        }
                    }
                }
            }            
        }
    }
    // board[fr][fc]=fsb;
    // board[sr][sc]=ssb;

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
        open_door_func(pin[0].first,pin[0].second,pin[1].first,pin[1].second,0);

    }
}