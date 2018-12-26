#include<vector>
#include<queue>
#include<iostream>
using namespace std;
int arrr[4]={0,0,1,-1};
int arrc[4]={1,-1,0,0};
int solution(vector<vector<int> > maps)
{
	int answer = 0;
    bool visit[101][101];
    int curr,curc;
    int n=maps.size();
    int m=maps[0].size();
    queue<pair<int, int>> q;
    q.push(make_pair(0,0));
    int s=q.size();
    while(s--){
        curr=q.front().first;
        curc=q.front().second;
        q.pop();
        if(curr==n-1&&curc==m-1){
            
            break;
        }
        for(int i=0; i<4; i++){
            int tmpr=curr+arrr[i];
            int tmpc=curc+arrc[i];
            if(tmpr>=0&&tmpc>=0&&tmpr<n&&tmpc<m){
                if(maps[tmpr][tmpc]==1&&visit[tmpr][tmpc]==false){
                    // cout<<tmpr<<","<<tmpc<<endl;
                    q.push(make_pair(tmpr,tmpc)); 
                    visit[tmpr][tmpc]=true;
                }
            }
        }
        if(s==0){
            answer+=1;
            s=q.size();
        }   
    }

    if(visit[n-1][m-1])
        return answer+1;
    else
        return -1;
}

int main(){
    // {1,0,1,1,1},
    // {1,0,1,0,1},
    // {1,0,1,1,1},
    // {1,1,1,0,1},
    // {0,0,0,0,1}

    cout<<solution({{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,0},{0,0,0,0,1}});

}