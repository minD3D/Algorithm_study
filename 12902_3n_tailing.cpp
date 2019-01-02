#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 2    2
// 4    22 4
// 6    222 42 24  6
// 8    2222 44  62 26 
// 10  22222 442 244 424 
// 12


// extra t[0]*2+t[2]*2+t[4]*2
// t[4]=t[2]*3+t[0]*2
// t[6]=t[4]*3+t[0]*2+t[2]*2
// t[8]=t[6]*3+(t[0]*2+t[2]*2+t[4]*2)

vector<vector<int>> dp;
int solution(vector<int> left, vector<int> right) {
    int answer = 0;
    int maxsum=0;
    for(int i=0; i<left.size(); i++){   
        vector<int> a;
        int l=left[i];
        int rsum=0;
        for(int j=0; j<right.size(); j++){
            int r=right[j];
            if(r<=l&&j<=i){
                a.push_back(r);
                rsum+=r;
            }
            else
                a.push_back(0);
        }    
        dp.push_back(a);
    }
    
    for(int i=1; i<left.size(); i++){   
        for(int j=1; j<right.size(); j++){
            dp[i][j]+=(dp[i-1][j-1]>dp[i][j-1]) ? dp[i-1][j-1]:dp[i][j-1];
            if(j==right.size()-1)
                maxsum= dp[i][j]>maxsum ? dp[i][j] : maxsum;
        }
    
    }

    return maxsum;
}

int main(){
    cout<<solution({3,2,5},{2,4,1});

}