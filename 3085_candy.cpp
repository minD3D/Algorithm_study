#include <iostream>
#include <string>
#include <vector>
using namespace std;    
int n;

vector<string> arr;
int mv=0;

int countbig(int i, int j, vector<string> inarr){
    char now=inarr[i][j];
    int v=1,h=1;
    int a=i,b=j;
    while(1){
        if(a<=0)
            break;
        if(now==inarr[a-1][b]){
            v++;
        }
        else break;
        a--;
    }
    a=i,b=j;
    while(1){
        if(a>=n-1)
            break;
        if(now==inarr[a+1][b])
        {    v++;
        }
        else break;
        a++;
    }

    a=i,b=j;
    while(1){
        if(b<=0)
            break;
        if(now==inarr[a][b-1])
        {    h++;
        }
        else break;
        b--;
    }
    a=i,b=j;
    while(1){
        if(b>=n-1)
            break;
        if(now==inarr[a][b+1])
        {    h++;

        }
        else break;
        b++;
    }    
    int res = v>h ? v : h;
    mv= res>mv ? res : mv;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        string a;
        cin>>a;
        arr.push_back(a);
    }
    //try all the case of right side and downside swap
    int max=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=n-1){//상하
                char tmp=arr[i][j];
                arr[i][j]=arr[i+1][j];
                arr[i+1][j]=tmp;
                countbig(i,j,arr);
                countbig(i+1,j,arr);
                tmp=arr[i][j];
                arr[i][j]=arr[i+1][j];
                arr[i+1][j]=tmp;
            }
            if(j!=n-1){//좌우
                char tmp=arr[i][j];
                arr[i][j]=arr[i][j+1];
                arr[i][j+1]=tmp;
                countbig(i,j,arr);
                countbig(i,j+1,arr);
                tmp=arr[i][j];
                arr[i][j]=arr[i][j+1];
                arr[i][j+1]=tmp;                
            } 
        }
    }
    cout<<mv;
}