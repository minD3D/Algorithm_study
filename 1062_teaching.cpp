#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int n,k;
vector<char> used;
map <char,int> usedmap;
bool usedset[26];
vector<char> input[51];
string st="anta", ed="tica";
bool check=true;
int mn=0;

int checkInclude(){
    map <char,int> set;
    int tmp=0;
    for(int i=0; i<k-5; i++){
        if(usedset[i]){
            set[used[i]]=1;
        }
    }
    for(int i=0; i<n; i++){
        bool isin= true;
        for(int j=0; j<input[i].size(); j++){
            if(set[input[i][j]]!=1){
                isin=false;
            }
        }
        if(isin){
            tmp++;
        }
    }
    mn = tmp>mn ? tmp : mn;
}

int makeset(int cnt, int index){//select b out of a
    if(cnt==k-5){
        checkInclude();
    }
    if(cnt<k-5){
        for(int i=index; i<=used.size(); i++){
            usedset[i]=true;
            makeset(cnt+1,i+1);
            usedset[i]=false;                
        }
    }

}

int main(){
    cin>>n>>k;
    for(int j=0; j<n; j++){
        string a="";
        cin>>a;
        for(int i=0; i<a.size(); i++){
            char b=a[i];
            if(b!='a'&&b!='n'&&b!='t'&&b!='i'&&b!='c')
            {
                if(usedmap[b]!=1){
                    used.push_back(b);
                    usedmap[b]=1;
                }
                input[j].push_back(b);
            }    
        }
    }
    // map<char, int> ::iterator it;
    if(used.size()<=k-5)
        cout<<n<<endl;
    else{
        makeset(0,0);
        cout<<mn<<endl;
    }  
}
