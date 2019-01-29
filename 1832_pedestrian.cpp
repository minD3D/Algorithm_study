#include <vector>
#include <iostream>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    vector<vector<pair<int,int>>> cnt;
    for(int i=0; i<m; i++){
        vector<pair<int,int>> a;
        for(int j=0; j<n; j++){
            a.push_back(make_pair(0,0));
        }
        cnt.push_back(a);
    }

    if(city_map[0][0]!=0)return answer;

    //first horizontal way
    //second vertical way
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0){
                if(city_map[i][j]==1){
                    cnt[i][j].first=0;
                    cnt[i][j].second=0;
                }
                else if(city_map[i][j]==2){
                    cnt[i][j].first=cnt[i][j-1].first+cnt[i][j-1].second;
                    cnt[i][j].second=0;
                }
                else{
                    if(j==0)cnt[i][j].first=1;
                    else
                        cnt[i][j].first+=cnt[i][j-1].first+cnt[i][j-1].second;
                }
            }
            else if(j==0){
                if(city_map[i][j]==1)
                    cnt[i][j].first=0;
                else if(city_map[i][j]==2){
                    cnt[i][j].first=0;
                    cnt[i][j].second=cnt[i-1][j].first+cnt[i-1][j].second;
                }
                else
                    cnt[i][j].first+=cnt[i-1][j].first;
            }

            else if(i!=0&&j!=0){
               if(city_map[i][j]==1){
                    cnt[i][j].first=0;
                }
                else{
                    if(city_map[i][j]==2){

                    }
                    else{
                        cnt[i][j].first+=cnt[i-1][j].first+cnt[i][j-1].first;

                    }
                }
            }
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<city_map[i][j];
        }
        cout<<endl;
    }
        cout<<endl;
    
      for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<cnt[i][j];
        }
        cout<<endl;
    }
    answer=cnt[m-1][n-1];
    return answer%MOD;
}
int main(){
    vector<vector<int> > a= {{0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0}};
    cout<<solution(3, 6, a); 
}