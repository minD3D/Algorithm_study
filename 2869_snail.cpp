#include <cstdio>
#include <queue>
#include <iostream>  
#include <functional>
using namespace std;

int main() {
    int v,a,b;
    cin>>a>>b>>v;
    int left=0, right=1000000000, res=0;;
    while(left<=right){
        int day=(left+right)/2;
        if(v<=day*(a-b)+a){
            res= (res>day+1)? day+1 : res;
            right=day-1;
        }
        else
            left=day+1;
    }
    cout<<res<<endl;
}
