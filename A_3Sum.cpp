#include<vector>
using namespace std;
//time limit
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (unsigned int i=0; i<nums.size(); i++) {
        if ((i>0) && (nums[i]==nums[i-1]))
            continue;
        int l = i+1, r = nums.size()-1;
        while (l<r) {
            int s = nums[i]+nums[l]+nums[r];
            if (s>0) r--;
            else if (s<0) l++;
            else {
                res.push_back(vector<int> {nums[i], nums[l], nums[r]});
                while (nums[l]==nums[l+1]) l++;
                while (nums[r]==nums[r-1]) r--;
                l++; r--;
            }
        }
    }
    return res;
}

public:
    vector<int> num;
    vector<bool> visit;
    vector<vector<int>> result;
    void search(vector<int> res,int i){
        if(i==num.size()){
            return;
        }
        if(res.size()==3){
            if(res[0]+res[1]+res[2]==0){
                sort(res.begin(),res.end());
                result.push_back(res);
                
            }
            else return;
        }
        else{
            search(res,i+1);
            res.push_back(num[i]);
            search(res,i+1);
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {        
        int s=nums.size();
        if(s<3)return result;
        if(s==3){
            if(nums[0]+nums[1]+nums[2]==0){
                vector<int> tmp;
                tmp.push_back(nums[0]);
                tmp.push_back(nums[1]);
                tmp.push_back(nums[2]);
                result.push_back(tmp);                
            }
            return result;
        }
        for(int i=0; i<s; i++){
            visit.push_back(false);
            num.push_back(nums[i]);            
        }
        vector<int> tmp;
        search(tmp,0);

        sort(result.begin(),result.end());
        int p0=result[0][0];
        int p1=result[0][1];
        int p2=result[0][2];

        vector<vector<int>> res;
        if(p0!=result[1][0]||p1!=result[1][1]||p2!=result[1][2])
            res.push_back(result[0]);
        for(int i=1; i<result.size(); i++){
            if(p0!=result[i][0]||p1!=result[i][1]||p2!=result[i][2])
                res.push_back(result[i]);
            p0=result[i][0];
            p1=result[i][1];
            p2=result[i][2];
        }          
        return res;
    }
};