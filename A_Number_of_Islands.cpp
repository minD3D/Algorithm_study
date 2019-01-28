#include<vector>
#include<map>
using namespace std;
//count is up and left is 1
//if up or left side is 1 don't count
//=> Doesn't work It can connected with right side 

//=>call DFS to visit all points and count one
class Solution {
private: 
    vector<vector<bool>>visited;
    vector<vector<char>> map;
public:
    void visitit(int r, int c){//O(4*mn)
        visited[r][c]=true;
        int rarr[4]={0,0,1,-1};
        int carr[4]={1,-1,0,0};
        for(int i=0; i<4; i++){
            int tr=r+rarr[i];
            int tc=c+carr[i];
            if(tr>=0&&tc>=0&&tr<map.size()&&tc<map[0].size()){
                if(map[tr][tc]=='1'&&!visited[tr][tc]){
                    visitit(tr,tc);
                }
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        if(grid.size()==0)return res;
        for(int i=0; i<grid.size(); i++){
            vector<char> a;
            vector<bool> b;
            for(int j=0; j<grid[0].size(); j++){
                a.push_back(grid[i][j]);
                b.push_back(false);
            }
            map.push_back(a);
            visited.push_back(b);
        }
        for(int i=0; i<grid.size(); i++){//O(mn)
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1'){
                    if(!visited[i][j]){
                        res+=1;
                        visitit(i,j);
                    }
                }
            }
        }
        return res;        
    }
};

//O(4m^2n^2) =O(m^2*n^2)