#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n;
int board[7][7];
int arrr[8]={0,1,0,-1,1,1,-1,-1};
int arrc[8]={1,0,-1,0,1,-1,1,-1};

void check(int r,int c, int color){//첫 3,2에 대해
    int rw=color,lw=color,uw=color,dw=color,ruw=color,rdw=color,luw=color,ldw=color;
    for(int i=0; i<8; i++){
        int tr=r,tc=c;        
        queue<pair<int,int>> q;
        bool change=false;
        while(1){
            tr=tr+arrr[i];
            tc=tc+arrc[i];
            // cout<<tr<<tc<<i<<endl;
            if(tr>6||tc>6||tr<0||tc<0||board[tr][tc]==0){
                change=false;
                break;
            }
            if(board[tr][tc]!=board[r][c])
                q.push(make_pair(tr,tc));
                // board[tr][tc]=board[r][c];
            else{
                change=true;
                break;
            }
        }
        if(change){
            while(!q.empty()){
                board[q.front().first][q.front().second]=board[r][c];
                q.pop();
            }
        }
    }
    
    // for(int i=1; i<7; i++){
    //     for(int j=1; j<7; j++){
    //         cout<<board[i][j]<<" ";
    //     }     
    //     cout<<endl;
    //  }
    //  cout<<endl;
    
}

int main(){
     board[3][3]=2;
     board[4][4]=2;
     board[3][4]=1;
     board[4][3]=1;
     
     cin>>n;
     bool turn = true;
     while(n--){
         int r,c;
         cin>>r>>c;
         if(turn){//1검은돌 true  2흰돌 false
            board[r][c]=1;
            check(r,c,1);
            turn =false;
         }
         else{
            board[r][c]=2;
            check(r,c,2);
            turn=true;
         }
     }

     int cntw=0,cntb=0;
     for(int i=1; i<7; i++){
        for(int j=1; j<7; j++){
            if(board[i][j]==1){
                cout<<"B";
                cntb++;
            }
            if(board[i][j]==2){
                cout<<"W";
                cntw++;
            }
            if(board[i][j]==0)cout<<".";
        }     
        cout<<endl;
     }
     string res=(cntw>cntb) ? "White" : "Black";
     cout<< res << endl;

}