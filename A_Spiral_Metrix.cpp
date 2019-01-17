
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > matrix) {
        vector<int> res;
        //Change direction through left down right up order
        int rarr[4]={0,1,0,-1};
        int carr[4]={1,0,-1,0};
        //When the pointer meet visited point or end of matrix turn to next direction
        int rs=matrix.size();
        if(rs==0)return res;
        int cs=matrix[0].size();
        
        bool visited[rs][cs]={0,};
        for(int i=0; i<rs; i++){
            for(int j=0; j<cs; j++)
                visited[i][j]=0;
        }
        int r=0,c=0,d=0;
        int cnt=0;
        while(cnt<=rs*cs-1){
            if(!visited[r][c]){
                res.push_back(matrix[r][c]);
                visited[r][c]=true;
                cnt++;
            }
            int tr= r+rarr[d%4];
            int tc= c+carr[d%4];
            if(tr==rs||tc==cs||tr==-1||tc==-1){
                d++;
            }
            else{
                if(visited[tr][tc]){
                    
                    d++;
                    
                }
                else{
                    r=tr;
                    c=tc;
                }
            }
        }
        return res;
    }
};