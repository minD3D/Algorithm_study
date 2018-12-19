#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> team;
//n명의 학생 학생수 짝수 
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        team.push_back(a);
    }
    sort(team.begin(),team.end());
    int cnt=0;
    for(int i=0; i<n; ){
        int a= team[i];
        int b= team[i+1];
        cnt+=b-a;
        i+=2;
    }
    cout<<cnt<<endl;
}
//길이 n 스트링 1-k까지의 