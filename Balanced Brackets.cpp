#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char> st;
    bool isbal=true;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='['||s[i]=='{'||s[i]=='(')
            st.push(s[i]);
        else{
            char tmp;
            if(st.empty()){
                isbal=false;
                tmp='.';
            }
            else
                tmp=st.top();

            if(s[i]==']'){
                if(tmp=='[')
                    st.pop();
                else
                    isbal=false;
            }
            if(s[i]==')'){
                if(tmp=='(')
                    st.pop();
                else
                    isbal=false;
            }
            if(s[i]=='}'){
                if(tmp=='{')
                    st.pop();
                else
                    isbal=false;
            }
        }
    }
    if(!st.empty())isbal=false;
    
    if(isbal)return "YES";
    else return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
