#include <iostream>
#include <vector>
#include <stack>

using namespace std;
bool isValid(string s) {
    stack<char> stk;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{'){
        stk.push(s[i]);
        }
        if(s[i]==')'){
            if(stk.top()=='(')
                stk.pop();
            else
                return false;
                
        }
        if(s[i]==']'){
            if(stk.top()=='[')
                stk.pop();
            else
                return false;
            
        }
        if(s[i]=='}'){
            if(stk.top()=='{'){
                stk.pop();
            }
            else
                return false;
            
        }
    }
    return true;
}

int main(){
    cout<<isValid("{[]}")<<endl;
}
