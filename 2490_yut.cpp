#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    int a=3;
    int cnt=0;
    while(a--){
        cnt=0;
        int b;
        cin>>b;
        if(b)cnt++;
        cin>>b;
        if(b)cnt++;
        cin>>b;
        if(b)cnt++;
        cin>>b;
        if(b)cnt++;
        
        switch(cnt){
            case 0:
                cout<<"D"<<endl;
                break;
            case 1:
                cout<<"C"<<endl;
                break;
            case 2:
                cout<<"B"<<endl;
                break;
            case 3:
                cout<<"A"<<endl;
                break;
            case 4:
                cout<<"E"<<endl;
                break;
        }
        // 0000D
        // 1000C
        // 1100B
        // 1110A
        // 1111E
    }
}
