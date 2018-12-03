#include<iostream>
#include<vector>
using namespace std;
#define INF 100000000
int res=INF;
int findRoute(int s, int e, vector<pair<int,int>> map[], int cost){//벡터를 주소로 넘길것 
    //끝나는 조건 줄것 
    for(int i=0; i<map[s].size(); i++){
        if(map[s][i].first==e){
            int c=cost+=map[s][i].second;
            res=(c<res) ? c:res;
            return c;
        }
        else
            findRoute(map[s][i].first,e,map,cost+map[s][i].second);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int[3]> data;
    vector<pair<int,int>> depart[n+1];
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        depart[a].push_back(make_pair(b,c));
    }

    int s,e;
    cin>>s>>e;

    findRoute(s,e,depart,0);
    cout<<res;
    return 0;
}
