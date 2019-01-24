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
    int midval;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        priority_queue<int> n_left;
        priority_queue<int> n_right;
        
        left.swap(n_left);
        right.swap(n_right);

    }
    
    void addNum(int num) {
        
    }
    
    double findMedian() {
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */