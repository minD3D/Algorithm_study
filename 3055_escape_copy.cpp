#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MAX = 50;
typedef struct{
    int y, x;
} Dir;

Dir moveDir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int R, C;

pair<int, int> start, destination;
string graph[MAX];
queue<pair<int, int>> river;
int cache[MAX][MAX];

int BFS(void)
{

    queue<pair<int, int>> mole;
    mole.push(start);
    cache[start.first][start.second] = 1;
    while (!mole.empty())
    {

        int curRiverSize = river.size();
        //우선 물이 차오른다
        for (int j = 0; j < curRiverSize; j++)
        {
            int curY = river.front().first;
            int curX = river.front().second;
            river.pop();
            for (int k = 0; k < 4; k++)
            {
                int nextY = curY + moveDir[k].y;
                int nextX = curX + moveDir[k].x;
                if (0 <= nextY && nextY < R && 0 <= nextX && nextX < C)
                {
                    //빈칸으로
                    if (graph[nextY][nextX] == '.')
                    {
                        graph[nextY][nextX] = '*';
                        river.push(make_pair(nextY, nextX));
                    }
                }
            }
        }

        int curSize = mole.size();
        for (int i = 0; i < curSize; i++)
        {
            int y = mole.front().first;
            int x = mole.front().second;
            mole.pop();
            //목적지 도달 시
            if (y == destination.first && x == destination.second)
                return cache[y][x] - 1;
            //두더지가 움직일 차례
            for (int j = 0; j < 4; j++)
            {
                int nextY = y + moveDir[j].y;
                int nextX = x + moveDir[j].x;
                if (0 <= nextY && nextY < R && 0 <= nextX && nextX < C)
                    //돌과 물에 차 있는 곳으로 움직일 수 없다
                    if (graph[nextY][nextX] != '*' && graph[nextY][nextX] != 'X' && cache[nextY][nextX] == 0)
                    {

                        cache[nextY][nextX] = cache[y][x] + 1;
                        mole.push(make_pair(nextY, nextX));
                    }
            }
        }
    }

    return -1;
}

int main(void)

{

    int result;

    cin >> R >> C;

    for (int i = 0; i < R; i++)

    {

        cin >> graph[i];

        for (int j = 0; j < C; j++)

            if (graph[i][j] == 'S')

                start = make_pair(i, j);

            else if (graph[i][j] == '*')

                river.push(make_pair(i, j));

            else if (graph[i][j] == 'D')

                destination = make_pair(i, j);
    }

    result = BFS();

    if (result == -1)

        cout << "KAKTUS" << endl;

    else    

        cout << result << endl;

    return 0;
}



// //메모리 초과 코드
// 위와 구조가 같은거같은데 초과나옴...
// #include <iostream>
// #include <stdio.h>
// #include <queue>

// using namespace std;
// int r, c, res = 0;
// char arr[51][51];
// queue<pair<int, int>> water; // 물이 있는 위치를 저장
// pair<int, int> start;
// void nextsec()
// {
//     queue<pair<int, int>> S; //갈 수 있는 고슴도치 위치 저장
//     S.push(make_pair(start.first, start.second));
//     int sec=0;
//     while (!S.empty())
//     {   
//         sec++;
//         int ws = water.size();
//         int ss = S.size();
//         while (ws--)
//         {
//             int a = water.front().first;
//             int b = water.front().second;
//             water.pop();
//             //S가 있는칸도 물이 퍼지도록 따로 세팅해야하는지 확인할것
//             if (a + 1 >= 0 && b >= 0 && a + 1 < r && b < c && arr[a + 1][b] == '.')
//             {
//                 water.push(make_pair(a + 1, b));
//                 arr[a + 1][b] = '*';
//             }
//             if (a >= 0 && b + 1 >= 0 && a < r && b + 1 < c && arr[a][b + 1] == '.')
//             {
//                 water.push(make_pair(a, b + 1));
//                 arr[a][b + 1] = '*';
//             }
//             if (a - 1 >= 0 && b >= 0 && a - 1 < r && b < c && arr[a - 1][b] == '.')
//             {
//                 water.push(make_pair(a - 1, b));
//                 arr[a - 1][b] = '*';
//             }
//             if (a >= 0 && b - 1 >= 0 && a < r && b - 1 < c && arr[a][b - 1] == '.')
//             {
//                 water.push(make_pair(a, b - 1));
//                 arr[a][b - 1] = '*';
//             }
//         }
//         while (ss--)
//         {
//             int a = S.front().first;
//             int b = S.front().second;
//             if (arr[a + 1][b] == 'D' || arr[a][b + 1] == 'D' || arr[a - 1][b] == 'D' || arr[a][b - 1] == 'D')
//                 res = sec;
//             S.pop();
//             if (a + 1 >= 0 && b >= 0 && a + 1 < r && b < c && arr[a + 1][b] == '.')
//             {
//                 S.push(make_pair(a + 1, b));
//             }
//             if (a >= 0 && b + 1 >= 0 && a < r && b + 1 < c && arr[a][b + 1] == '.')
//             {
//                 S.push(make_pair(a, b + 1));
//             }
//             if (a - 1 >= 0 && b >= 0 && a - 1 < r && b < c && arr[a - 1][b] == '.')
//             {
//                 S.push(make_pair(a - 1, b));
//             }
//             if (a >= 0 && b - 1 >= 0 && a < r && b - 1 < c && arr[a][b - 1] == '.')
//             {
//                 S.push(make_pair(a, b - 1));
//             }
//         }
//     }
//     return;
// }

// int main()
// {
//     // .빈칸 *물 X돌 D굴 S위치
//     //물 매분 확장
//     cin >> r >> c;
//     for (int i = 0; i < r; i++)
//     {
//         string a;
//         cin >> a;
//         for (int j = 0; j < c; j++)
//         {
//             if (a[j] == 'S')
//             {
//                 start = make_pair(i, j);
//                 arr[i][j] = '.';
//             }
//             else
//             {
//                 if (a[j] == '*')
//                     water.push(make_pair(i, j));
//                 arr[i][j] = a[j];
//             }
//         }
//     }

//     nextsec();
//     cout << res << endl;
// }
