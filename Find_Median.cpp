#include<iostream>
#include<map>
#include<queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> left;//가장큰거
    priority_queue<int> right;//가장작은거
    double mid=2100000000;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        priority_queue<int> emptylst1;
        priority_queue<int> emptylst2;
        left.swap(emptylst1);  
        right.swap(emptylst2);  
    }    
    void addNum(int num) {
        int ls= left.size(), rs=right.size();
        if(num<=mid){
            if(ls<=rs){
                left.push(num);
                ls+=1;
            }
            else{
                right.push(-1*left.top());
                left.pop();
                left.push(num);
                rs+=1;
            }
        }
        else if(num>mid){
            if(rs<=ls){
                right.push(-1*num);
                rs+=1;
            }
            else{
                left.push(-1*right.top());
                right.pop();
                right.push(-1*num);
                ls+=1;
            }
        }
        
        if(ls==rs){
            mid=(double)(left.top()+-1*right.top())/2;
        }
        else if(ls<rs){
            mid=-1*right.top();
        }
        else if(ls>rs){
            mid=left.top();
        }

    }
    
    double findMedian() {
        return mid;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */