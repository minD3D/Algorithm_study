#include<vector>
#include<map>
using namespace std;
//List of int will be a input
//if the elements are not 
//If I sort it its so much faster than now

class Solution {
private:
    map <int,bool> connection;
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        int res=1;
        for(int i=0; i<nums.size(); i++){//O(n)
            int cur=nums[i];
            if(!connection[cur])
                connection[cur]=true;
        }
        map <int,bool>::iterator it;
        int cur=connection.begin()->first;
        int tmpcnt=1;
        for(it=connection.begin(); it!=connection.end(); it++){//O(n)
            if(cur+1==it->first){
                cout<<it->first<<endl;            
                tmpcnt+=1;
                // res= tmpcnt > res ? tmpcnt : res;
            }
            else{
                res= tmpcnt>res ? tmpcnt : res;
                tmpcnt=1;
            }
            cur=it->first;
        }
        res= tmpcnt > res ? tmpcnt : res;
        
        return res;
    }
};

//O(2n)