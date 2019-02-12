class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0)return false;
        if(matrix[0].size()==0)return false;
        for(int i=0; i<matrix.size() ; ){
            for(int j=matrix[0].size()-1; j>=0; ){
                cout<<i<<j<<matrix[i][j]<<endl;
                if(target>matrix[i][j]){
                    if(i==matrix.size()-1)return false;
                    i++;
                }
                else if(target<matrix[i][j]){
                    if(j==0)return false;
                    j--;
                }
                else
                    return true;  
            }
        }
        return false;
    }
};