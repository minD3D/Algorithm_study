#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    bool find=false;
    for(int j=0; j<participant.size(); j++){
        string a=participant.back();
        participant.pop_back();
        find=false;
        for(int i=0; i<completion.size(); i++){
                if(completion[i]==a){
                    find=true;
                    completion.erase(completion.begin()+i);
                    break;
                }
        }
        if(!find)return a;
    }
    
    return "";
}