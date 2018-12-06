#include <string>
#include <vector>
//participant를 처음부터 끝까지 돌며 completion에 같은 이름이 있을 경우마다 제거했습니다.
using namespace std;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    //O(nm)-a
    for(int i = 0; i < participant.size(); i++)
    {
        for(int j = 0; j<completion.size(); j++)
        {
            if(completion.empty())//completion이 비었으면
            {
                answer = participant[i];
                return answer; //현재이름을 반환
            }
            if(participant[i] == completion[j]) //같은 이름을 찾으면
            {
                completion.erase(completion.begin()+j); //이름을 삭제
                break;
            }
            else{
                if(j == completion.size()-1)  //마지막까지 completion에 일치하는 이름이 없으면
                {
                    answer = participant[i];
                    return answer; //현재이름 반환
                }
            }
        }
    }
}






#include<iostream>
#include<stdio.h>
#include<deque>

using namespace std;

char map[52][52]; 

int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }; //4 방향

typedef struct Cord { //pair 사용 x
	int x;
	int y;
}cord;

deque<cord> fire;
deque<cord> firetemp;  //물 bfs용 큐

deque<cord> man;
deque<cord> mantemp;  //고슴도치 bfs용 큐

cord startposition; //고슴도치이 시작점
cord fireposition;  //물 시작점

bool checkdone(int x, int y)
{
	if (map[x][y] == 'D')
		return true;
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

	cord ft;
	cord mt;

	int count = 0;

	firetemp.clear();

	man.clear();
	mantemp.clear(); //각 큐 초기화

	man.push_back(startposition);

	while (!man.empty())
	{
		//**************물 bfs**************
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

				if (tempx >= 1 && tempx <= h && tempy >= 1 && tempy <= w && (map[tempx][tempy] == '.' || map[tempx][tempy] == 'S')) //빈공간이거나 고슴도치가 지나간 자리면
				{
					map[tempx][tempy] = '*';// 맵에 물 확장
					cord ttf;
					ttf.x = tempx;
					ttf.y = tempy;
					firetemp.push_back(ttf); //큐에 추가
				}
			}
		}// 물 큐를 비우고 임시 큐를 채움

		fire.swap(firetemp); // 큐 스왑

		//********************상근이bfs***********************
		while (!man.empty())
		{
			mt = man.front();
			man.pop_front();

			for (int k = 0; k < 4; k++)
			{
				int mtempx = mt.x;
				int mtempy = mt.y;

				mtempx += dir[k][0];
				mtempy += dir[k][1];

				if (mtempx >= 1 && mtempx <= h && mtempy >= 1 && mtempy <= w && (map[mtempx][mtempy] == '.'|| map[mtempx][mtempy] == 'D')) //빈공간이거나 비버집이면
				{
					if (checkdone(mtempx, mtempy)) //끝났으면
					{
						count++;
						return count;
					}
					map[mtempx][mtempy] = 'S';// 맵에 방문체크
					cord ttm;
					ttm.x = mtempx;
					ttm.y = mtempy;
					mantemp.push_back(ttm); //큐에 추가
				}
			}
		}// 불 큐를 비우고 임시 큐를 채움

		man.swap(mantemp); // 큐 스왑
		count++;
	}
	return -1;
}

void scanmap(int w, int h) {
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			char temp;
			scanf_s("%1c", &temp);
			if (temp == '\n') //빈줄이면 다시한번 입력받음
				scanf_s("%1c", &temp);

			if (temp == '*')//물 위치
			{
				fireposition.x = i;
				fireposition.y = j;
				fire.push_back(fireposition);
			}
			if (temp == 'S')//고슴도치 위치
			{
				startposition.x = i;
				startposition.y = j;
			}			
			map[i][j] = temp;					
		}
	}
	return;
}// 맵입력

int main()
{
	int r,c;

	cin >> r >> c;
	
	scanmap(c, r);
	
	int temp = bfs(c, r);
	if (temp == -1)
		cout << "KAKTUS";
	else
		cout << temp;
	
	return 0;
}