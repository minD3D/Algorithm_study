#include <vector>
#include <map>
#include <queue>
#include <list>
#include <iostream>

using namespace std;

class LRUCache {
    map<int, list<pair<int,int>>::iterator> cache;
    int m_capacity;
    list<pair<int,int>> list;
public:
    LRUCache(int capacity) {
        m_capacity=capacity;
    }
    int get(int key) {
        auto found_iter = cache.find(key);
        if(found_iter==cache.end())
            return -1;
        list.splice(list.begin(),list, found_iter->second);
        return found_iter->second->second;
    }
    
    void put(int key, int value) {
        auto found_iter = cache.find(key);
        if(found_iter!=cache.end()){
            list.splice(list.begin(),list, found_iter->second);
            found_iter->second->second=value;
            return;
        }
        if(cache.size()==m_capacity){
            int key_to_del = list.back().first;
            list.pop_back();
            cache.erase(key_to_del);
        }
        list.emplace_front(key,value);
        cache[key]=list.begin();
    }
};



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */