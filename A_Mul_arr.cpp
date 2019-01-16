#include <iostream>
#include <vector>

using namespace std;
// Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int ns=nums.size();
        vector<int> res;
        if(ns==0)return res;

        vector<int> mul_from_front;
        vector<int> mul_to_end;
        int mul_f=1;
        int mul_e=1;
        for(int i=0; i<ns; i++){
            mul_f*=nums[i];
            mul_e*=nums[ns-1-i];
            mul_from_front.push_back(mul_f);
            mul_to_end.push_back(mul_e);
        }
        for(int i=0; i<ns; i++){
            if(i==0)
                res.push_back(mul_to_end[ns-2]);
            else if(i==ns-1)
                res.push_back(mul_from_front[ns-2]);
            else
                res.push_back(mul_from_front[i-1]*mul_to_end[ns-1-i]);
        }
        return res;
    }
};