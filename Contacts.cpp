#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the contacts function below.
 */
vector<int> contacts(vector<vector<string>> queries) {
    map<string,int> cnt_contact;
    vector<int> res;
    for(int i=0; i<queries.size(); i++){
        if(queries[i][0]=="add"){
            string tmp="";
            for(int j=0; j<queries[i][1].length(); j++){
                tmp+=queries[i][1][j];
                cnt_contact[tmp]+=1;
            }
        }
        if(queries[i][0]=="find"){
            res.push_back(cnt_contact[queries[i][1]]);
        }
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int queries_rows;
    cin >> queries_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<string>> queries(queries_rows);
    for (int queries_row_itr = 0; queries_row_itr < queries_rows; queries_row_itr++) {
        queries[queries_row_itr].resize(2);

        for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
            cin >> queries[queries_row_itr][queries_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = contacts(queries);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
