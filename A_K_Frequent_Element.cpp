#include<map>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;

        map<int,int> cnt;
        for(int i=0; i<nums.size(); i++){
            cnt[nums[i]]+=1;
        }
        
        priority_queue<pair<int,int> > pq;
        
        map<int,int>::iterator it;
        for( it=cnt.begin(); it!=cnt.end(); it++){
            pq.push(make_pair((*it).second,(*it).first));
        }

        for(int i=0; i<k; i++){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};

//O(n+n+klogn)=O(n+klogn)