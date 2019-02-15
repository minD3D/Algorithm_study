class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()<=1)return 0;
        if(cost.size()==2){
            return cost[0]<cost[1] ?cost[0]: cost[1];
        }
            
        for(int i=2; i<cost.size(); i++){
            cost[i]+= cost[i-1]>cost[i-2] ? cost[i-2]:cost[i-1]; 
        }
        return cost[cost.size()-1]<cost[cost.size()-2] ?  cost[cost.size()-1]: cost[cost.size()-2];
    }
};