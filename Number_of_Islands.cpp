#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<vector<char>> checkIsland(vector<vector<char>> grid,int row,int col) {
    queue<pair<int,int>> tq;
    tq.push(make_pair(row,col));
    while(!tq.empty()){
        int s=tq.size();
        for(int i=0; i<s; i++){
            int cf=tq.front().first;
            int cs=tq.front().second;
            tq.pop();
            if(cs+1==grid[0].size()){
                // cout<<"!!!!!!!"<<cf<<","<<cs<<endl;
                return grid;
            }
            if(grid[cf][cs+1]=='1'){
                tq.push(make_pair(cf,cs+1));
                grid[cf][cs+1]='0';
            }
            
            if(cf+1==grid.size())
                return grid;
            if(grid[cf+1][cs]=='1'){
                tq.push(make_pair(cf+1,cs));
                grid[cf+1][cs]='0';
            }
        }
    }
    return grid;
}

int numIslands(vector<vector<char>>& grid) {
    if(grid.size()==0)
    return 0;

    queue<pair<int,int>> q;
    bool used[grid.size()][grid[0].size()];
    int res=0;
    q.push(make_pair(0,0));
    used[0][0]=1;
    while(!q.empty()){
        int size=q.size();
        for(int i=0; i<size; i++){
            int f=q.front().first;
            int s=q.front().second;
            q.pop();
            if(grid[f][s]=='1'){
                // cout<<f<<","<<s<<endl;
                grid=checkIsland(grid, f, s);
                res++;
            }
            if(f+1<grid.size()&&!used[f+1][s]){
                q.push(make_pair(f+1,s));
                used[f+1][s]=1;
            }
            if(s+1<grid[0].size()&&!used[f][s+1]){
                q.push(make_pair(f,s+1));
                used[f][s+1]=1;
            }
        }
    }

    return res;    
}

int main(){
    // [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]
    vector<vector<char>> a = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    cout<<numIslands(a)<<endl;
    // if(a[0][0]=='1')
    // cout<<"!!";
}
