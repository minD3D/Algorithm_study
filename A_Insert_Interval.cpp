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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        if(intervals.size()==0){
            res.push_back(newInterval);
            return res;
        }

        int st=newInterval.start;
        int ed=newInterval.end;
        bool input=true;

        // [[1,5]] 2<5 1<3 st ,ed
        // [2,3]
        for(int i=0; i<intervals.size(); i++){
            if(st<intervals[i].end&& intervals[i].start<=ed){
                // cout<<st<<ed<<endl;
                st=min(intervals[i].start,st);
                ed=max(intervals[i].end, ed);
            }
            else{
                if(input){
                    if(intervals[i].end<st)
                        res.push_back(intervals[i]);
                    else{
                        Interval tmp= Interval(st,ed);
                        res.push_back(tmp);
                        input=false;
                        res.push_back(intervals[i]);
                    }
                }
            }
        }
        if(res.size()==0)res.push_back(Interval(st,ed));
        return res;
    }
};