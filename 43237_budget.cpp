#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    sort(budgets.begin(),budgets.end());
    int sum=0;
    int s= budgets.size();
    for(int i=0; i<s; i++){
        sum+=budgets[i];
    }
    if(sum<=M)
        return budgets[s-1];
    else{
        int left=0;
        int right=budgets[s-1];
        int mid=0;
        while(left+1<right){
            mid=(left+right)/2;
            sum=0;
            for(int i=0; i<s; i++){
                if(budgets[i]<mid)
                    sum+=budgets[i];
                else
                    sum+=mid;
            }
            if(sum<=M)
                left=mid;
            else   
                right=mid;
        }
        return left;
    }
}
int main(){
    cout<<solution({120,110,140,150},485);
}
