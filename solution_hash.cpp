#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
//hash map 
//set

string solution(vector<string> participant, vector<string> completion) {
    map<string,int> m;
    for(int i=0; i<participant.size(); i++){
        m[participant[i]]++;
    }
    for(int i=0; i<completion.size(); i++){
        m[completion[i]]++;
    }

    map<string,int> ::iterator it;
    for(it=m.begin(); it!=m.end(); it++){
        int n=it->second;
        if(n%2==1){
            return it->first;
            break;
        }
    }
    return "";
}

int main(){
    vector<string> participant={"a","b","c"};
    vector<string> completion={"a","c"};
    cout<<solution(participant,completion)<<endl;
}