#include <string>
#include <vector>
//participant를 처음부터 끝까지 돌며 completion에 같은 이름이 있을 경우마다 제거했습니다.
using namespace std;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for(int i = 0; i < participant.size(); i++)
    {
        for(int j = 0; j<completion.size(); j++)
        {
            if(completion.empty())//completion이 비었으면
            {
                answer = participant[i];
                return answer; //현재이름을 반환
            }
            if(participant[i] == completion[j]) //같은 이름을 찾으면
            {
                completion.erase(completion.begin()+j); //이름을 삭제
                break;
            }
            else{
                if(j == completion.size()-1)  //마지막까지 completion에 일치하는 이름이 없으면
                {
                    answer = participant[i];
                    return answer; //현재이름 반환
                }
            }
        }
    }
}