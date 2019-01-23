#include<vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
private:
    bool compareInterval(Interval a, Interval b){
        return (a.start<b.start);
    }
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int res=0;
        if(intervals.size()<=1)return res;
        
        sort(intervals.begin(),intervals.end(),compareInterval);
        int pntst=intervals[0].start;
        int pnted=intervals[0].end;
        //If there are overlapping remove one with end with bigger num 
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i].start<pnted){
                res+=1;
                pnted=min(intervals[i].end,pnted);
            }
            else{
                pntst=intervals[i].start;
                pnted=intervals[i].end;
            }
        }
        return res;
    }
};

//O(nlogn+n)