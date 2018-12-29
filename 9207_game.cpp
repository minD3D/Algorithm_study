#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;
int row,col;
int board[6][10];
vector<pair<int,int>> pin;

int dr[4]={0,0,1,-1};
int dc[4]={1,-1,0,0};

int rescnt=1;
int leftpin=0;

int isfin=false;
void dfs(int turn,int pinnum){
    if(leftpin>=pinnum){
        if(leftpin==pinnum)
            rescnt= rescnt>turn ? turn : rescnt;
        else{
            leftpin=pinnum;
            rescnt=turn;
        }
    }

    // for(int r=0; r<row; r++){
    //     for(int c=0; c<col; c++){
    //         cout<<board[r][c];
    //     }
    //     cout<<endl;
    // }
    // cout<<pinnum<<endl;

    for(int r=0; r<row; r++){
        for(int c=0; c<col; c++){
            if(board[r][c]==1){
                for(int k=0; k<4; k++){
                    int tr=r+dr[k];   
                    int tc=c+dc[k];
                    if(tr<row &&tc<col && tr>=0 && tc>=0){
                        int nr=r+2*dr[k];   
                        int nc=c+2*dc[k];
                        if(nr<row &&nc<col && nr>=0 && nc>=0){
                            if(board[tr][tc]==1&&board[nr][nc]==0){
                                isfin=false;
                                board[r][c]=0;
                                board[tr][tc]=0;
                                board[nr][nc]=1;
                                dfs(turn+1,pinnum-1);
                                board[r][c]=1;
                                board[tr][tc]=1;
                                board[nr][nc]=0;
                            }
                        }
                    }
                    
                }
            }    
        }
    }
    

    return;
}

int main(){
    int n;
    cin>>n;
    int arr[101][2];
    for(int k=0; k<n; k++){
        row=5;
        col=9;
        leftpin=0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                char a;
                cin>>a;
                if(a=='.')board[i][j]=0;
                if(a=='#')board[i][j]=2;
                if(a=='o'){//pin
                    board[i][j]=1;
                    leftpin+=1;
                }
            }
        }
        dfs(0,leftpin);
        arr[k][0]=leftpin;
        arr[k][1]=rescnt;
    }
    for(int k=0; k<n; k++){
        cout<<arr[k][0]<<" "<<arr[k][1]<<endl;
    }   
}
