bool compareInterval(Interval a, Interval b){
    return (a.start<b.start);
}
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size()<=1)return true;

        sort(intervals.begin(),intervals.end(),compareInterval);
        int pntst=intervals[0].start;
        int pnted=intervals[0].end;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i].start<pnted){
                return false;
            }
            else{
                pntst=intervals[i].start;
                pnted=intervals[i].end;
            }
        }
        return true;
    }
};