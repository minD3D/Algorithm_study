#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
private:
    int rarr[4]={1,-1,0,0};
    int carr[4]={0,0,1,-1};
    vector<vector<char>>& pboard;
    string pword;
public:
    bool bfs(int r, int c, int p){
        if(p==pword.length())
            return true;
        
        for(int i=0; i<4; i++){
            int tr=r+rarr[i];
            int tc=c+carr[i];
            if(tr>=pboard.size()||tc>=pboard[0].size()||tr<0||tc<0)
                continue;
            if(pboard[tr][tc]==pword[p])
            {
                return bfs(tr,tc,p+1);
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        //bfs
        if(board.size()==0)return false;
        pboard=board;
        pword=word;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]==word[0]){
                    if(bfs(i,j,1))return true;
                }
            }
        }
        
        return false;
    }
};
int main(){
    Solution a;
    cout<<a.exist({{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}} ,"ABCCED");
}