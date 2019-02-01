#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;
//How do you set recent used argument
//priority queue return smaller argument 

//Use case
//1. update recent used node
//2. when input node have to see if it's bigger than capacity
//3. if its big remove least used node

class LRUCache {
private:
    priority_queue<pair<int,int>> cq;
    map<int,int> cache;
    map<int,int> cache_time;
    int capa;
    int time;
    int num;
public:
    LRUCache(int capacity) {
        capa=capacity;
        cache.clear();
        priority_queue<pair<int,int>> nq;
        cq.swap(nq);
        time=0;
        num=0;
    }
    int get(int key) {
        // cout<<"k"<<key<<endl;
        time++;
        cout<<cache[key]<<endl;
        if(num==0)
            return -1;
        else if(cache[key]==0)
            return -1;
        else if(cache[key]!=-999999999){
            cache_time[key]=-1*time;
            cq.push(make_pair(-1*time,key));        
            return cache[key]; 
        }
        else
            return -1;       
    }
    
    void put(int key, int value) {
        time++;
        if(cache_time[key]==0){
            num++;
        }
        cq.push(make_pair(-1*time,key));        
        cache[key]=value;
        cache_time[key]=-1*time;
        
        if(num>capa){
            // cout<<"k"<<key<<endl;
            while(cq.top().first!=cache_time[cq.top().second]){
                cq.pop();
            }
            cout<<"d"<<cq.top().second<<cache[cq.top().second]<<endl;
            cache_time[cq.top().second]=-1;
            cache[cq.top().second]=-999999999;
            cq.pop();
            num-=1;
        }
    }
};



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */