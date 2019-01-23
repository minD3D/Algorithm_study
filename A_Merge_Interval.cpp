#include<vector>
using namespace std;
  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
/**
 * Definition for an interval.
;
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int pntst=intervals[0].start;
        int pnted=intervals[0].end;
        vector<Interval> res;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i].start<pnted)
                pnted=intervals[i].end;
            else{
                res.push_back(Interval(pntst,pnted));
                pntst=intervals[i].start;
                pnted=intervals[i].end;
            }
            if(i+1==intervals.size())
                res.push_back(Interval(pntst,pnted));
        }      
        return res;
    }
};