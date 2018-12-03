#include<iostream>
#include<vector>
using namespace std;
#define INF 100000000

int fin=INF;
int calculateChickenDis(vector<pair<int,int>> home, vector<pair<int,int>> chi, vector<int> flag){
    int sum=0;
    for(int i=0; i<home.size(); i++){
        int dis=INF;
        for(int j=0; j<flag.size(); j++){
            int tmp=abs(home[i].first-chi[flag[j]].first)+abs(home[i].second-chi[flag[j]].second);
            dis=(tmp<dis) ? tmp : dis;
        }
        sum+=dis;
    }
    return sum;
}

int combination(vector<pair<int,int>> home, vector<pair<int,int>> chi, int flag[], int length, int n, int r)
{
    if( n == r ){
        int i;
        for(i=0;i<n;i++){
            flag[i] = 1;
        }
        vector<int> arr;
        for(i=0;i<length;i++){
            if( flag[i] == 1 )arr.push_back(i);
        }
        fin=(calculateChickenDis(home, chi, arr)<fin)? calculateChickenDis(home, chi, arr) : fin;
        cout<<fin<<endl;
        for(i=0;i<n;i++){
            flag[i] = 0;
        }
        return 0;
    }
    if( r==1 ){
        int i,j;
        for(i=0;i<n;i++){
            flag[i] = 1;
            vector<int> arr;
            for(j=0;j<length;j++){
                if( flag[j] == 1 )arr.push_back(j);
            }
            fin=(calculateChickenDis(home, chi, arr)<fin)? calculateChickenDis(home, chi, arr) : fin;
            cout<<fin<<endl;            
            flag[i] = 0;
        }
        return 0;
    }

    flag[n-1]=1;
    combination(home, chi, flag, length,n-1,r-1);
    flag[n-1]=0;
    combination(home, chi, flag, length,n-1,r);
}

int main(){
    
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>>chi;
    vector<pair<int,int>>home;
    int chisize=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int a;
            cin>> a;
            if(a==1)
                home.push_back(make_pair(i,j));
            if(a==2){
                chi.push_back(make_pair(i,j));
                chisize++;            
            }
        }    
    }
    int flag[chisize];
    
    combination(home, chi, flag, chisize, chisize, m);
    cout<<fin;
    return 0;
}
