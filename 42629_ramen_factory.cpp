#include <iostream>
#include <string>
#include <queue>
using namespace std;


int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer=0;
    int st=0;
    int maxi=-1, maxstock=stock;
    priority_queue<int> pq;
    while(stock<k){
        for(int i=st; i< dates.size(); i++){
            if(dates[i]<=stock){
                pq.push(supplies[i]);
            }
            else{
                st=i;
                break;
            }
        }
        stock+=pq.top();
        pq.pop();
        answer++;
    }

    return answer;
}