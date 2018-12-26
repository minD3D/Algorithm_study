#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int arrr[4]={0,0,1,-1};
int arrc[4]={1,-1,0,0};
int solution(vector<vector<int> > maps)
{
    int curr,curc;
    int n=maps.size();
    int m=maps[0].size();
    queue<pair<int, int>> q;
    q.push(make_pair(0,0));
    int s=q.size();    
    int cnt=2;
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
                if(maps[tmpr][tmpc]==1){
                    q.push(make_pair(tmpr,tmpc)); 
                    maps[tmpr][tmpc] = cnt;              
                }
                if(maps[tmpr][tmpc]>1){
                    // q.push(make_pair(tmpr,tmpc)); 
                    maps[tmpr][tmpc] = cnt<maps[tmpr][tmpc] ? cnt : maps[tmpr][tmpc];              
                }
            }
        }
        if(s==0){
            cnt+=1;
            s=q.size();
        }   
    }

    if(maps[n-1][m-1]>1)
        return maps[n-1][m-1];
    else
        return -1;
}

int main(){
    // {1,0,1,1,1},
    // {1,0,1,0,1},
    // {1,0,1,1,1},
    // {1,1,1,0,1},
    // {0,0,0,0,1}

    cout<<solution({{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}});

}