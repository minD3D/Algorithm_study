
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string,int> pre; 
    sort(phone_book.begin(), phone_book.end());
    for(int i=0; i<phone_book.size(); i++){
       pre[phone_book[i]]=1; 
        for(int j=1; j<phone_book[i].length(); j++){
            string cut=phone_book[i].substr(0,j);
            if(pre[cut]==1)
                pre[cut]++;
        }
    }

    map<string,int>::iterator it;
    for(it=pre.begin(); it!=pre.end(); it++){
        if(it->second>1){
            return false;
        }
    }

    return answer;
}