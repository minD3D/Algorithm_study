#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int n;
queue<pair<int,int>> qu;
vector<pair<int,int>> qu2;
 
bool** checkset(int x, int y, bool** pos){
    for(int i=0; i<n; i++){
        pos[x][i]=false;
        pos[i][y]=false;
        if(x+i<n&&x+i>=0&&y+i<n&&y+i>=0)
            pos[x+i][y+i]=false;
        if(x+i<n&&x+i>=0&&y-i<n&&y-i>=0)
            pos[x+i][y-i]=false;
        if(x-i<n&&x-i>=0&&y+i<n&&y+i>=0)
            pos[x-i][y+i]=false;
        if(x-i<n&&x-i>=0&&y-i<n&&y-i>=0)
            pos[x-i][y-i]=false;
    }
    return pos;
}

int* dfs(bool** pos, queue<pair<int,int>> q, int* arr){
    if(q.empty())
        return arr;
    if(q.front().first==n-1){
        arr[q.front().first]=q.front().second;
        return arr;
    }
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        arr[y]=x;
        pos=checkset(x,y,pos);
        queue<pair<int,int>> q2;
        for(int i=0; i<n; i++){
            if(pos[y+1][i])
                q2.push(make_pair(y+1,i));
        }
        dfs(pos,q2,arr);
    }
}

int main(){
    cin>>n;
    bool pos[n][n]={true,};
    int arr[n];
    for(int i=0; i<n; i++){
        qu.push(make_pair(0,i));
    }
    arr=dfs(pos,qu,&arr);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}