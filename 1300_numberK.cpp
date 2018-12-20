#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
using namespace std;
int n,k;
vector<int> v;
int main(){
    //    1  2  3  4  5
    // 1  1  2  3  4  5
    // 2  2  4  6  8  10
    // 3  3  6  9  12 15
    // 4  4  8  12 16 20
    //                25
    // 5  5  10 15 20  

    //1 2 2 3 3 4 4 4 5 5 6 6 8 8 9 12 12 16 
    
    cin>>n>>k;
    int left=1;
    int right=k;
    int m,res;

    while(left<=right){
        m=(1+right)/2;
        int cnt=0;
        for(int i=1; i<=n; i++){
            cnt+=min(m/i,n);
        }
        if(cnt<k)
         left=m+1;
        else{
            res=m;
            right=m-1;
        }    
    }
    
    cout<<res<<endl;
}


int main() {

   cin >> n >> k;
   long long left = 1;
   long long right = k;
   int ans;
   while (left <= right) {
      long long cnt = 0;
      long long mid = (left + right) / 2;
      for (int i = 1; i <= n; ++i) cnt += min(mid / i, n);   // i * j 보다 작은수를 찾아야하므로 mid / i => j를 이용 , n보다 클순 없으므로 n이 최대   
      if (cnt < k) {
         left = mid + 1;
      }
      else {
         ans = mid;
         right = mid - 1;
      }
   }

   cout << ans << '\n';

   return 0;
}