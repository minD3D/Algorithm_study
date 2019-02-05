#include<string>
#include<vector>
#include<map>
using namespace std;

//time limit error
class Solution {
public:
    map<char,vector<string>> dictionary;
    bool res;
    string str;
    
    //match function
    bool matchWord(int idx){
        if(idx==str.length()){
            res=true;
            return true;
        }
        char fc=str[idx];
        for(int i=0;i<dictionary[fc].size(); i++){
            string cpr_str=dictionary[fc][i];
            string sub_str=str.substr(idx,cpr_str.length());
            if(cpr_str==sub_str){
                if(matchWord(idx+cpr_str.length())){
                    return true;
                }
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        str=s;
        //mapping at dictionary
        for(int i=0; i<wordDict.size(); i++){
            if(wordDict[i].length()==0)
                continue;
            char firstLetter=wordDict[i][0];
            dictionary[firstLetter].push_back(wordDict[i]);
        }
        res=false;
        matchWord(0);
        return res;
    }
};