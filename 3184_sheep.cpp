#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int r,c;
int arr[251][251];
int visit[251][251];
vector<pair<int,int>> t;
int dr[4]={0,0,1,-1};
int dc[4]={1,-1,0,0};
int o=0, int v=0;
void bfs(int tr, int tc){j
    for(int i=0; i<4; i++){
        int nr=tr+dr[i];
        int nc=tr+dc[i];
        if(nr<r&&nc<c&&nr>=0&&nc>=0){
            if(arr[nr][nc]==1&&visit[nr][nc]!=1)
            
        }
    }
}

int main(){
    cin>>r>>c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            char a;
            cin>>a;
            if(a=='.')arr[i][j]=0;
            if(a=='#')arr[i][j]=-1;
            if(a=='o'){
                arr[i][j]=1;
                t.push_back(make_pair(i,j));
            }
            if(a=='v'){
                arr[i][j]=2;
                t.push_back(make_pair(i,j));
            }
        }
    }

    for(int i=0; i<t.size(); i++){
        bfs(t[i].first,t[i].second);
    }
}
