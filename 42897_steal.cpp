#include <iostream>
#include <string>
#include <vector>

using namespace std;
int max(int a, int b){
    if(a>b)return a;
    else return b;
}

int solution(vector<int> money) {
    int res;
    int fv=money[0];
    money[0]=0;
    vector<bool> isf;
    
    // 0,1,2 
    isf.push_back(true);
    isf.push_back(false);
    isf.push_back(true);
 
    for(int i=3;i<money.size(); i++){
        int a,b;
        isf.push_back(false);
        if(i==money.size()-1){
            a=money[i-2]+money[i];
            b=money[i-3]+money[i];

            if(isf[i-3]&&a<b)
                b=money[i-3]+max(money[i],fv);            
            if(isf[i-2]&&a>b)
                a=money[i-2]+max(money[i],fv);
            
            money[i]=max(a,b);
        }
        else{
            a=money[i-2]+money[i];
            b=money[i-3]+money[i];
            if(isf[i-3]&&a<b)
                isf[i]=true;
            if(isf[i-2]&&a>b)
                isf[i]=true;
            money[i]=max(a,b);
        }
    }

    // for(int i=0; i<money.size(); i++){
    //     cout<<money[i]<<endl;
    // }
    // cout<<endl;
    if(money.size()==3)
        return max(max(fv,money[1]),money[2]);
    else{
        return max(money[money.size()-1],money[money.size()-2]+fv);
    }
}

int main(){
    cout<<solution({1,2,3,1,4});
}