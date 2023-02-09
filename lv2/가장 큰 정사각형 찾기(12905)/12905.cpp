#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board){
    int answer = 0;
    if(board.size() == 1 && board[0].size() == 1) return board[0][0];
    
    for(int i = 1;i < board.size();i++){
        for(int j = 1;j < board[i].size();j++){
            if(board[i][j] == 0){
                if(board[i-1][j-1] || board[i-1][j] || board[i][j-1]){
                    if(answer == 0) answer = 1;
                }
            }
            else board[i][j] = min(board[i-1][j-1],min(board[i-1][j],board[i][j-1])) + 1;
        
            if(board[i][j] > answer) answer = board[i][j];
        }
    }
    
    return answer*answer;
}
