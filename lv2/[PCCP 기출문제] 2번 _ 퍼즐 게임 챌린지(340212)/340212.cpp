#include <vector>
#include <algorithm>

using namespace std;

int algo(vector<int> diffs, vector<int> times, long long limit, int level)
{
    long long nowTime = 0;
    for(int i = 0;i < diffs.size();i++)
    {
        if(diffs[i] <= level)
        {
            nowTime += times[i];
        }
        else
        {
            for(int j = (diffs[i] - level);j > 0;j--)
            {
                nowTime += times[i-1] + times[i];
            }
            nowTime += times[i];
        }
        
        if(nowTime > limit) break;
    }
    return (limit >= nowTime ? level : -1);   
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int right = *max_element(diffs.begin(),diffs.end());
    int mid = right/2;
    int left = 0;
    int algoResult = 0;
    
    while(left != mid)
    {
        algoResult = algo(diffs, times, limit, mid);
        if(algoResult == -1)
        {
            left = mid;
            mid = (left+right)/2;
        }
        else
        {
            right = mid;
            mid /= 2;
        }
    }
    
    return right;
}
