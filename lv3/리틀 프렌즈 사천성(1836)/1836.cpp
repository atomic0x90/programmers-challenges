#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string answer = "";
int num = 0;
vector<int> alpha(26,0);
vector<pair<int,int>> block1(26);
vector<pair<int,int>> block2(26);

void algo(vector<string>bo){
    while(num){
        bool check = true;
        for(int i = 0;i < 26;i++){
            if(alpha[i] == 0) continue;
            bool flag = true;
            int x1,x2,y1,y2;
            x1 = block1[i].first;
            x2 = block2[i].first;
            y1 = block1[i].second;
            y2 = block2[i].second;
            if(x1 == x2){
                //oxo
                for(int j = y1+1;j < y2;j++){
                    if(bo[x1][j] != '.'){
                        flag = false;
                        break;
                    }
                }
            }
            else if(y1 == y2){
                /*
                o
                x
                o
                */
                for(int j = x1+1;j < x2;j++){
                    if(bo[j][y1] != '.' && bo[j][y1] != bo[x1][y1]){
                        flag = false;
                        break;
                    }
                }
            }
            else if(y1 < y2){
                /*
                o
                xo
                */
                bool flag1 = true,flag2 = true;
                for(int j = x1+1;j <= x2;j++){
                    if(bo[j][y1] != '.'){
                        flag1 = false;
                        break;
                    }
                }
                if(flag1){
                    for(int j = y1;j < y2;j++){
                        if(bo[x2][j] != '.'){
                            flag1 = false;
                            break;
                        }
                    }
                }
                if(!flag1){
                    for(int j = y1+1;j <= y2;j++){
                        if(bo[x1][j] != '.'){
                            flag2 = false;
                            break;
                        }
                    }
                    if(flag2){
                        for(int j = x1;j < x2;j++){
                            if(bo[j][y2] != '.'){
                                flag2 = false;
                                break;
                            }
                        }
                    }
                }
                
                if(!flag1 && !flag2) flag = false;
            }
            else if(y1 > y2){
                /*
                   o
                  ox
                */
                bool flag1 = true, flag2 = true;
                for(int j = y1-1;j >= y2;j--){
                    if(bo[x1][j] != '.'){
                        flag1 = false;
                        break;
                    }
                }
                if(flag1){
                    for(int j = x1;j < x2;j++){
                        if(bo[j][y2] != '.'){
                            flag1 = false;
                            break;
                        }
                    }
                }
                if(!flag1){
                    for(int j = x1+1;j <= x2;j++){
                        if(bo[j][y1] != '.'){
                            flag2 = false;
                            break;
                        }
                    }
                    if(flag2){
                        for(int j = y1;j > y2;j--){
                            if(bo[x2][j] != '.'){
                                flag2 = false;
                                break;
                            }
                        }
                    }
                }
                
                if(!flag1 && !flag2) flag = false;
            }
            
            
            if(flag){
                num--;
                answer += char('A'+i);
                check = false;
                bo[x1][y1] = bo[x2][y2] = '.';
                alpha[i] = 0;
                break;
            }
        }
        
        if(check) return;
    }
    
    return;
}

string solution(int m, int n, vector<string> board) {
    answer = "";
    num = 0;
    for(int i = 0;i < 26;i++){
        alpha[i] = 0;
        block1[i].first = 0;
        block1[i].second = 0;
        block2[i].first = 0;
        block2[i].second = 0;
    }
    
    for(int i = 0;i < board.size();i++){
        for(int j = 0;j < board[i].size();j++){
            if(isalpha(board[i][j])){
                if(alpha[board[i][j]-'A'] == 0){
                    block1[board[i][j]-'A'].first = i;
                    block1[board[i][j]-'A'].second = j;
                    alpha[board[i][j]-'A']++;
                    num++;
                }
                else{
                    block2[board[i][j]-'A'].first = i;
                    block2[board[i][j]-'A'].second = j;
                    alpha[board[i][j]-'A']++;
                }
            }
        }
    }
    
    algo(board);
    
    return num == 0 ? answer : "IMPOSSIBLE";
}
