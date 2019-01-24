#include<map>
#include<vector>
#include<queue>
using namespace std;
//make two priority queue
//left for smaller than mid num
//right for bigger than mid num
//for balancing left should be bigger order
//right should be smaller order


class MedianFinder {
private:
    priority_queue<int> left;
    priority_queue<int> right;
    double midval;
public:
    /** initialize your data structure here. */
    MedianFinder() { 
        priority_queue<int> n_left;
        priority_queue<int> n_right;

        left.swap(n_left);
        right.swap(n_right);

        midval=0;
    }
    
    void addNum(int num) {//O(logn);
        if(midval<num){
            right.push(num*-1);
        }
        else{
            left.push(num);
        }
        valancing();
    }
    
    void valancing(){//O(logn)
        int ls=left.size();
        int rs=right.size();
        if(ls+1<rs){
            int tmp=right.top()*-1;
            right.pop();
            left.push(tmp);
        }
        else if(ls>rs+1){
            int tmp=left.top();
            left.pop();
            right.push(tmp*-1);
        }

        ls=left.size();
        rs=right.size();
        if(ls==rs){
            midval=(double)(left.top()+right.top()*-1)/2;
        }
        else if(ls<rs){
            midval=right.top()*-1;
        }
        else if(ls>rs){
            midval=left.top();
        }

        return;
    }

    double findMedian() {
        return midval;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */