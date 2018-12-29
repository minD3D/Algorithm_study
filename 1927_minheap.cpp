#include <string>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
int n,x;

int main(){
    cin>>n;
    priority_queue<int, vector<int>,greater<int>>pq;
    while(n--){
        cin>>x;
        if(x==0){
            if(pq.empty())
                cout<<0<<endl;
            else{
                int res=pq.top();
                pq.pop();
                cout<<res<<endl;
            }
        }
        else{
            pq.push(x);
        }
    }    
    return 0;
}
