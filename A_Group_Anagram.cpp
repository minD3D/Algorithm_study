class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,int>> order;
        for(int i=0; i<strs.size(); i++){
            string tmp=strs[i];
            sort(tmp.begin(),tmp.end());
            order.push_back(make_pair(tmp,i));
        }
        sort(order.begin(),order.end());
        vector<vector<string>> res;
        vector<string> tmpvec;
        string cprstr=order[0].first;
        tmpvec.push_back(strs[order[0].second]);
        
        for(int i=1;i<order.size(); i++)
        {
            if(cprstr==order[i].first){
                tmpvec.push_back(strs[order[i].second]);
            }
            else{
                res.push_back(tmpvec);
                tmpvec.clear();
                cprstr=order[i].first;
                tmpvec.push_back(strs[order[i].second]);                
            }
            
            
        }
        res.push_back(tmpvec);
                
        return res;
    }
};


//Better solution for saving storage
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};