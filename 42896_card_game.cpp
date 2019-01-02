#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
            if(r<l){
                a.push_back(r);
                rsum+=r;
            }
            else
                a.push_back(0);
        }    
        maxsum= rsum>maxsum ? rsum : maxsum;
        dp.push_back(a);
    }
    

    // for(int i=0; i<left.size(); i++){   
    //     for(int j=0; j<right.size(); j++){
    //         cout<<dp[i][j];
    //     }    
    //     cout<<endl;
    // }
    return maxsum;
}
// 1. 언제든지 왼쪽 카드만 통에 버릴 수도 있고 왼쪽 카드와 오른쪽 카드를 둘 다 통에 버릴 수도 있다. 이때 얻는 점수는 없다.
// 2. 오른쪽 카드에 적힌 수가 왼쪽 카드에 적힌 수보다 작은 경우에는 오른쪽 카드만 통에 버릴 수도 있다. 오른쪽 카드만 버리는 경우에는 오른쪽 카드에 적힌 수만큼 점수를 얻는다.
// 3. (1)과 (2)의 규칙에 따라 게임을 진행하다가 어느 쪽 더미든 남은 카드가 없다면 게임이 끝나며 그때까지 얻은 점수의 합이 최종 점수가 된다.
int main(){
    cout<<solution({3,2,5},{2,4,1});

}