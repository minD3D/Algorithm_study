#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int positive_map[nums.size()]={1};
        int negative_map[nums.size()]={1};
        int max_map=nums[0];
        for(int i=1; i<nums.size(); i++){
            map[i]=max(nums[i],nums[i]*nums[i-1]);
            max_map=max(max_map,map[i]);
        }
        
        return max_map;
    }
};