#include <string>
using namespace std;
int visit[11][11][4];   //UDRL 0123

int solution(string dirs) {
    int answer = 0;
    int x = 0,y = 0;
    for(int i = 0;i < dirs.size();i++){
        if(dirs[i] == 'U'){
            if(y != 5){
                if(visit[x+5][y+5][0] != 1){
                    visit[x+5][y+5][0] = 1;
                    visit[x+5][y+6][1] = 1;
                    answer++;
                }
                y++;
            }
            else continue;
        }
        else if(dirs[i] == 'D'){
            if(y != -5){
                if(visit[x+5][y+5][1] != 1){
                    visit[x+5][y+5][1] = 1;
                    visit[x+5][y+4][0] = 1;
                    answer++;
                }
                y--;
            }
            else continue;
        }
        else if(dirs[i] == 'R'){
            if(x != 5){
                if(visit[x+5][y+5][2] != 1){
                    visit[x+5][y+5][2] = 1;
                    visit[x+6][y+5][3] = 1;
                    answer++;
                }
                x++;
            }
            else continue;
        }
        else if(dirs[i] == 'L'){
            if(x != -5){
                if(visit[x+5][y+5][3] != 1){
                    visit[x+5][y+5][3] = 1;
                    visit[x+4][y+5][2] = 1;
                    answer++;
                }
                x--;
            }
            else continue;
        }
    }
    return answer;
}
