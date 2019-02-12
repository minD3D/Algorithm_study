class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        
        map<char,int> cnt;
        for(int i=0; i<s.size(); i++){
            cnt[s[i]]+=1;
        }   
        for(int i=0; i<t.size(); i++){
            if(cnt[t[i]]==0)
                return false;
            else
                cnt[t[i]]-=1;
        }   
        return true;
    }
};