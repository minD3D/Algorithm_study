#include<vector>
#include<map>
using namespace std;
//check all of points
//DFS until the water meet some ocean

//=>DFS time limit exception
//=>change to BFS

class Solution {
private:
    vector<vector<pair<bool,bool>>> reached; //<Pacific, Atlantic>
    vector<vector<bool>> visited; 
    vector<vector<int>> map; 
    int rarr[4]={0,0,1,-1};
    int carr[4]={1,-1,0,0};
public:
    void DFS(int r, int c, int sr, int sc){
        visited[r][c]=true;
        for(int i=0; i<4; i++){
            int tr= r+rarr[i];
            int tc= c+carr[i];
            // cout<<tr<<tc<<endl;
            if(tr<0||tc<0){
                reached[sr][sc].first=true;
                continue;
            }
            else if(tr>=map.size()||tc>=map[0].size()){
                reached[sr][sc].second=true;
                continue;
            }
            else if(tr>=0&&tc>=0&&tr<map.size()&&tc<map[0].size()){
                if(map[tr][tc]<=map[r][c]&&!visited[tr][tc])
                    DFS(tr,tc,sr,sc);
            }
        }
        visited[r][c]=false;
        return;
    }
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> res;
        if(matrix.size()==0)return res;
        for(int i=0; i<matrix.size(); i++){
            vector<int> a;
            vector<pair<bool,bool>> b;
            vector<bool> c;
            for(int j=0; j<matrix[0].size(); j++){
                a.push_back(matrix[i][j]);
                b.push_back(make_pair(false,false));
                c.push_back(false);
            }
            map.push_back(a);
            reached.push_back(b);
            visited.push_back(c);
        }

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                DFS(i,j,i,j);
            }
        }

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(reached[i][j].first==true&&reached[i][j].second==true){
                    res.push_back(make_pair(i,j));
                }
           }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> a={{1,1,1},{0,0,0},{0,0,0}};
    s.pacificAtlantic(a);
}