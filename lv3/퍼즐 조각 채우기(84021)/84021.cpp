#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<vector<int>> c90(vector<vector<int>> block){
    vector<vector<int>> tmp(block.size(),vector<int>(block.size(),0));
    for(int i = 0;i < block.size();i++){
        for(int j = 0;j < block[i].size();j++){
            tmp[i][j] = block[block[i].size()-j-1][i];
        }
    }
    return tmp;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {   
    int answer = 0;
    vector<vector<int>> visit(table.size(),vector<int>(table[0].size(),0));
    
    for(int i = 0;i < table.size();i++){
        for(int j = 0;j < table[i].size();j++){
            if(table[i][j] == 0) visit[i][j] = 1;
        }
    }
    
    for(int i = 0;i < table.size();i++){
        for(int j = 0;j < table[i].size();j++){
            if(table[i][j] == 1 && visit[i][j] == 0){
                queue<pair<int,int>> q;
                vector<pair<int,int>> coordinate;
                
                q.push(make_pair(i,j));
                
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    if(visit[x][y] == 1) continue;
                    
                    visit[x][y] = 1;
                    coordinate.push_back(make_pair(x-i,y-j));
                    
                    if(x != 0){ //up
                        if(visit[x-1][y] == 0 && table[x-1][y] == 1) q.push(make_pair(x-1,y));
                    }
                    if(y != 0){ //left
                        if(visit[x][y-1] == 0 && table[x][y-1] == 1) q.push(make_pair(x,y-1));
                    }
                    if(x != table.size()-1){  //down
                        if(visit[x+1][y] == 0 && table[x+1][y] == 1) q.push(make_pair(x+1,y));
                    }
                    if(y != table.size()-1){  //right
                        if(visit[x][y+1] == 0 && table[x][y+1] == 1) q.push(make_pair(x,y+1));
                    }
                }
                
                vector<vector<int>> field = game_board;
                
                for(int k = 0;k < 4;k++){
                    vector<vector<int>> fvisit = field;
                    
                    bool flag = false;
                    for(int o = 0;o < game_board.size();o++){
                        for(int p = 0;p < game_board.size();p++){
                            if(field[o][p] == 0 && fvisit[o][p] == 0){
                                vector<pair<int,int>> fieldCoor;
                                
                                q.push(make_pair(o,p));
                                
                                while(!q.empty()){
                                    int x = q.front().first;
                                    int y = q.front().second;

                                    q.pop();
                                    if(fvisit[x][y] == 1) continue;
                                    
                                    fvisit[x][y] = 1;
                                    fieldCoor.push_back(make_pair(x-o,y-p));
                                    
                                    if(x != 0){ //up
                                        if(fvisit[x-1][y] == 0 && field[x-1][y] == 0) q.push(make_pair(x-1,y));
                                    }
                                    if(y != 0){ //left
                                        if(fvisit[x][y-1] == 0 && field[x][y-1] == 0) q.push(make_pair(x,y-1));
                                    }
                                    if(x != table.size()-1){  //down
                                        if(fvisit[x+1][y] == 0 && field[x+1][y] == 0) q.push(make_pair(x+1,y));
                                    }
                                    if(y != table.size()-1){  //right
                                        if(fvisit[x][y+1] == 0 && field[x][y+1] == 0) q.push(make_pair(x,y+1));
                                    }
                                }
                                
                                if(coordinate.size() == fieldCoor.size()){
                                    bool checkFlag = true;
                                    
                                    for(int m = 0;m < coordinate.size();m++){
                                        if(coordinate[m] != fieldCoor[m])
                                            checkFlag = false;
                                    }
                                    if(checkFlag){
                                        answer += fieldCoor.size();

                                        for(int m = 0;m < fieldCoor.size();m++)
                                            field[fieldCoor[m].first+o][fieldCoor[m].second+p] = 1;

                                        while(k != 4){
                                            k++;
                                            field = c90(field);
                                        }
                                        game_board = field;
                                        flag = true;
                                    }
                                    
                                }
                            }
                            if(flag) break;
                        }
                        if(flag) break;
                    }
                    if(flag) break;
                    field = c90(field);
                }
                
            }
        }
    }
    return answer;
}
