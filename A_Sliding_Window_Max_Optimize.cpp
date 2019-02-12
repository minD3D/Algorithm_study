class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& num, int k) {
        if(nums.size()==0)return res;
        vector<pair<int,int>> order;
        for(int i=0; i<nums.size(); i++){
            order.push_back(make_pair(-1*nums[i], i));
        }
        sort(order.begin(),order.end());
        
        for(int i=0; i<nums.size()-k+1; i++){
            int pnt=0;
            while(order[pnt].second>=i+k||i>order[pnt].second){
                pnt++;
            }
            res.push_back(-1*order[pnt].first);
        }
        
        return res;
    }
};