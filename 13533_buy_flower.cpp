#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long n,s; // 꽃집 n개 꽃 s개
vector<unsigned long long> flowers; // 꽃집 n개 꽃 s개
vector<unsigned long long> bought_flower; // 꽃집 n개 꽃 s개
int cnt=0;
void calsum(int pnt, unsigned long long sum){
    if(sum>s)return;
    if(sum==s){    
    // for( int k=0; k<n; k++)
    //     cout<<bought_flower[k];
    //     cout<<endl;    
        cnt++;
        return;
    }

    for(unsigned long long j=0; j<=flowers[pnt]; j++)
    {
        bought_flower[pnt]=j;
        sum+=j;
        if(pnt<=n-1)
            calsum(pnt+1,sum);
        bought_flower[pnt]=0;
        sum-=j;
    }
    return;
}

int main(){
    cin>>n>>s;
    int t=n;
    while(t--){
        unsigned long long a;
        cin>>a;
        flowers.push_back(a);
        bought_flower.push_back(0);
    }

    // n=3;
    // s=5;
    // flowers.push_back(1);
    // bought_flower.push_back(0);
    // flowers.push_back(2);
    // bought_flower.push_back(0);
    // flowers.push_back(3);
    // bought_flower.push_back(0);

    calsum(0,0);
    cout<<cnt<<endl;
}