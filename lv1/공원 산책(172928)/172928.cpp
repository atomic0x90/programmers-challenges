#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int W = park[0].size(), H = park.size();
    for(int i = 0;i < H && answer.size() == 0;i++){
        for(int j = 0;j < W;j++){
            if(park[i][j] == 'S'){
                answer.push_back(i);
                answer.push_back(j);
                break;
            }
        }
    }
    
    for(int i = 0;i < routes.size();i++){
        if(routes[i].front() == 'N'){
            if(answer[0] - (routes[i].back()-'0') < 0) continue;
            
            bool flag = true;
            
            for(int j = 1;j <= (routes[i].back()-'0');j++){
                if(park[answer[0] - j][answer[1]] == 'X') flag = false;
            }
            
            if(flag) answer[0] -= (routes[i].back()-'0');
        }
        else if(routes[i].front() == 'S'){
            if(answer[0] + (routes[i].back()-'0') >= H) continue;
            
            bool flag = true;
            
            for(int j = 1;j <= (routes[i].back()-'0');j++){
                if(park[answer[0] + j][answer[1]] == 'X') flag = false;
            }
            
            if(flag) answer[0] += (routes[i].back()-'0');
        }
        else if(routes[i].front() == 'W'){
            if(answer[1] - (routes[i].back()-'0') < 0) continue;
            
            bool flag = true;
            
            for(int j = 1;j <= (routes[i].back()-'0');j++){
                if(park[answer[0]][answer[1] - j] == 'X') flag = false;
            }
            
            if(flag) answer[1] -= (routes[i].back()-'0');
        }
        else if(routes[i].front() == 'E'){
            if(answer[1] + (routes[i].back()-'0') >= W) continue;
            
            bool flag = true;
            
            for(int j = 1;j <= (routes[i].back()-'0');j++){
                if(park[answer[0]][answer[1] + j] == 'X') flag = false;
            }
            
            if(flag) answer[1] += (routes[i].back()-'0');
        }
    }
    
    return answer;
}
