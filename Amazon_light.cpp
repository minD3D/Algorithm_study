#include <bits/stdc++.h>

using namespace std;
// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
vector<int> cellCompete(int* states, int days) 
{
    vector<int> res;
    vector<int> tmp;
    
    for(int i=0; i<8; i++){
        res.push_back(*(states+i));
        tmp.push_back(*(states+i));
    }
    
    
    while(days--){
        
        for(int i=0; i<8; i++){
            int add;    
            if(i==0){
                add=(res[1])%2;
                if(add==1)
                    tmp[i]=1;
                else
                    tmp[i]=0;
            }
            else if(i==7){
                add=(res[6])%2;
                if(add==1)
                    tmp[i]=1;
                else
                    tmp[i]=0;
            }
            else{
                add=(res[i-1]+res[i+1])%2;
                if(add==1)
                    tmp[i]=1;
                else
                    tmp[i]=0;
            }
        }
        res.swap(tmp);

    }
    
    // for(int i=0; i<8; i++){
    //     cout<<res[i];
    //     }
    //     cout<<endl;
        
    
    return res;
    // WRITE YOUR CODE HERE  
}
// FUNCTION SIGNATURE ENDS

int main(){
       int arr[8]={1,1,1,0,1,1,1,1};
    // int arr[8]={0,0,1,0,1,0,0,0};
    // int arr[8]={0,1,0,0,0,1,0,0};
    int* b=arr;
    cellCompete(b,2);
}