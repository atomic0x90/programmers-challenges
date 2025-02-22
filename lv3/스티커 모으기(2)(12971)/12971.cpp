#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
	vector<int> sum1(sticker.size(),0);
	vector<int> sum2(sticker.size(),0);

	int answer = sticker[0];

	if(sticker.size() == 1) return sticker[0];
	else if(sticker.size() == 2) return sticker[0] > sticker[1] ? sticker[0] : sticker[1];

	sum1[0] = sticker[0];

	for(int i = 1;i < sticker.size()-1;i++)	// 1번째 스티커를 땐 경우
	{
		sum1[i] = sum1[i-2] + sticker[i] > sum1[i-1] ? sum1[i-2] + sticker[i] : sum1[i-1];
		if(answer < sum1[i]) answer = sum1[i];
	}

	sum2[1] = sticker[1];

	for(int i = 2;i < sticker.size();i++)		// 2번째 스티커를 땐 경우
	{
		sum2[i] = sum2[i-2] + sticker[i] > sum2[i-1] ? sum2[i-2] + sticker[i] : sum2[i-1];
		if(answer < sum2[i]) answer = sum2[i];
	}

	return answer;
}
