#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp;
    dp[0][0]=triangle[0][0];
    for(int i=0; i<triangle.size(); i++){   
        for(int j=0; j<triangle[i].size(); j++){
            
        }
    }

    return answer;
}

int main(){
    vector<vector<int>> tri ={7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}}
    cout<<solution(tri);
}