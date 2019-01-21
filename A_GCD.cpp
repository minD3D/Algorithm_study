#include <bits/stdc++.h>

using namespace std;
// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
int generalizedGCD(int num, int* arr)
{
    int max_num_in_arr=0;
    int min_num_in_arr=2100000000;
    
    vector<int> list;
    vector<int> prime_list;
    //1. set vector list and find maximum and minimun number
    for(int i=0 ; i< num ; i++){
        list.push_back(*(arr+i));
        cout<<list[i]<<endl;

        max_num_in_arr= *(arr+i) > max_num_in_arr ? *(arr+i) : max_num_in_arr;
        min_num_in_arr= *(arr+i) < min_num_in_arr ? *(arr+i) : min_num_in_arr;
    }
    cout<<max_num_in_arr<<"/"<<min_num_in_arr<<endl;
    
    //2. check if the minimun nuber is GCD
    bool isFin=false;
    for(int i=0 ; i< num ; i++){
        if(isFin)break;
        if(list[i]%min_num_in_arr!=0)
            isFin=true;
    }
    //return if the minimun nuber is GCD
    if(!isFin)return min_num_in_arr;
    
    //3. find prime number /smaller than maximum number from arr
    for(int i=1; i<max_num_in_arr; i++){
        if(prime_list.empty())
            prime_list.push_back(i);
        else{
            //use isfin for check if it prime num
            isFin=false;
            for(int j=1; j<prime_list.size(); j++){
                if(isFin)break;
                if(i%prime_list[j]==0)
                    isFin=true;
                else
                    prime_list.push_back(i);
            }
        }
    }
    //4. check from bigger prime number
    for(int i=prime_list.size()-1; i>0; i--){
        isFin=false;
        for(int j=0; j<list.size(); j++){
            if(isFin)break;
            if(list[j]%i!=0)
                isFin=true;
        }
        if(!isFin)return i;
    }    
    
    return 1;
}
// FUNCTION SIGNATURE ENDS

int main(){
    int arr[8]={0,1,1,1,1};
    int* b=arr;
    cout<<generalizedGCD(5,b);
}
