#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long n,s; // 꽃집 n개 꽃 s개
vector<unsigned long long> cb;
unsigned long long H(unsigned long long a, unsigned long long b){
    if(b==0)return 1;
    if(b<0)return 0;
    unsigned long long res1=1, res2=1;
    unsigned long long k=a+b-1;
    b= k-b < b ? k-b : b;
    if(k<=0)return 0;
    for(unsigned long long i=0; i<b; i++){
        res1*=k;
        k-=1;
        res2*=i+1;
    }
    if(res2==0)return 0;
    return res1/res2;
}

int main(){
// cout<<H(1,0);
    cin>>n>>s;
    cout<<endl<<n<<","<<s-n<<"="<<H(n,s-n)<<endl;
    unsigned long long res=H(n,s);
    unsigned long long t=n;
    unsigned long long cnt=0;

    while(t--){
        unsigned long long a;
        cin>>a;
        cnt+=a;
        res-=H(n,s-a-1);
        cout<<n<<","<<s-n-a<<"="<<H(n,s-n-a)<<endl;
    }
    if(s==cnt)cout<<1<<endl;
    else
        cout<<res%10000000000000000<<endl;
     
}