#include <iostream>
#include <string>
using namespace std;
int t, n, k;
int main(){
    cin>>t;
    while(t--){
        cin>>n>>k;
        char a= 'a';
        int dup=n/k;
        int cnt=0;
        int addcnt=0;
        string ans;
        for(int i=0 ; i<n; i++){
            if(cnt==dup&&addcnt!=k-1){
                a+=1;
                addcnt+=1;
                cnt=0;
            }
            ans+=a;
            cnt++;
        }
        cout<<ans<<endl;
    }

}
//길이 n 스트링 1-k까지의 