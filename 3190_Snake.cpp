#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int n,k,l,res;
int board[101][101]={0,};
queue<int> sec;
queue<char>side;
queue<pair<int,int>>snake;
int curdir=1;//1 x+1, 2 y+1, 3 x-1, 4 y-1

int checkDir(char n){
    if(n=='D'){
        if(curdir==4)curdir=1;
        else curdir++;
    }
    if(n=='L'){
        if(curdir==1)curdir=4;
        else curdir--;
    }
    return 0;
}

void setcur(int r,int c, int s){
    cout << endl;    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
    if(r==0||c==0||r>=n+1||c>=n+1||board[r][c]==2){
        res=s;
        // cout<<"ret"<<endl;
        return;
    }
    else{
        // cout<<r<<","<<c<<endl;
        if(board[r][c]==1){
            board[r][c]=2;
        }
        if(board[r][c]==0){
            board[r][c]=2;
            board[snake.front().first][snake.front().second]=0;
            snake.pop();
        }
        snake.push(make_pair(r,c));

        if(sec.front()==s){
            checkDir(side.front());
            sec.pop();
            side.pop();
        }
        s++;
        if(curdir==1)setcur(r,c+1,s);
        else if(curdir==2)setcur(r+1,c,s);
        else if(curdir==3)setcur(r,c-1,s);
        else if(curdir==4)setcur(r-1,c,s);
    }
    return;
}

int main(){
    cin>>n>>k; 
    while(k--){
        int a,b;
        cin>>a>>b;
        board[a][b]=1;//1은 사과 2는 뱀 몸
    }
    cin>>l;
    while(l--){
        int a;
        char b;
        cin>>a>>b;
        sec.push(a);
        side.push(b);
    }
    snake.push(make_pair(1,1));
    setcur(1,1,0);
    cout<<res<<endl;

}