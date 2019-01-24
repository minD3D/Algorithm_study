#include<map>
#include<vector>
#include<queue>
using namespace std;
//go from 0 to n
//do dfs or bfs and check visit
//when call dfs or bfs first add 1 to cnt
//if a edges are already visited check next one

class Solution {
private:
    map<int,vector<int> > graph; //save list of connected edges
    vector<bool> visited;
    int res;
public:
    void bfs(int e){ //O(n^2)
        res+=1;        
        queue<int> q;
        q.push(e); 
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            visited[cur]=true;
            for(int i=0; i<graph[cur].size(); i++){
                int tmp=graph[cur][i];
                if(!visited[tmp]){
                    q.push(tmp);
                }
            }
        }
        return;
    }
    int countComponents(int n, vector<pair<int, int> >& edges) {        
        res=0;
        for(int i=0; i<edges.size(); i++){//O(n)
            int e1=edges[i].first;
            int e2=edges[i].second;
            graph[e1].push_back(e2);
            graph[e2].push_back(e1);
        }
        visited.clear();
        visited.resize(n);
        for(int i=0; i<n; i++){//O(n)
            if(!visited[i])
                bfs(i);//O(n^2)
        }        
        return res;
    }
};

//O(n+n^3)

//Optimize 
//=> not good idea 
// I can't check if the graph connected later
class Solution {
private:
public:
    int countComponents(int n, vector<pair<int, int> >& edges) {        
        if(n==0)return 0;
        vector<map<int,bool>> connection;
        bool used[n];
        int unUsed=n;
        for(int i=0; i<edges.size(); i++){
            if(connection.size()==0){
                map<int,bool> tmp;
                tmp[edges[i].first]=true;
                tmp[edges[i].second]=true;
                
                used[edges[i].first]=true;
                used[edges[i].second]=true;
                unUsed-=2;

                connection.push_back(tmp);
            }
            else{
                bool input=false;
                for(int j=0; j<connection.size(); j++){
                    int e1=edges[i].first;
                    int e2=edges[i].second;
                    if(connection[j][e1]||connection[j][e2]){
                        connection[j][e1]=true;
                        connection[j][e2]=true;
                        if(!used[e1]){
                            used[e1]=true;
                            unUsed-=1;
                        }
                        if(!used[e2]){
                            used[e2]=true;
                            unUsed-=1;
                        }
                        input=true;
                        break;
                    }
                }
                if(!input){
                    map<int,bool> tmp;
                    tmp[edges[i].first]=true;
                    tmp[edges[i].second]=true;

                    used[edges[i].first]=true;
                    used[edges[i].second]=true;
                    unUsed-=2;

                    connection.push_back(tmp);
                }
            }
        }
        return connection.size()+unUsed;
    }
};

//Optimize with Union

class Solution {
vector<int> id;
public:
int find(int i) {
    while (i != id[i]) {//O(n)
        id[i] = id[id[i]]; // compression
        i = id[i];
    }
    return i;
}
void unions(int p, int q) {//O(2n)
    int x = find(p);
    int y = find(q);
    id[x] = y;
}
int countComponents(int n, vector<pair<int, int>>& edges) {
    id.resize(n);
    for (int i = 0; i < n; i++) {//O(n)
        id[i] = i;
    }
    int count = 0;
    for (const auto& edge: edges) {//O(n)
        int x = find(edge.first);//O(n)
        int y = find(edge.second);//O(n)
        if (x != y) {
            unions(edge.first, edge.second);//O(2n)
            count++;
        }
    }
    return n-count;
}
};

//O(4n^2+n)=O(n^2)