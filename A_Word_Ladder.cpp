#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> words;
    vector<bool> used;
    int res=999999999;
    string end;
    void findNext(string now, int cnt){
        for(int i=1; i<now.size()-1; i++){
            string beginNow=now.substr(0,i);
            string endNow=now.substr(i+1,now.size()-i-1);
            string beginEnd=end.substr(0,i);
            string endEnd=end.substr(i+1,end.size()-i-1);
            if(beginNow==beginEnd&&endNow==endEnd){
                cout<<now<<cnt<<endl;
                res=cnt<res ? cnt : res;
            }
        }

        for(int i=0; i<now.size(); i++){
            string beginNow=now.substr(0,i);
            string endNow=now.substr(i+1,now.size()-i-1);
            for(int j=0;j<words.size(); j++){
                if(used[j])
                    continue;
                string beginCpr=words[j].substr(0,i);
                string endCpr=words[j].substr(i+1,words[j].size()-i-1);
                // cout<<beginNow<<" "<<endNow<<"/"<<beginCpr<<" "<<endCpr<<endl;
                if(beginNow==beginCpr&&endNow==endCpr){
                    // cout<<"gotit"<<endl;
                    used[j]=true;
                    findNext(words[j],cnt+1);
                    used[j]=false;
                }
            }
        }
        return;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord.size()==1){
            return 2;
        }
        words=wordList;
        end=endWord;
        vector<bool> usedtmp(wordList.size(),false);
        used=usedtmp;
        findNext(beginWord,0);
        if(res!=999999999)
            return res+1;
        else
            return 0;
        
    }
};

// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
// "hit" -> "hot" -> "dot" -> "dog" -> "cog",