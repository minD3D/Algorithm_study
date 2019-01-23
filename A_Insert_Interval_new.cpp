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
        //1. ed is before pnt start
        //2. ed is until pnt end and above end
        //3. st is after pnt end 
        bool input=true;

        for(int i=0; i<intervals.size(); i++){
            int pntst=intervals[i].start;
            int pnted=intervals[i].end;
            if(input){
                if(st<=pnted){
                    if(ed<pntst){
                        res.push_back(Interval(st,ed));
                        input=false;
                        res.push_back(intervals[i]);
                    }
                    else{
                        st=min(st, pntst);
                        ed=max(ed, pnted);
                        if(i+1==intervals.size())
                        {
                            input=false;
                            res.push_back(Interval(st,ed));
                        }
                    }
                }
                else{
                    res.push_back(intervals[i]);
                    if(i+1==intervals.size())
                    {
                        input=false;
                        res.push_back(Interval(st,ed));
                    }
                }
            }
            else{
                res.push_back(intervals[i]);
            }
            
        }
        return res;
    }
};