#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    unordered_map<int, int> dp; //key는 숫자고 val은 가장작은 사용횟수
    vector<vector<int>> cnt(9);

    cnt[0].push_back(0);

    //22 222 2222등 같은 숫자 쌓는 경우 저장
    for(int i=1; i<7; i++){
        cnt[i].push_back(cnt[i-1][0]*10+N);
        dp[cnt[i-1][0]*10+N]=i;
    }

    for(int i=1; i<9; i++){
        for(auto n1: cnt[i]){
            for(int j=1; j<9-i; j++){
                for(auto n2 : cnt[j]){
                    vector<int> cal ={n1+n2,n1-n2,n1*n2};
                    if(n2!=0)cal.push_back(n1/n2);

                    for(auto c:cal)
                        if(dp[c]==0||dp[c]>i+j){
                            dp[c]=i+j;
                            cnt[i+j].push_back(c);
                        }
                }
            }
        }
    }
    return answer=(dp[number]==0 ? -1 : dp[number]);
}

int main(){
    cout<<solution(5,12);
}