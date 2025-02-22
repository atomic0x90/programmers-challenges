#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
	int answer = 0;
	vector<int> routNum(routes.size(),0);
	vector<vector<int>> now(routes.size(),vector<int>(2,0));

	for(int i = 0;i < routes.size();i++)   // 출발 위치 조정
	{
		now[i][0] = points[routes[i][0]-1][0]-1;
		now[i][1] = points[routes[i][0]-1][1]-1;
	}

	while(true)
	{
		vector<vector<int>> visit(100,vector<int>(100,0));

		for(int i = 0;i < now.size();i++)
		{
			if(routNum[i] != -1)    // 운송 마침 여부 확인
			{
				if(now[i][0] != points[ routes[i][routNum[i]] - 1 ] [0] - 1)   // r 좌표 이동
				{
					(now[i][0] > points[ routes[i][routNum[i]] - 1 ] [0] - 1 ? now[i][0]-- : now[i][0]++);
				}
				else if(now[i][1] != points[ routes[i][routNum[i]] - 1] [1] - 1)  //  c 좌표 이동
				{
					(now[i][1] > points[ routes[i][routNum[i]] - 1] [1] - 1 ? now[i][1]-- : now[i][1]++);
				}

				visit[ now[i][0] ][ now[i][1] ]++;

				if(now[i][0] == points[ routes[i][routNum[i]] - 1 ] [0] - 1 && now[i][1] == points[ routes[i][routNum[i]] - 1] [1] - 1)
				{   // 목적지 도착
					if(routNum[i] != routes[i].size()-1) routNum[i]++;
					else routNum[i] = -1;
				}
			}
		}

		for(int i = 0;i < visit.size();i++) // 충돌 확인
		{
			for(int j = 0;j < visit[i].size();j++)
			{
				if(visit[i][j] >= 2)
				{
					answer++;
				}
			}
		}

		bool flag = true;

		for(int i = 0;i < routNum.size();i++)   // 전체 운송 마침 여부 확인
		{
			if(routNum[i] != -1)
			{
				flag = false;
				break;
			}
		}

		if(flag) break;
	}

	return answer;
}
