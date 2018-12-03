#include<iostream>
#include<vector>
#include<queue>
#define INF 10000000
using namespace std;
int n,m;
int cost[101][101]={10000,};
int min(int a, int b){
    return ( a < b ? a: b );
}

int main(){
    cin>>n>>m; 

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cost[i][j]=100000;
        }
    }
    
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        cost[a][b]=min(c,cost[a][b]);
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i==j)cost[i][j]=0;
                else {
                        cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
                }
            }
        }
    }
    

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(cost[i][j]==INF)
                cout<<"0 ";
                
            else
            cout<<cost[i][j]<--<" ";
        }
        cout<<endl;
    }

}

pair<int,char> a;
