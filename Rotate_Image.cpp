#include<iostream>
#include<map>
#include<queue>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
           vector<vector<int>> tmp;
           for(int i=0; i<matrix.size(); i++){
               vector<int> a;
               for(int j=matrix.size()-1; j>=0; j--){
                   a.push_back(matrix[j][i]);
               }
               tmp.push_back(a);
           }
           matrix=tmp;
    }
};
