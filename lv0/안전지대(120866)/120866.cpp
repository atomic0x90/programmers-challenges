#include <string>
#include <vector>

using namespace std;

vector<vector<int>> v;

void check(int i,int j,int n){
    v[i][j] = 1;
    if(i > 0){
        if(j > 0) v[i-1][j-1] = 1;
        v[i-1][j] = 1;
        if(j < n-1) v[i-1][j+1] = 1;
    }
    if(i < n-1){
        if(j > 0) v[i+1][j-1] = 1;
        v[i+1][j] = 1;
        if(j < n-1) v[i+1][j+1] = 1;
    }
    if(j > 0) v[i][j-1] = 1;
    if(j < n-1) v[i][j+1] = 1;
}

int solution(vector<vector<int>> board) {
    v.resize(board.size(),vector<int>(board.size(),0));
    int answer = 0;
    
    for(int i = 0;i < board.size();i++){
        for(int j = 0;j < board[i].size();j++){
            if(board[i][j] == 1) check(i,j,board.size());
        }
    }
    
    for(int i = 0;i < v.size();i++){
        for(int j = 0;j < v.size();j++)
            if(v[i][j] == 0) answer++;
    }
    
    return answer;
}
