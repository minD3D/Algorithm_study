#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //sum of total - left sum -right sum
        int res=0;
        int total_sum=0;
        vector<int> left_sum; 
        vector<int> right_sum; 
        int left_tmp=0, right_tmp=0;
        left_sum.push_back(0);
        right_sum.push_back(0);
        
        for(int i=0; i<nums.size(); i++){
            total_sum+=nums[i];
            left_tmp+=nums[i];
            right_tmp+=nums[nums.size()-1-i];
            left_sum.push_back(left_tmp);
            right_sum.push_back(right_tmp);
        }

        for(int i=0; i<left_sum.size(); i++){
            for(int j=0; j<right_sum.size(); j++){
                int tmp=total_sum-left_sum[i]-right_sum[j];
                res=tmp>res ? tmp : res;
            }
        }

        return res;
    }
};

//better solution
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_map[nums.size()] = {0};
        max_map[0] = nums[0];
        int max_num = max_map[0];
        for(int i = 1; i < nums.size(); i++)
        {
            max_map[i] = max(nums[i], max_map[i-1]+nums[i]);
            max_num = max(max_map[i], max_num);
        }
        return max_num;
    }
};