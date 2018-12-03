#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int numSquares(int n) {
    queue<int> q;
    int res=0;
    q.push(n);
    while(!q.empty()){
        int s=q.size();
        res++;
        while(s--){
            int cur=q.front();
            q.pop();
            for(int i=1; i<n; i++){
                if(cur-i*i<0)
                    break;
                if(cur-i*i==0){
                    return res;
                }
                // if(cur-i*i>0)
                    q.push(cur-i*i);
            }
        }
    }
}

int main(){
    // [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]
    vector<vector<char>> a = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    cout<<numSquares(18)<<endl;
    // if(a[0][0]=='1')
    // cout<<"!!";
}
