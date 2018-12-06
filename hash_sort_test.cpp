#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;


int main(){
    vector<string> genres={"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays={500, 600, 150, 800, 2500};	

    map <int, string> m;
    m[2]="이";
    m[1]="일";
    m[3]="삼";

    map<int, string> ::iterator it;
    
    for(it=m.begin(); it!=m.end(); it++){
        cout<<it->second<<endl;
    }
    
}

// 결과 :
// 일
// 이
// 삼
// 인덱스 정렬순으로 프린트된다