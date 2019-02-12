class Solution {
public:
    int countPrimes(int n) {
        if(n<=1)return 0;
        vector<bool> prime(n,true);
        prime[0]=false;
        prime[1]=false;
        vector<int> added;
        for(int i=2; i<n; i++){
            if(!prime[i])continue;
            if(prime[i]){
                added.push_back(i);
                for(int z=i; z<n; z+=i){
                    // cout<<z<<"/";
                    prime[z]=false;
                }            
            // cout<<endl;
            }
        }
        return added.size();
    }
};