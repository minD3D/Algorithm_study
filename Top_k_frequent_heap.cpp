#include<iostream>
#include<map>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
            map <int, int> cntmap;
            priority_queue<pair<int, int>> pq;
            for(int i=0; i<nums.size(); i++){
                cntmap[nums[i]]+=1;
            }
            for(auto it=cntmap.begin(); it!=cntmap.end(); it++){
                pq.push(make_pair(it->second,it->first));
            }
            vector<int> res;
            for(int i=0; i<k; i++){
                res.push_back(pq.top().second);
                pq.pop();
            }
            return res;
    }
};