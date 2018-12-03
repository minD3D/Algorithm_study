#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> data;
    int ps;
    int pe;
    bool full;
    bool empty;
    int size;
    int insize;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.assign(k,-1);
        ps=0;
        pe=0;
        full=false;
        empty=true;
        size=k;
        insize=0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(full)
            return false;
        data[pe]=value;
        insize++;
        if(pe+1==size-1)
            pe=0;
        else
            pe++;
        empty=false;
        
        if(insize==size)full=true;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(empty)
            return false;
        if(ps+1==size-1)
            ps=0;
        else 
            ps++;
        insize--;
        full=false;
        if(insize==0)
            empty=true;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(empty)
            return false;
        return data[ps];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(empty)
            return false;
        if(pe==0)
            return data[size-1]; 
        return data[pe-1];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return empty;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return full;
    }
};


class MyQueue {
    private:
        // store elements
        vector<int> data;       
        // a pointer to indicate the start position
        int p_start;            
    public:
        MyQueue() {p_start = 0;}
        /** Insert an element into the queue. Return true if the operation is successful. */
        bool enQueue(int x) {
            data.push_back(x);
            return true;
        }
        /** Delete an element from the queue. Return true if the operation is successful. */
        bool deQueue() {
            if (isEmpty()) {
                return false;
            }
            p_start++;
            return true;
        };
        /** Get the front item from the queue. */
        int Front() {
            return data[p_start];
        };
        /** Checks whether the queue is empty or not. */
        bool isEmpty()  {
            return p_start >= data.size();
        }
};

int main() {
    // ["MyCircularQueue","enQueue","deQueue","Front","deQueue","Front","Rear","enQueue","isFull","deQueue","Rear","enQueue"]
    // [[3],[7],[],[],[],[],[],[0],[],[],[],[3]]
    // Output:
    // [null,true,true,-1,false,-1,7,true,false,true,0,true]
    // Expected:
    // [null,true,true,-1,false,-1,-1,true,false,true,-1,true]
    
    MyCircularQueue q(3);
    cout<<q.enQueue(7)<<endl;
    cout<<q.deQueue()<<endl;
        cout << q.Front() << endl;
    cout<<q.deQueue()<<endl;
        cout << q.Front() << endl;
    cout<<q.deQueue()<<endl;
        cout << q.Rear() << endl;
    cout<<q.enQueue(0)<<endl;
    cout<<q.isFull()<<endl;
    cout<<q.deQueue()<<endl;
        cout << q.Rear() << endl;
    cout<<q.enQueue(3)<<endl;
}