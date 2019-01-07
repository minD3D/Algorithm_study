#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the runningMedian function below.
 */
vector<double> runningMedian(vector<int> a) {
    vector<double> res;
    priority_queue<int> left; 
    priority_queue<int> right;
    int ls=0,rs=0;
    double mid=0;

    for(int i=0; i<a.size(); i++){
        if(mid<=a[i])right.push(-1*a[i]);
        else left.push(a[i]);
        
        ls=left.size();
        rs=right.size();

        if(ls==rs){
            mid=(double)(left.top()+right.top()*-1)/2; 
        }
        else if(ls>rs){
            if(ls==rs+1)
                mid=left.top();
            else
            {
                right.push(left.top()*-1);
                left.pop();
                mid=(double)(left.top()+right.top()*-1)/2; 
            }
        }
        else if(ls<rs){
            if(ls+1==rs)
                mid=right.top()*-1;
            else
            {
                left.push(right.top()*-1);
                right.pop();
                mid=(double)(left.top()+right.top()*-1)/2; 
            }
        }
        res.push_back(mid);
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        int a_item;
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        a[a_itr] = a_item;
    }

    vector<double> result = runningMedian(a);

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
