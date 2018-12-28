#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int check(vector<int> *budgets, int M, int n){
    int sum=0;
    for(int i=0; i<(*budgets).size(); i++){
        if((*budgets)[i]<=n)
            sum+=(*budgets)[i];
        else
            sum+=n;
    }
    if(sum<=M)
        return sum;
    else
        return -1;
}

int solution(vector<int> budgets, int M) {
    int answer = 0;
    sort(budgets.begin(),budgets.end());

    int s= budgets.size();
    int a=(M/s);
    int b=budgets[s-1];
    int i= (a+b)/2;
    while(1){
        if(a==b)break;
        int tmp=check(&budgets,M,i);
        if(tmp>answer){
            answer=tmp;
            a=i;
        }
        else{
            b=i;
        }
        i=(a+b)/2;
    }
    // cout<<M-sum<<s-a;
    return answer;
}
int main(){
    cout<<solution({120,110,140,150},485);
}


// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm>

// using namespace std;

// int solution(vector<int> budgets, int M) {
//     int answer = 0;
//     sort(budgets.begin(),budgets.end());
//     int a=0;
//     int sum=0;
//     int s= budgets.size();
//     for(int i=0; i<s; i++){
//         if(budgets[i]*s>M){
//             if(i==0)
//                 answer=M/s;
//             else
//                 a=i-1;
//         }else{
//             sum+=budgets[i];
//         }
//     }

//     // cout<<M-sum<<s-a;
//     answer=(M-sum)/(s-a);
//     return answer;
// }