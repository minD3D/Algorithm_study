#include<vector>
using namespace std;
//time limit
class Solution {
public:
    vector<int> num;
    vector<bool> visit;
    vector<vector<int>> result;
    void search(vector<int> res,int i){
                // cout<<"h";
        if(i==num.size()+1){
            return;
        }
        if(res.size()==3){
            if(res[0]+res[1]+res[2]==0){
                sort(res.begin(),res.end());
                if(result.size()==0)
                    result.push_back(res);
                else{
                   for(int j=0; j<result.size(); j++){
                       if(result[j][0]==res[0]&&result[j][1]==res[1]&&result[j][2]==res[2])
                            return;
                   }
                    result.push_back(res);
                }
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
        if(s==0)return result;
        for(int i=0; i<s; i++){
            visit.push_back(false);
            num.push_back(nums[i]);            
        }
        vector<int> tmp;
        search(tmp,0);
        return result;
    }
};