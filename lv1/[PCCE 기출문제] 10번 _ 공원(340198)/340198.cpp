#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    int max_size = 0;
    vector<vector<int>> v(park.size(),(vector<int>(park[0].size(),0)));
    
    sort(mats.begin(),mats.end());
    
    for(int i = 0;i < park.size();i++) // 세로 첫 줄 초기화
    {
        if(park[i][0] != "-1")
        {
            v[i][0] = 0;
        }
        else
        {
            v[i][0] = 1;
        }
    }
    
    for(int i = 0;i < park[0].size();i++) // 가로 첫 줄 초기화
    {
        if(park[0][i] != "-1")
        {
            v[0][i] = 0;
        }
        else
        {
            v[0][i] = 1;
        }
    }
    
    for(int i = 1;i < park.size();i++)
    {
        for(int j = 1;j < park[i].size();j++)
        {
            if(park[i][j] == "-1")
            {
                v[i][j] = min(min(v[i-1][j],v[i][j-1]),v[i-1][j-1]) + 1;
                max_size = max(max_size, v[i][j]);
            }
            else
            {
                v[i][j] = 0;
            }
        }
    }
    
    for(int i = mats.size()-1;i >= 0;i--)
    {
        if(mats[i] <= max_size)
        {
            answer = mats[i];
            break;
        }
    }
    
    return answer;
}
