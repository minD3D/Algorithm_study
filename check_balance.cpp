#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='['||s[i]=='('||s[i]=='{')
            st.push(s[i]);
        else{
            char tmp = st.top();
            st.pop();
            if(tmp!='['&&s[i]==']')
              return "NO";
            else if(tmp!='{'&&s[i]==')')
              return "NO";
            else if(tmp!='('&&s[i]=='}')
              return "NO";
        }
    }
    return "YES";
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
