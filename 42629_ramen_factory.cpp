#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int i=0;
    int maxi=i;
    int maxdate=stock;
    bool isused[20000];
    while(stock<k-1){
        while(stock>=dates[i]){
            if(i==dates.size()-1)break;
            if(maxdate<stock+supplies[i]){
                maxi=i;
                maxdate=stock+supplies[i];
            } 
            i++;
        }
        cout<<i;

        if(stock+supplies[i]<maxdate&&!isused[maxi]){
            stock=maxdate;
            maxdate=0;
            isused[maxi]=true;
        
        }
        else{
            isused[i]=true;
            stock=stock+supplies[i];
        }
        cout<<stock<<endl<<endl;
        answer++;
    }
    return answer; 
}

int main(){
       vector<int> dates={1,2,3,4,5};
    vector<int> supplies={3,1,1,1,1};
    cout<<solution(1, dates, supplies, 6)<<endl;//k=6이면 5까지만 있음돼
}
