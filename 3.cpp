#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int n;
vector<pair<string,int>> arr;
vector<char> res;
//n명의 학생 학생수 짝수 
int main(){
    cin>>n;
    for(int i=0; i<2*n-2; i++){
        string a;
        cin>>a;
        arr.push_back(make_pair(a,i));
        res.push_back('a');
    }

    sort(arr.begin(),arr.end());
    cout<<endl;
    for(int i=0; i<arr.size()-1; i++){     
        if(arr[i].first==arr[i+1].first){
            res[arr[i].second]='P';
            res[arr[i+1].second]='S';
        }
        if(arr[i+1].first.find(arr[i].first)==0)
            res[arr[i].second]='P';
        else
            res[arr[i].second]='S';
    }
    for(int i=0; i<arr.size(); i++){     
        cout<<res[i]<<endl;
    }
}

// 5
// a
// a
// ab
// aba
// aba
// abab
// ba
// baba

// SPPSPSPS