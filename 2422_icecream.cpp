#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n,m;
int arr[201][201];
int main(){
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
                
    }

    int cnt=0;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(arr[i][j]!=1){
                for(int k=j+1; k<=n; k++){
                    if(arr[i][k]!=1&&arr[j][k]!=1)
                        cnt++;
                }
            }
            
        }
    }
    cout<<cnt;
}