#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct PS{
    int st;
    int pt;
    int idx;
    PS(int a, int b, int c): st(a),pt(b),idx(c){}
};

struct priority{
    bool operator()(PS a, PS b){
        return a.pt > b.pt;
    }
};

int solution(vector<vector<int>> jobs) {

    int init_size = jobs.size();
    int total_time = 0;
    priority_queue<PS, vector<PS>, priority> temp;
    int time=0;

    int cnt=0;
    while(!jobs.empty()){
        for(int i=0; i<jobs.size(); i++){
            if(jobs[i][0]<=time)
                temp.push(PS(jobs[i][0],jobs[i][1],i));
        }
        
        if(temp.size()==0)time++;
        else{
            time+= temp.top().pt;
            total_time+= time-temp.top().st;
            jobs.erase(jobs.begin()+ temp.top().index);
            while(!temp.empty())temp.pop();
        }
    }

	return (int)((float)total_time/(float)init_size);
}