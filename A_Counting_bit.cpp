class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        
        for(int i=0; i<=num; i++){//O(n)
            int tmp=0;
            int v=i;
            while(v){//O(21억)
                if(v%2==1)tmp+=1;
                v=v>>1;
            }
            res.push_back(tmp);
        }
        
        return res;
    }
};

//worst O(n*210000000)
//O(n)

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};