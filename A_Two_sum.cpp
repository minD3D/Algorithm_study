#include <iostream>
using namespace std;
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 2 7 11 15
        vector<int> res;

        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j]==target){
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }   
        }
        return res;
    }
};