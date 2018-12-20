#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
//5번 이동시 가장 큰 블록수 출력
int arr[21][21];
int n,res;
queue<int> q;
int searchbig(){
    int maxv=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            maxv=arr[i][j]>maxv ? arr[i][j] : maxv;
        }
    }
    return maxv;
}

void merge(int d)
{
    queue<int> q;
    int cnt = 0;
    switch (d){
 
    case 0://위
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (arr[j][i] != 0) q.push(arr[j][i]);
                arr[j][i] = 0;
            }
 
            int idx = 0;
            int pop_data;
 
            while (!q.empty()){
                pop_data = q.front();
                q.pop();
 
                if (arr[idx][i] == 0) arr[idx][i] = pop_data;
                else if (arr[idx][i] == pop_data){
                    arr[idx][i] *= 2;
                    idx++;
                }
                else arr[++idx][i] = pop_data;
            }
 
        }
        break;
    case 1://아래
        for (int i = 0; i < n; i++){
            for (int j = n - 1; j >= 0; j--){
                if (arr[j][i] != 0) q.push(arr[j][i]);
                arr[j][i] = 0;
            }
 
            int idx = n - 1;
            int pop_data;
 
            while (!q.empty()){
                pop_data = q.front();
                q.pop();
 
                if (arr[idx][i] == 0) arr[idx][i] = pop_data;
                else if (arr[idx][i] == pop_data){
                    arr[idx][i] *= 2;
                    idx--;
                }
                else arr[--idx][i] = pop_data;
            }
        }
        break;
    case 2://왼
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (arr[i][j] != 0) q.push(arr[i][j]);
                arr[i][j] = 0;
            }
 
            int idx = 0;
            int pop_data;
 
            while (!q.empty()){
                pop_data = q.front();
                q.pop();
 
                if (arr[i][idx] == 0) arr[i][idx] = pop_data;
                else if (arr[i][idx] == pop_data){
                    arr[i][idx] *= 2;
                    idx++;
                }
                else arr[i][++idx] = pop_data;
            }
 
        }
        break;
 
    case 3://오
        for (int i = 0; i < n; i++){
            for (int j = n - 1; j >= 0; j--){
                if (arr[i][j] != 0) q.push(arr[i][j]);
                arr[i][j] = 0;
            }
 
            int idx = n - 1;
            int pop_data;
 
            while (!q.empty()){
                pop_data = q.front();
                q.pop();
 
                if (arr[i][idx] == 0) arr[i][idx] = pop_data;
                else if (arr[i][idx] == pop_data){
                    arr[i][idx] *= 2;
                    idx--;
                }
                else arr[i][--idx] = pop_data;
            }
        }
        break;
 
 
    }
}

void bfs(int t){
    if(t==5){
        int cnt=searchbig();
        res= res<cnt ? cnt : res;
        return;
    }
    
    int tmp[21][21];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tmp[i][j]=arr[i][j];
        }
    }

    for(int k=0; k<4; k++){
        merge(k);
        bfs(t+1);    
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                arr[i][j]=tmp[i][j];
            }
        }
    }
    return;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    // n=3;
    // arr[0][0]=2;
    // arr[0][1]=64;
    // arr[0][2]=0;
    // arr[1][0]=0;
    // arr[1][1]=256;
    // arr[1][2]=1024;
    // arr[2][0]=1024;
    // arr[2][1]=16;
    // arr[2][2]=256;
    bfs(0);
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    cout<<res<<endl;
}



void moveleft(){
    //계산과 정렬
    for(int i=0; i<n; i++){
        vector<int> v;
        for(int j=0; j<n; j++){
            if(arr[i][j]!=0){
                if(v.empty())
                    v.push_back(arr[i][j]);
                else{
                    if(v.back()==arr[i][j]){
                        v.pop_back();
                        v.push_back(arr[i][j]+arr[i][j]);
                        //여러번 합쳐지는 케이스 생각못함
                    }
                    else if(v.back()!=arr[i][j]){
                        v.push_back(arr[i][j]);
                    }
                }    
            }
        }

        for(int j=0; j<n; j++){
            if(j>=v.size())
                arr[i][j]=0;
            else
                arr[i][j]=v[j];
        }
    }
}


void moveright(){
    //계산과 정렬
    for(int i=0; i<n; i++){
        vector<int> v;
        for(int j=n-1; j>=0; j--){
            if(arr[i][j]!=0){
                if(v.empty())
                    v.push_back(arr[i][j]);
                else{
                    if(v.back()==arr[i][j]){
                        v.pop_back();
                        v.push_back(arr[i][j]+arr[i][j]);
                    }
                    else if(v.back()!=arr[i][j]){
                        v.push_back(arr[i][j]);
                    }
                }    
            }
        }
        int cnt=0;
        for(int j=n-1; j>=0; j--){
            if(cnt>=v.size())
                arr[i][j]=0;
            else{
                arr[i][j]=v[cnt];
                cnt++;
            }
        }
    }
}

void moveup(){
    //계산과 정렬
    for(int i=0; i<n; i++){
        vector<int> v;
        for(int j=0; j<n; j++){
            if(arr[j][i]!=0){
                if(v.empty())
                    v.push_back(arr[j][i]);
                else{
                    if(v.back()==arr[j][i]){
                        v.pop_back();
                        v.push_back(arr[j][i]+arr[j][i]);
                    }
                    else if(v.back()!=arr[j][i]){
                        v.push_back(arr[j][i]);
                    }
                }    
            }
        }

        for(int j=0; j<n; j++){
            if(j>=v.size())
                arr[j][i]=0;
            else
                arr[j][i]=v[j];
        }
    }
}


void movedown(){
    //계산과 정렬
    for(int i=0; i<n; i++){
        vector<int> v;
        for(int j=n-1; j>=0; j--){
            if(arr[j][i]!=0){
                if(v.empty())
                    v.push_back(arr[j][i]);
                else{
                    if(v.back()==arr[j][i]){
                        v.pop_back();
                        v.push_back(arr[j][i]+arr[j][i]);
                    }
                    else if(v.back()!=arr[j][i]){
                        v.push_back(arr[j][i]);
                    }
                }    
            }
        }
        int cnt=0;
        for(int j=n-1; j>=0; j--){
            if(cnt>=v.size())
                arr[j][i]=0;
            else{
                arr[j][i]=v[cnt];
                cnt++;
            }
        }
    }
}



// d 0위 1오른쪽 2아래 3왼쪽
int count1=0;
