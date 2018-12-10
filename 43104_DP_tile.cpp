#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    int n=1,o=1;
    long long dp[N];
    dp[1]=6;
    for(int i=2; i<=N; i++){
        dp[i]=dp[i-1]+(n+o)*2;
        cout<<o<<","<<n<<endl;
        int tmp=n;
        n+=o;
        o=tmp;
        cout<<dp[i]<<endl;
    }
    
    //1일때는 특별히 4리턴 
    if(N==1)return 4;
    return dp[N];
}

int main(){
    cout<<solution(5);
}