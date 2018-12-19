#include <iostream>
#include <string>
#include <queue>
#include <functional>
using namespace std;


int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0; i<jobs.size(); i++){
        pq.push(make_pair(jobs[i][0]+jobs[i][1], i));   
    }

    int wait=0;
    int now=0;
    while(!pq.empty()){
        int idx=pq.top().second;
        // cout<<idx<<endl;
        pq.pop();
        while(now<jobs[idx][0]){
            now++;
        }
        now+=jobs[idx][1];        
        wait+=now-jobs[idx][0];
    }
    return wait/jobs.size();
}

int main(){
    vector<vector<int>> jobs ={{0,3},{1,9},{2,6}};
    cout<<solution(jobs);
}

//0 3 
//1 10
//2 8