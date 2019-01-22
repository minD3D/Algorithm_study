class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        
        int a=32;
        while(a--){
            res=res<<1;

            if(n%2==1)
                res+=1;
            
            n=n>>1;
        }
        return res;
    }
};
// O(1)