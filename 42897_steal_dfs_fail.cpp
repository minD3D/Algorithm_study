#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> marr;
int res;
void dfs(int cur, int sum){
    // cout<<cur<<","<<sum<<endl;
    if(cur==marr.size()){
        res=sum>res ? sum : res;
        return;
    }
    if(cur==marr.size()-1){
        if(marr[0]==true)
            dfs(cur+1,sum);
        else
            dfs(cur+1,sum+marr[cur]);
    }    
    else{
        if(cur!=0){
            if(visit[cur-1]==true){
                dfs(cur+1,sum);
            }
            else{
                visit[cur]=true;
                dfs(cur+1,sum+marr[cur]);
                visit[cur]=false;
                dfs(cur+1,sum);
            }
        }
        else{
            visit[cur]=true;
            dfs(cur+1,sum+marr[cur]);
            visit[cur]=false;
            dfs(cur+1,sum);
        
        }
        
    }
    return;
}

int solution(vector<int> money) {
    for(int i=0;i<money.size(); i++){
        visit.push_back(0);
        marr.push_back(money[i]);
    }
    
    dfs(0,0);
    return res;
}

int main(){
    cout<<solution({1,2,3,1});
}