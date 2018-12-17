#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main(){
    map <string,int> name_to_id;
    int arr[5][5][3];
    double score[5];
    int res[5];
    for(int i=0; i<4; i++){
        string a;
        cin>>a;
        name_to_id[a]=i;
        res[i]=0;
        score[i]=0;
    }
    
    for(int i=0; i<6; i++){
        string a,b;
        double w,d,l; 
        cin>>a>>b>>w>>d>>l;
        score[name_to_id[a]]+=d+w*3;
        score[name_to_id[b]]+=d+l*3;
    }
    vector<pair<float,int>> rank;
    for(int i=0; i<4; i++){
        rank.push_back(make_pair(score[i],i));        
    }
    sort(rank.begin(),rank.end());
    
    int cntf=1, cnts=0;
    float tmp=rank[3].first;
    for(int i=2; i>=0; i--){
        if(tmp==rank[i].first)
            cntf++;
    }
    if(cntf==1){
        tmp=rank[2].first;
        for(int i=2; i>=0; i--){
            if(tmp-rank[i].first==0)
                cnts++;
        }
    }
    if(cntf==1){
        res[rank[3].second]=1;
        if(cnts==1)
            res[rank[2].second]=1;
        if(cnts==2){
            res[rank[2].second]=2;
            res[rank[1].second]=2;
        }
        if(cnts==3){
            res[rank[2].second]=3;
            res[rank[1].second]=3;
            res[rank[0].second]=3;
        }
    }
    else{
        if(cntf==2){
            res[rank[3].second]=2;
            res[rank[2].second]=2;
        }
        if(cntf==3){
            res[rank[2].second]=3;
            res[rank[1].second]=3;
            res[rank[3].second]=3;
        }
        if(cntf==4){
            res[rank[0].second]=4;
            res[rank[2].second]=4;
            res[rank[1].second]=4;
            res[rank[3].second]=4;
        }
    }
    for(int i=0; i<4; i++){;
        if(res[i]==0)
            cout<<"0.0000000000"<<endl;
        if(res[i]==1)
            cout<<"1.0000000000"<<endl;
        if(res[i]==2)            
            cout<<"0.5000000000"<<endl;
        if(res[i]==3)
            cout<<"0.3333333333"<<endl;
        if(res[i]==4)
            cout<<"0.2500000000"<<endl;
    }
}

// KOR CCC 1.0   0.0   0.0
// AAA BBB 0.428 0.144 0.428
// AAA KOR 0.0   0.0   1.0
// CCC BBB 0.0   0.0   1.0
// KOR BBB 1.0   0.0   0.0
// CCC AAA 0.0   0.0   1.0

            1 2 3
            1 2 3
            1 2 3
            1 2 3
            1 2 3
            1 2 3



// K 3 3 3
// A 0.428*3 + 0.144*1 3
// B 0.428*3 + 0.144*1 3
// C 0