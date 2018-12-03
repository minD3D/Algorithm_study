#include<iostream>
#include<stdio.h>
#include<deque>

using namespace std;

char map[1002][1002];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}}; //4 방향
int testcases[100]; //

typedef struct Cord {
	int x;
	int y;
}cord;

deque<cord> fire;
deque<cord> firetemp;  //불 bfs용 큐

deque<cord> man;
deque<cord> mantemp;  //상근이 bfs용 큐

cord startposition; //상근이 시작점
cord fireposition;  //불 시작점

bool checkdone(int x, int y, int w, int h)
{
	if ((x == h || y == w || x == 1 || y == 1) && (map[x][y] == '.' || map[x][y] == '@'))//가장자리이고 빈공간이거나 시작점이면
	{
		return true;
	}
	return false;
}	

void printmap(int w, int h)
{
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			cout << map[i][j];
			if (j == w)
				cout << endl;
		}
	}
	return;
} // 맵 출력

int bfs(int w, int h) {
	
	if (checkdone(startposition.x, startposition.y, w, h))
		return 1;

	cord ft;
	cord mt;

	int count = 0;
	
	//fire.clear();
	firetemp.clear();
	
	man.clear();
	mantemp.clear();
	
	//각 큐 초기화

	man.push_back(startposition);
	//fire.push_back(fireposition);
	//상근이와 불의 출발위치를 넣음

	//cout << startposition.x << "," << startposition.y << endl;
	//cout << fireposition.x << "," << fireposition.y << endl;


	while (!man.empty())
	{
		//**************불 bfs**************
		while (!fire.empty())
		{
			ft = fire.front();  //맨 앞 요소를 꺼냄
			fire.pop_front();

			for (int k = 0; k < 4; k++)
			{
				int tempx = ft.x;
				int tempy = ft.y;
				
				tempx += dir[k][0];
				tempy += dir[k][1];

				if (tempx >= 1 && tempx <= h && tempy >= 1 && tempy <= w && (map[tempx][tempy] == '.' || map[tempx][tempy] == '@')) //빈공간이거나 방문한 자리면
				{
					map[tempx][tempy] = '*';// 불 확장
					cord ttf;
					ttf.x = tempx;
					ttf.y = tempy;
					firetemp.push_back(ttf); //큐에 추가
				}
			}
		}// 불 큐를 비우고 임시 큐를 채움
		
		fire.swap(firetemp); // 큐 스왑

		//********************상근이bfs***********************
		while(!man.empty())
		{
			mt = man.front();
			man.pop_front();

			for (int k = 0; k < 4; k++)
			{
				int mtempx = mt.x;
				int mtempy = mt.y;

				mtempx += dir[k][0];
				mtempy += dir[k][1];

				if (mtempx >= 1 && mtempx <= h && mtempy >= 1 && mtempy <= w && map[mtempx][mtempy] == '.' ) //빈공간이면
				{
					if (checkdone(mtempx, mtempy, w, h)) //끝났으면
					{
						count += 2;
						return count;
					}
					map[mtempx][mtempy] = '@';// 방문체크
					cord ttm;
					ttm.x = mtempx;
					ttm.y = mtempy;
					mantemp.push_back(ttm); //큐에 추가
				}
			}
		}// 불 큐를 비우고 임시 큐를 채움

		man.swap(mantemp); // 큐 스왑
		count++;
		//printmap(w, h);
	}


	return -1;
}




void scanmap(int w, int h) {
	fire.clear();
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			char temp;
			scanf_s("%1c", &temp);
			if (temp == '\n') {
				scanf_s("%1c", &temp);

				if (temp == '*')
				{
					fireposition.x = i;
					fireposition.y = j;
					fire.push_back(fireposition);
				}
				if (temp == '@')
				{
					startposition.x = i;
					startposition.y = j;
				}
				map[i][j] = temp;
			}
			else
			{
				if (temp == '*')
				{
					fireposition.x = i;
					fireposition.y = j;
					fire.push_back(fireposition);
				}
				if (temp == '@')
				{
					startposition.x = i;
					startposition.y = j;
				}
				map[i][j] = temp;
			}
		}
	}
	return;
}// 맵입력

int main()
{
	int n, h ,w;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> w >> h;
		//cout << w << "," << h << endl;
		scanmap(w, h);
		//printmap(w, h);
		testcases[i] = bfs(w, h);
	}
	for (int i = 0; i < n; i++)
	{
		if (testcases[i] == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << testcases[i] << endl;
	}

	return 0;
}
