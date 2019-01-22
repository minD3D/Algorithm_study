class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<=nums.size(); i++){//O(n)
            sum+=i;
        }
        for(int i=0; i<nums.size(); i++){//O(n)
            sum-=nums[i];
        }
        return sum;
    }
};

//O(2n)=O(n) =>liniar time