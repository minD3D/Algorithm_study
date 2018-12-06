#include <iostream>
#include <vector>
using namespace std;
int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = 0, i;
	int arr[32];
	for (i = 0; i <= n+1; i++)
		arr[i] = 0;
	for (i = 0; i < lost.size(); i++)
		arr[lost[i]]--;
	for (i = 0; i < reserve.size(); i++)
		arr[reserve[i]]++;
	for (i = 0; i < lost.size(); i++)
	{
		if (arr[lost[i]] != -1)
			continue;
		if (arr[lost[i] - 1] == 1)
		{
			arr[lost[i]] = 0;
			arr[lost[i] - 1] = 0;
			continue;
		}
		if (arr[lost[i] + 1] == 1)
		{
			arr[lost[i]] = 0;
			arr[lost[i] + 1] = 0;
		}
	}
	for (i = 1; i <= n; i++)
		if (arr[i] != -1)
			answer++;
	return answer;
}
