#include<map>
#include<vector>
#include<queue>
#include<string>
using namespace std;
//Find order from first letters
//Push at same queue if first letters are same 
//Do 1,2 in queue
//Merge connections
class Solution {
public:
    vector<vector<char>> Orders;
    string res;
public:
    void findOrder(vector<string> wordLst){
        char cur=wordLst[0][0];
        vector<string> newLst;            
        vector<char> orderset;
        orderset.push_back(cur);
        for(int i=0; i<wordLst.size(); i++){
            if(cur==wordLst[i][0]){
                newLst.push_back(wordLst[i].substr(1));
            }
            else{
                if(newLst.size()>1)
                    findOrder(newLst);
                newLst.clear();
                newLst.push_back(wordLst[i].substr(1));
                cur=wordLst[i][0];
                orderset.push_back(cur);
            }
        }
        Orders.push_back(orderset);
        setOrder();
        return;
    }
    void setOrder(){
        if(Orders.size()==0)
            return;
        if(Orders.size()==1){
            for(int i=0; i<Orders[0].size(); i++)
                res+=Orders[0][i];
            return;
        }

        vector<char> tmp=Orders[0];
        int pnt=0;
        for(int i=1; i<Orders.size(); i++){
            vector<char> cpr=Orders[i];
            //FAIL
        }

        res;
    }
    string alienOrder(vector<string>& words) {
        res="";
        findOrder(words);
        
        return res;
    }
};

// [
//   "wrt",
//   "wrf",
//   "er",
//   "ett",
//   "rftt"
// ]
// w e r
//     r t
//       t f
