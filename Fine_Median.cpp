#include<iostream>
#include<map>
#include<queue>
using namespace std;

class MedianFinder {
private:
    vector<int> lst;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        lst.clear();        
    }    
    void addNum(int num) {
        lst.push_back(num);
    }
    
    double findMedian() {
        int s=lst.size();
        sort(lst.begin(),lst.end());
        if(s%2==1){
            return lst[s/2];
        }else{
            return (lst[s/2]+lst[s/2])/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */