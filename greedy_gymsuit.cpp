#include <iostream>
#include <string>
#include <vector>

using namespace std;
int mv=0;
void borrowsuit(int n, int* arr, int i){
    if(i==n+2)return;
    int cnt=0;
    for(int j=1; j<n+1; j++){
        if(arr[j]==0||arr[j]==1)
            cnt++;
    }
    cout<<cnt<<endl;
    mv = (cnt > mv) ? cnt : mv;
    i++;
    if(arr[i]==-1){
        if(arr[i-1]==1&&arr[i+1]==1){
            arr[i-1]=0;
            arr[i]=0;
            borrowsuit(n,arr,i);
            arr[i-1]=1;
            arr[i+1]=0;
            arr[i]=0;
            borrowsuit(n,arr,i); 
        }
        else if(arr[i-1]==1){
            arr[i-1]=0;
            arr[i]=0;
            borrowsuit(n,arr,i);
        }
        else if(arr[i+1]==1){
            arr[i+1]=0;
            arr[i]=0;
            borrowsuit(n,arr,i);
        }
    }
    else{
        borrowsuit(n,arr,i);
    }
    // cout<<arr[i]<<endl;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int table[n+1];
    mv=n;
    for(int i=0; i<lost.size(); i++){
        table[lost[i]]=-1;
        mv--;
    }
    for(int i=0; i<reserve.size(); i++){
        table[reserve[i]]=1;
    }
    
    borrowsuit(n,table,1);
    return mv;
}

int main(){
    vector<int> lost={3,5};
    vector<int> reserve={2,6};
    cout<<solution(6,lost,reserve)<<endl;
}