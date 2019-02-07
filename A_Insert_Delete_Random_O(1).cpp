#include<string>
#include<vector>
#include<map>
using namespace std;
class RandomizedSet {
public:
    map<int,int> numberMap;
    vector<int> numbers;
    int total;
    /** Initialize your data structure here. */
    RandomizedSet() {
        numberMap.clear();
        numbers.clear();
        // numbers.push_back(0);
        total=0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(numberMap[val]==0){
            numberMap[val]=numbers.size();
            numbers.push_back(val);
            total+=1;
            return true;
        }
        
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(numberMap[val]>0){
            numbers.erase(numbers.begin()+numberMap[val]);
            numberMap[val]=0;
            total-=1;
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        map<int,bool>::iterator it;
        if(total==0)return 0;
        int rn=rand()%total;
        return numbers[rn];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */