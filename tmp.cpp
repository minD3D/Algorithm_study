#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct Work {
	int call_time;
	int process_time;
	int index;
	Work(int x, int y, int i) : call_time(x), process_time(y), index(i) {} //구조체 생성자
};

struct cmp {
	bool operator()(Work a, Work b)
	{
		return a.process_time > b.process_time;
	}
}; // Work 비교연산자 정의

int solution(vector<vector<int>> jobs) {

	int init_size = jobs.size();
	int total_time = 0;
	priority_queue<Work, vector<Work>, cmp> temp;
	int time = 0;// 현재시점

	while (!jobs.empty()) { //모든 일이 끝날 때까지
		for (int i = 0; i < jobs.size(); i++)
		{
			if (jobs[i][0] <= time)
				temp.push(Work(jobs[i][0], jobs[i][1], i));
		}//현 시점에서 수행 가능한 일들을 모두 큐에 넣음

		if (temp.size() == 0) // 수행 가능한 일이 없을 경우
			time++;
		else {              // 수행 가능한 일이 있을 경우
			
			cout<<temp.top().process_time<<endl;
			time += temp.top().process_time; //현재 시간을 변경
			total_time += time - temp.top().call_time; // 완료시간 - 요청시간을 더함
			jobs.erase(jobs.begin() + temp.top().index);// 수행한 일을 벡터에서 제거함
			while (!temp.empty()) {
				temp.pop();
			}
			
		}
	}
	

	int answer =  (int)((float)total_time/(float)init_size);

	return answer;

}

int main(){
    vector<vector<int>> jobs ={{0,3},{1,9},{2,6}};
    cout<<solution(jobs);
}