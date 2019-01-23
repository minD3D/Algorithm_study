    bool compareInterval(Interval i1, Interval i2) 
    { 
        return (i1.start < i2.start); 
    } 
class Solution {
public:

    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.size()==0)return res;
        if(intervals.size()==1)return intervals;
        

        sort(intervals.begin(),intervals.end(),compareInterval);
        int pntst=intervals[0].start;
        int pnted=intervals[0].end;
        
        for(int i=1; i<intervals.size(); i++){
            cout<<intervals[i].start<<intervals[i].end<<endl;
            cout<<pntst<<pnted<<endl;
            
            if(intervals[i].start<=pnted){
                pntst=min(intervals[i].start,pntst);
                pnted=max(intervals[i].end,pnted);   
            }
            else{
                res.push_back(Interval(pntst,pnted));
                pntst=intervals[i].start;
                pnted=intervals[i].end;
            }
            if(i+1==intervals.size())
                res.push_back(Interval(pntst,pnted));
            cout<<pntst<<pnted<<endl<<endl;
            
        }      
        return res;
    }
};