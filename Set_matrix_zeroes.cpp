#include<iostream>
#include<map>
#include<queue>
using namespace std;
class Solution {
private:
    vector<vector<int>> board;
    int rs,cs;
        
public:
    void setroute(int r, int c){
        int arrr[4]={0,0,1,-1};
        int arrc[4]={1,-1,0,0};
        for(int i=0; i<4; i++){
            int n=1;
            while(1){
                int tr=r+arrr[i]*n;
                int tc=c+arrc[i]*n;
                if(tr<rs&&tc<cs&&tr>=0&&tc>=0){
                    board[tr][tc]=0;
                    n+=1;
                }
                else
                    break;
            }
        }

        return;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        board= matrix;
        int arrr[4]={0,0,1,-1};
        int arrc[4]={1,-1,0,0};
        rs=matrix.size();
        cs=matrix[0].size();
        
        for(int i=0; i<rs; i++){
            for(int j=0; j<cs; j++){
                // cout<<matrix[i][j];
                if(matrix[i][j]==0){
                    setroute(i,j);   
                    // cout<<i<<j<<endl;
                }
            }
            // cout<<endl;
        }   


        // for(int i=0; i<rs; i++){
        //     for(int j=0; j<cs; j++){
        //         cout<<board[i][j];
        //         // if(matrix[i][j]==0)
        //         //     setroute(i,j);   
        //     }
        //     cout<<endl;
        // }  
        matrix=board; 
    }
};

int main(){
    vector<vector<int>> b={{0,1,1,0},{1,1,1,1},{1,1,1,1}};
    Solution a;
    a.setZeroes(b);
}