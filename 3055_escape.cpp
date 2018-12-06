#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;
int r, c, res = 0;
char arr[51][51];
queue<pair<int, int>> water; // 물이 있는 위치를 저장
pair<int, int> start;
void nextsec()
{
    queue<pair<int, int>> S; //갈 수 있는 고슴도치 위치 저장
    S.push(make_pair(start.first, start.second));
    int sec=0;
    while (!S.empty())
    {   
        sec++;
        int ws = water.size();
        int ss = S.size();
        while (ws--)
        {
            int a = water.front().first;
            int b = water.front().second;
            water.pop();
            //S가 있는칸도 물이 퍼지도록 따로 세팅해야하는지 확인할것
            if (a + 1 >= 0 && b >= 0 && a + 1 < r && b < c && arr[a + 1][b] == '.')
            {
                water.push(make_pair(a + 1, b));
                arr[a + 1][b] = '*';
            }
            if (a >= 0 && b + 1 >= 0 && a < r && b + 1 < c && arr[a][b + 1] == '.')
            {
                water.push(make_pair(a, b + 1));
                arr[a][b + 1] = '*';
            }
            if (a - 1 >= 0 && b >= 0 && a - 1 < r && b < c && arr[a - 1][b] == '.')
            {
                water.push(make_pair(a - 1, b));
                arr[a - 1][b] = '*';
            }
            if (a >= 0 && b - 1 >= 0 && a < r && b - 1 < c && arr[a][b - 1] == '.')
            {
                water.push(make_pair(a, b - 1));
                arr[a][b - 1] = '*';
            }
        }
        while (ss--)
        {   
            int a = S.front().first;
            int b = S.front().second;
            S.pop();
            if (arr[a + 1][b] == 'D' || arr[a][b + 1] == 'D' || arr[a - 1][b] == 'D' || arr[a][b - 1] == 'D')
            {
                res = sec;
                break;
            }

            if (a + 1 >= 0 && b >= 0 && a + 1 < r && b < c && arr[a + 1][b] == '.')
            {
                S.push(make_pair(a + 1, b));
            }
            if (a >= 0 && b + 1 >= 0 && a < r && b + 1 < c && arr[a][b + 1] == '.')
            {
                S.push(make_pair(a, b + 1));
            }
            if (a - 1 >= 0 && b >= 0 && a - 1 < r && b < c && arr[a - 1][b] == '.')
            {
                S.push(make_pair(a - 1, b));
            }
            if (a >= 0 && b - 1 >= 0 && a < r && b - 1 < c && arr[a][b - 1] == '.')
            {
                S.push(make_pair(a, b - 1));
            }
        }
    }
    return;
}

int main()
{
    // .빈칸 *물 X돌 D굴 S위치
    //물 매분 확장
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        string a;
        cin >> a;
        for (int j = 0; j < c; j++)
        {
            if (a[j] == 'S')
            {
                start = make_pair(i, j);
                arr[i][j] = '.';
            }
            else
            {
                if (a[j] == '*')
                    water.push(make_pair(i, j));
                arr[i][j] = a[j];
            }
        }
    }

    nextsec();
    cout << res << endl;
}
