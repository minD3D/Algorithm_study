#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end());
    int pnt=people.size()-1;
    for(int i=0;; ){
        if(pnt<=i){
            answer++;
            break;
        }
        if(people[i]+people[pnt]<=limit){
            answer++;
            i++;
            if(i==pnt)
                break;
            pnt--;
        }
        else{
            answer++;
            pnt--;
        }
    }
    
    return answer;
}

int main(){
    vector<int> ppl = {2,5,5,5,7,8};
    cout<<solution(ppl,10);
}