#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    int a;
    cin>>a;
    a=1000-a;
    int arr[]={500,100,50,10,5,1};
    int cnt=0;
    for(int i=0; i<6; i++){
        while(a>=arr[i]){
            if((a-arr[i])>=0){
                // cout<<arr[i]<<endl;
                a-=arr[i];
                cnt++;
            }
            if(a==0)break;
        }
        if(a==0)break;
    }
    cout<<cnt<<endl;
}
