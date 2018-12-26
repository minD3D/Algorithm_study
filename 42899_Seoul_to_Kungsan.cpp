#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int K, vector<vector<int>> travel) {
    int answer = 0;
    int time=0;
    vector<pair<int,int>>dp;
    vector<pair<int,int>>tmp;
    //그단계의 시간, 모금액
    tmp.push_back(make_pair(travel[0][1],travel[0][0]));
    tmp.push_back(make_pair(travel[0][3],travel[0][2]));
    int curmax=0;
    for(int i=1; i<travel.size(); i++){
        for(int j=0; j<tmp.size(); j++){
            int sum1=tmp[j].first+travel[i][1];
            int sum_time1=tmp[j].second+travel[i][0];
            int sum2=tmp[j].first+travel[i][3];
            int sum_time2=tmp[j].second+travel[i][2];
            if(sum1>=sum2&&sum_time1<=sum_time2){
                if(sum_time1<=K){                
                    curmax= sum1 > curmax ? sum1 : curmax; 
                    dp.push_back(make_pair(sum1, sum_time1));    
                }
            }
            else if(sum1<=sum2&&sum_time1>=sum_time2){
                if(sum_time2<=K){
                    curmax= sum2 > curmax ? sum2 : curmax; 
                    dp.push_back(make_pair(sum2, sum_time2));
                }
            }
            else{
                if(sum_time1<=K){
                    curmax= sum1 > curmax ? sum1 : curmax; 
                    dp.push_back(make_pair(sum1, sum_time1));
                }
                if(sum_time2<=K){
                    curmax= sum2 > curmax ? sum2 : curmax; 
                    dp.push_back(make_pair(sum2, sum_time2));
                }
            }
        }
        if(i!=travel.size()-1)
        {
            tmp.swap(dp);
            dp.clear();
        }
    }
            // // cout<<i<<endl;
            // for(int j=0; j<dp.size(); j++){
            //     cout<<dp[j].first<<","<<dp[j].second<<endl;
            // }

    return curmax;
}

int main(){
    cout<<solution(3000,{{1000, 2000, 300, 700}, {1100, 1900, 400, 900}, {900, 1800, 400, 700}, {1200, 2300, 500, 1200}})<<endl;
}

// [도보 시간,모금액, 자전거 시간,모금액]
// {1000, 2000, 300, 700}, 
// {1100, 1900, 400, 900}, 
// {900, 1800, 400, 700}, 
// {1200, 2300, 500, 1200}



// {500, 200, 200, 100}, 
// {800, 370, 300, 120}, 
// {700, 250, 300, 90}});


// #include <string>
// #include <vector>
// #include <iostream>

// using namespace std;

// int solution(int K, vector<vector<int>> travel) {
//     int answer = 0;
//     int dp[101];
//     int time=0;
//     dp[0]=0;
//     for(int i=0; i<travel.size(); i++){
//         if(time+travel[i][0]<K){
//             if(time+travel[i][2]<K){
//                 if(travel[i][1]>travel[i][3]){
//                     dp[i+1]=dp[i]+travel[i][1];
//                     time+=travel[i][0];
//                 }
//                 else{
//                     dp[i+1]=dp[i]+travel[i][3];
//                     time+=travel[i][2];
//                 }
//             }
//             else{
//                 dp[i+1]=dp[i]+travel[i][1];
//                 time+=travel[i][0];
//             }
//         }
//         else if(time+travel[i][2]<K){
//             dp[i+1]=dp[i]+travel[i][3];
//             time+=travel[i][2];
//         }
//     }

//     for(int i=0; i<=travel.size(); i++){
//         cout<<dp[i]<<endl;
//     }

//     return dp[travel.size()];
// }

// int main(){
//     cout<<solution(3000,{{1000, 2000, 300, 700}, {1100, 1900, 400, 900}, {900, 1800, 400, 700}, {1200, 2300, 500, 1200}})<<endl;
// }

// // [도보 시간,모금액, 자전거 시간,모금액]
// // {500, 200, 200, 100}, 
// // {800, 370, 300, 120}, 
// // {700, 250, 300, 90}});


// {1000, 2000, 300, 700}, 
// {1100, 1900, 400, 900}, 
// {900, 1800, 400, 700}, 
// {1200, 2300, 500, 1200}