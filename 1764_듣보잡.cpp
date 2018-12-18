#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int n,m;

int main(){
    cin>>n>>m;
    vector<string> db;
    map<string,int> dbcnt;
    for(int i=0; i<n; i++){
        string a;
        cin>>a;
        dbcnt[a]+=1;
    }
    int cnt=0;
    for(int j=0; j<m; j++){
        string a;
        cin>>a;
        if(dbcnt[a]>0){
            dbcnt[a]-=1;
            db.push_back(a); 
            cnt++;
        }  
    }
    
    sort(db.begin(),db.end());
    
    cout<<cnt<<endl;
    for(int j=0; j<db.size(); j++){
        cout<<db[j]<<endl;
    }
}
