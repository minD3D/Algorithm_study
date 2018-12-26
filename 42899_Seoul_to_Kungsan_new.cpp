#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
vector<vector<int>> chache;

int max(int a, int b){
	if(a>b)return a;
	else return b;
}

int reculsive(int k,int n, int x, int t, vector<vector<int>> *travel){
	if(t>k)
		return -1000000000;
	if(x==n)
		return 0;
	if(chache[x][t]!=-1)
		return chache[x][t];
	
	chache[x][t] = max((*travel)[x-1][1]+reculsive(k,n,x+1,t+(*travel)[x-1][0],travel),(*travel)[x-1][3]+reculsive(k,n,x+1,t+(*travel)[x-1][2],travel));
	return chache[x][t];
}

int solution(int K, vector<vector<int>> travel) {
	int n= travel.size()+1;
	for(int i=0; i<n+1; i++){
		vector<int> a;
		for(int j=0; j<K+1; j++){
			a.push_back(-1);
		}
		chache.push_back(a);
	}
	return reculsive(K,n,1,0, &travel);
} 

int main(){
    cout<<solution(3000,{{1000, 2000, 300, 700}, {1100, 1900, 400, 900}, {900, 1800, 400, 700}, {1200, 2300, 500, 1200}})<<endl;
}
