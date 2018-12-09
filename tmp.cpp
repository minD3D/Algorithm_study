#include <vector>
#include <unordered_map>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    unordered_map<int,int> dp; //key=number, value=min used N number
    vector<vector<int>> nOfCnt(9); //NOfCount if (55+5 -> 3, 5+5+5+5 -> 4)

    nOfCnt[0].push_back(0);
    //number(1~32000); MAX_NUM_CNT=6, 999999/99=10101(o), 9999999/9=1111111(x)
    for(int i=1; i<7; i++) { 
        nOfCnt[i].push_back(nOfCnt[i-1][0]*10 + N); 
        dp[nOfCnt[i-1][0]*10 + N] = i;
    }

    for(int i=1; i<9; i++) {
        for(auto n1 : nOfCnt[i]) {
            for(int j=1; j<9-i; j++) {
                for(auto n2 : nOfCnt[j]) {
                    vector<int> cal = {n1+n2, n1-n2, n1*n2};
                    if(n2!=0) cal.push_back(n1/n2);

                    for(auto c : cal) //first number or min used N number
                        if(dp[c]==0 || dp[c]>i+j) 
                        { dp[c]=i+j; nOfCnt[i+j].push_back(c);}
                }
            }
        }
    }

    return answer= ( dp[number]==0 ? -1 : dp[number] );
}