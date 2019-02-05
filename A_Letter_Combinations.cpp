#include<vector>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    string digit;
    int length;
    vector<vector<char>> letter={{' '},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    vector<string> result;

    void setLetters(int idx, string sets){
        if(idx==length){
            if(sets!="")
                result.push_back(sets);
            return;
        }
        int num=digit[idx]-'0';
        cout<<num<<endl;

        //digit[idx]*1;
        for(int i=0; i<letter[num].size(); i++){
            string tmp=sets;
            tmp+=letter[num][i];
            setLetters(idx+1, tmp);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        digit=digits;
        length=digits.length();        
        setLetters(0,"");
        return result;
    }
};