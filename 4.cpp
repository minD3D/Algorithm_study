#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n;
vector<long> arr;
//n명의 학생 학생수 짝수 
int main(){
    cin>>n;
    bool is3=false;
    int maxh=0;
    while(n--){
        long a;
        cin>>a;
        arr.push_back(a);
        maxh= a>maxh ? a: maxh;
    }
    bool iskeep=true;

    while(1){
        iskeep=false;        
        for(int i=0; i<arr.size()-1; ){
            if(arr[i]<maxh&& arr[i]==arr[i+1])
            {   
                // cout<<i<<","<<i+1<<"->"<<arr[i]+1<<endl;
                arr[i]+=1;
                arr[i+1]+=1;   
                iskeep=true;
                i=0;
                // for(int j=0; j<arr.size(); j++){
                //     cout<<arr[j];
                // }
                // cout<<endl;
                
            }
            else
                i++;
        }
        if(!iskeep)break;
        
        iskeep=false;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]!=maxh)
                iskeep=true;
                iskeep=true;
        }
        if(!iskeep)break;
    }

    iskeep=true;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]!=maxh)
            iskeep=false;
    }
    if(iskeep)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
}

// 5
// ba
// a
// abab
// a
// aba
// baba
// ab
// aba

// SPPSPSPS