class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mapping[nums.size()+1][2];
        mapping[0][0]=1;//save max
        mapping[0][1]=1;//save min
        int tmp_neg=1;
        int max_map=nums[0];
        for(int i=0; i<nums.size(); i++){            
            mapping[i+1][0]= max(mapping[i][0]*nums[i],mapping[i][1]*nums[i]);     
            mapping[i+1][0]= max(mapping[i+1][0],nums[i]);                        
            mapping[i+1][1]= min(mapping[i][0]*nums[i],mapping[i][1]*nums[i]);
            mapping[i+1][1]= min(mapping[i+1][1],nums[i]);                        
            
            cout<<mapping[i+1][0]<<" "<<mapping[i+1][1]<<endl;
            max_map=max(max_map,mapping[i+1][0]);
        }
        
        return max_map;
    }
};