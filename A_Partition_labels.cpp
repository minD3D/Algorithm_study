class Solution {
public:
    vector<int> partitionLabels(string S) {
        //save biggest index on map
        map<char,int> bigidx;
        for(int i=0; i<S.size(); i++){
            bigidx[S[i]]=i;
        }
        
        vector<int> res;
        for(int i=0; i<S.size(); ){
            int tmp_p = bigidx[S[i]];
            for(int j=i; j<=tmp_p; j++){
                tmp_p=(bigidx[S[j]]>tmp_p)? bigidx[S[j]] : tmp_p;
            }
            res.push_back(tmp_p-i+1);
            i=tmp_p+1;
        }
        return res;
    }
};