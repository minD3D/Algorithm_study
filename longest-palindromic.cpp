#include<iostream>
#include<string>
using namespace std;
//make a function and consider two center way
string longestPalindrome(string s) {
    int sl=s.length();
    int longest=0;
    string result="";

    if(sl==0)return "";
    if(sl==1)return s;
    if(sl==2){
        if(s[0]==s[1])
            return s;
        else{
            result=result+s[0];
            return result;    
        }   
    }
    for(int i=0; i<sl-1; i++){
        int a=findLong(s,i,i+1);
        int b=findLong(s,i,i);
        if(a>b)
            return 
    }
    cout<<rs<<","<<re<<endl;
    return s.substring(rs,re);
    // cout<<s[rs]<<"~"<<s[re]<<endl;
}
int findLong(string s, int l, int r){
    while(l>=0&&r<s.length()&&s[l]==s[r]){
        l--;
        r++;
    }
    return
}
int main(){
    string s="aaaa";
    cout<<longestPalindrome(s)<<endl;
    
}
