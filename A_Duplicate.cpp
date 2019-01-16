#include <iostream>
#include <map>

using namespace std;
// Given an array of integers, find if the array contains any duplicates.
// Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()==0)
            return false;

        map <int, bool> isDuplicated;
        for(int i=0; i<nums.size(); i++){
            if(isDuplicated[nums[i]]){
               return true; 
            }
            else{
                isDuplicated[nums[i]]=true;
            }
        }
        return false;
    }
};