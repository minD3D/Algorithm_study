#include<vector>
#include<map>
using namespace std;
//List of int will be a input
//if the elements are not 

class Solution {
private:
    map <int,int> connection;
public:
    void setnum(int n){
        int i=1;
        int tmp=connection[n+i];
        while(tmp!=0){
            connection[n+i]=connection[n];
            i+=1;
            tmp=connection[n+i];
        }
        i=1;
        tmp=connection[n-i];
        while(tmp!=0){
            connection[n-i]=connection[n];
            i+=1;
            tmp=connection[n-i];
        }
        return;
    }
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        int res=0;
        for(int i=0; i<nums.size(); i++){
            int cur=nums[i];
            if(connection[cur])continue;
            connection[cur]=connection[cur-1]+connection[cur+1]+1;
            setnum(cur);
            res=connection[cur]>res ? connection[cur] : res;
        }
        return res;
    }
};
