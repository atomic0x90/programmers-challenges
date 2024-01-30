#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//[][][0] : from top, [][][1] : from right, [][][2] : from bottom, [][][3] : from left
vector<vector<vector<int>>> visit(500,vector<vector<int>>(500, vector<int>(4)));

int algo(int startX, int startY, vector<string> grid, int startFrom){
    int x = startX, y = startY, from = startFrom;
    int answer = 0;
    do{
        if(visit[x][y][from] == 1) break;
        answer++;
        visit[x][y][from] = 1;
            
        if(from == 0 && grid[x][y] == 'S'){
            x++;
            if(x == grid.size()) x = 0;
            from = 0;
        }
        else if(from == 0 && grid[x][y] == 'L'){
            y++;
            if(y == grid[x].size()) y = 0;
            from = 3;
        }
        else if(from == 0 && grid[x][y] == 'R'){
            y--;
            if(y == -1) y = grid[x].size()-1;
            from = 1;
        }
        else if(from == 1 && grid[x][y] == 'S'){
            y--;
            if(y == -1) y = grid[x].size()-1;
            from = 1;
        }
        else if(from == 1 && grid[x][y] == 'L'){
            x++;
            if(x == grid.size()) x = 0;
            from = 0;
        }
        else if(from == 1 && grid[x][y] == 'R'){
            x--;
            if(x == -1) x = grid.size()-1;
            from = 2;
        }
        else if(from == 2 && grid[x][y] == 'S'){
            x--;
            if(x == -1) x = grid.size()-1;
            from = 2;
        }
        else if(from == 2 && grid[x][y] == 'L'){
            y--;
            if(y == -1) y = grid[x].size()-1;
            from = 1;
        }
        else if(from == 2 && grid[x][y] == 'R'){
            y++;
            if(y == grid[x].size()) y = 0;
            from = 3;
        }
        else if(from == 3 && grid[x][y] == 'S'){
            y++;
            if(y == grid[x].size()) y = 0;
            from = 3;
        }
        else if(from == 3 && grid[x][y] == 'L'){
            x--;
            if(x == -1) x = grid.size()-1;
            from = 2;
        }
        else if(from == 3 && grid[x][y] == 'R'){
            x++;
            if(x == grid.size()) x = 0;
            from = 0;
        }
    }while(startX != x || startY != y || startFrom != from);
    
    return answer;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    for(int i = 0;i < grid.size();i++){
        for(int j = 0;j < grid[i].size();j++){
            for(int k = 0;k < 4;k++){
                if(visit[i][j][k] == 0){
                    int algoReturnValue = algo(i,j,grid,k);
                    if(algoReturnValue != 0) answer.push_back(algoReturnValue);
                }
            }
        }
    }
    sort(answer.begin(),answer.end());
    
    return answer;
}
