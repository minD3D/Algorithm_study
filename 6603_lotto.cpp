#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int k=1;
int arr[15];
int visit[15];
void bfs(int idx, int n){
    
    if(n>6||idx==k+1)return;
       
    if(n==6){
         for(int i=0; i<k; i++){
            if(visit[i])
                cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    
    visit[idx]=1;
    bfs(idx+1,n+1);
    
    visit[idx]=0;
    bfs(idx+1,n);
}

int main(){
    while(k!=0){
        cin>>k;
        for(int i=0; i<k; i++){
            cin>>arr[i];
        }
        bfs(0,0);
        cout<<endl;
    }
}
