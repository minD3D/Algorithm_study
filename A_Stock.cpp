#include <iostream>
using namespace std;
// Say you have an array for which the ith element is the price of a given stock on day i.
// If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Don't forget endpoint!
        if(prices.size()==0)
            return 0;
        
        int min=prices[0];
        int maxprofit=0;
        for(int i=1; i<prices.size(); i++){
            if(min>=prices[i]){
                min=prices[i];
            }else{
                int tmp=prices[i]-min;
                maxprofit=tmp>maxprofit ? tmp : maxprofit;
            }
        }
        return maxprofit;
    }
};