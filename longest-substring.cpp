#include<iostream>
using namespace std;
int lengthOfLongestSubstring(string s){
        int ln = 0; 
        int st = 0;
        if(s.length()==0)
            return 0;
        if(s.length()==1)
            return 1;
            
        for(int i=0; i<s.length(); i++)
        {
            cout<<"i: "<<s[i]<<endl;

            for(int j=st; j<i; j++){
                cout<<"     j: "<<s[j]<<endl;
                if(s[i] == s[j]){
                    st = j+1;
                }
                ln = (j-st+2>ln) ? j-st+2 : ln;
                    cout<<"         l:"<<ln<<endl;
                
            }
            
        }
        
        return ln;
}

int main(){
    string s="duaeklamno";

    cout<<"return: "<<lengthOfLongestSubstring(s)<<endl;
    
}

    // class Solution {
    // public:
    //     int lengthOfLongestSubstring(string s) {
    //         int ln = 0; 
    //         for(int i=0; i<s.length(); i++)
    //         {
    //             char arr*;
    //             int st = 0;
    //             int ch = 1;
    //             for(int j=st; j<ch-1; j++){
    //                 if(s[i] == s[j]){
    //                     st = j+1;
    //                 } 
    //                 ln = (j-st+1>ln) ? j-st+1 : ln;
    //             }
    //         }
    //         return ln;
    //     }
    // };