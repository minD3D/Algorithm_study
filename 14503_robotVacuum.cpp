#include <iostream>
using namespace std;

int cur[3];
bool finished=false;
int n, m, r, c, d,res=0;
int pos[100][100];

void checkPos(int x, int y, int n, int cnt){
    cout<<"["<<x<<","<<y<<","<<n<<","<<cnt<<"]"<<endl;    
    if(cnt>=4){
        finished=true;
        return;
    }
    pos[x][y]=false;
    if(n==0){
        if(pos[x][y-1]){
            res++;
            cur[0]=x;
            cur[1]=y-1;
            cur[2]=3;
            checkPos(cur[0],cur[1],cur[2],0);
            return;
        }
        else{
            cnt++;
            checkPos(x,y,3,cnt);
        }
    }
    if(n==1){
        if(pos[x-1][y]){
            res++;            
            cur[0]=x-1;
            cur[1]=y;
            cur[2]=0;
            checkPos(cur[0],cur[1],cur[2],0);
            return;
        
        }
        else{
            cnt++;
            checkPos(x,y,0,cnt);
        }
    }
    if(n==2){
        if(pos[x][y+1]){
            res++;            
            cur[0]=x;
            cur[1]=y+1;
            cur[2]=1;
            checkPos(cur[0],cur[1],cur[2],0);
            return;
        }
        else{
            cnt++;
            checkPos(x,y,1,cnt);
        }
    }
    if(n==3){
        if(pos[x+1][y]){
            res++;            
            cur[0]=x+1;
            cur[1]=y;
            cur[2]=2;
            checkPos(cur[0],cur[1],cur[2],0);
            return;
        }
        else{
            cnt++;
            checkPos(x,y,2,cnt);
        }
    }
    return;
}

int main() {
    cin >> n >> m;
    cin >> r >> c >> d;
    int map[n][m];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int a;
            cin>>a;
            map[i][j]=a;
            if(a==1)
                pos[i][j]=2;
            if(a==0)
                pos[i][j]=0;
        }
    }

    cur[0]=r;
    cur[1]=c;
    cur[2]=d;
    pos[r][c]=1;
    checkPos(r,c,d,0);
    cout<<"res"<<res<<endl;
    return 0;
}
