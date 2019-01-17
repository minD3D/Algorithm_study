#include <iostream>
#include <vector>
using namespace std;
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rs=matrix.size();
        int cs=matrix[0].size();
        bool horizontal[rs];
        bool vertical[cs];
        for(int i=0; i<cs; i++){
            for(int j=0; j<rs; j++){
                if(matrix[i][j]==0){
                    vertical[i]=false;
                    horizontal[j]=false;                    
                }
            }
        }

        for(int i=0; i<cs; i++){
            for(int j=0; j<rs; j++){
                if(!vertical[i]||!horizontal[j])
                    matrix[i][j]=0;
            }
        }
    }
};

int main(){
    Solution a;
    vector<int> b;
    b.push_back(1);
    b.push_back(1);
    b.push_back(1);
    vector<int> c;
    c.push_back(1);
    c.push_back(0);
    c.push_back(1);

    vector< vector<int> > d;
    d.push_back(b);
    d.push_back(c);
    d.push_back(b);
    
    a.setZeroes(&d);

}