#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;


int solution(string name) {
    int answer = 0;
    map<char,int> alpa={{'A',0},{'B',2},{'C',3},{'D',4},{'E',5},{'F',6},{'G',7},{'H',8},{'I',9},{'J',10},{'K',11},{'L',12},{'M',13},{'N',14},{'O',15},{'P',16},{'Q',17},{'R',18},{'S',19},{'T',20},{'U',21},{'V',22},{'W',23},{'X',24},{'Y',25},{'Z',26}};
    int l=name.length(); //문자길이
    bool pos[21]; //바꿔야되는 문자 저장
    int num=0; //바꿔야되는 문자 수
    
    //바꿔야되는 문자 위치 초기화
    for(int i=0; i<l; i++){
        if(name[i]!='A'){
            pos[i]=true;
            num++;
        }
        else
            pos[i]=false;
    }

    //1. 가까운 처리위치 탐색
    //2. 가까운 알파벳 접근 찾기
    int cur=0;
    while(num!=0){
        if(pos[cur]){
            if(alpa[name[cur]]<=14)
                answer+=alpa[name[cur]]-1;
            else
                answer+=(27-alpa[name[cur]]);
            pos[cur]=false;
            num--;
            if(!num)break;
        }
        int rm=0,lm=0,rcurtmp=cur,lcurtmp=cur;
            while(1){
                if(pos[rcurtmp])
                    break;
                rm++;
                if(rcurtmp==l-1)
                    rcurtmp=0;
                else
                    rcurtmp++;
            }
            while(1){
                if(pos[lcurtmp])
                    break;
                lm++;
                if(lcurtmp==0)
                    lcurtmp=l-1;
                else
                    lcurtmp--;
            }
            answer+= rm>=lm ? lm : rm ;
            cur =  rm>=lm ? lcurtmp : rcurtmp;
    }
    return answer;
}

int main(){
    solution("ABC");
}

