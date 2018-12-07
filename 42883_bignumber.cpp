#include <iostream>
#include <string>
#include <vector>

using namespace std;
int m=0;

void makebinary(int n, int k, int cnt, int i, string selecs, string alls){
    //n개중 k개 고르기 cnt만큼 선택했고 현재 위치 i
    if(i==n&&cnt==k){
        int a = atoi(selecs.c_str());
        if(a>m)m=a;
        cout<<m<<endl;
        return;
    }
    else if(cnt>k||i>n)
        return;
    
    string tmp;
    tmp=selecs;
    
    tmp+=alls[i];
    i++;
    cnt++;
    makebinary(n,k,cnt,i,tmp,alls);
    
    tmp=selecs;
    cnt--;
    makebinary(n,k,cnt,i,tmp,alls);
}

string solution(string number, int k) {
    string answer = "";
    int l=number.size();
    makebinary(l,l-k,0,0,"",number);
    return to_string(m);
}

int main(){
    cout<<solution("1924",2);
}

//시간초과 
//뒷 숫자가 더 클때 삭제하는 방식으로 작은것은 지우고 큰것은 남기게 풀면 해결됨