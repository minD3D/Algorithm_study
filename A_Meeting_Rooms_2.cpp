#include<vector>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compareInterval(Interval a, Interval b){
    return (a.start<b.start);
}
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size()<=1)
            return intervals.size();
        
        vector<int> rooms;
        sort(intervals.begin(), intervals.end(),compareInterval); //O(nlogn)
        int pnt=intervals[0].end;
        rooms.push_back(pnt);
        
        for(int i=1; i<intervals.size(); i++){//O(n)
            sort(rooms.begin(),rooms.end()); //O(nlogn)
            pnt=rooms[0];
            if(intervals[i].start<pnt){
                rooms.push_back(intervals[i].end);
            }
            else{
                for(int j=rooms.size()-1;j>=0; j--){
                    if(rooms[j]<=intervals[i].start){//O(n)
                        rooms[j]=intervals[i].end;
                        break;
                    }
                }
            }
        }      
        return rooms.size();
    }
};

//O(nlogn + n^2*logn + n^2)
//if I use priority queue i can make it O(nlogn + n^2*logn)