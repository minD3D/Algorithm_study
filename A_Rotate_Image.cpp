class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        int sz=matrix.size();
        for(int i=0; i<sz; i++){
            vector<int> a;
            for(int j=sz-1; j>=0; j--){
                a.push_back(matrix[j][i]);
            }
            res.push_back(a);
        }
        matrix=res;
        
    }
};