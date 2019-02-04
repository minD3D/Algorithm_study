class Solution {
public:
    vector<int> num;
    vector<vector<int>> result;
    void selection(vector<int> list, int i){
        if(i==num.size()){
            result.push_back(list);
        }
        else{
            selection(list,i+1);
            list.push_back(num[i]);
            selection(list,i+1);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        num=nums;
        vector<int> tmp;
        selection(tmp,0);
        sort(result.begin(),result.end());
        
        vector<vector<int>> ret_result;
        tmp=result[0];
        if(tmp!=result[1])
            ret_result.push_back(tmp);
        for(int i=1; i<result.size(); i++){
            if(tmp!=result[i])
                ret_result.push_back(result[i]);
            tmp=result[i];
        }
        return ret_result;
    }
};