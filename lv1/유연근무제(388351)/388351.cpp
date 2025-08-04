#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int i = 0;i < timelogs.size();i++)
    {
        int day = startday;
        bool flag = true;
        int hour = schedules[i] / 100;
        int minute = schedules[i] % 100;
        
        for(int j = 0;j < timelogs[i].size();j++)
        {
            if(day != 6 && day != 7)
            {
                if(timelogs[i][j] / 100 == hour)
                {
                    if(timelogs[i][j] % 100 > minute + 10)
                    {
                        flag = false;
                        break;
                    }
                }
                else if(timelogs[i][j] / 100 == hour + 1)
                {
                    if((timelogs[i][j] % 100) + 60 > minute + 10)
                    {
                        flag = false;
                        break;
                    }
                }
                else if(timelogs[i][j] / 100 > hour + 1)
                {
                    flag = false;
                    break;
                }
            }
            
            day == 7 ? day = 1 : day++;
        }
        
        if(flag == true) answer++;
        
    }
    
    return answer;
}
