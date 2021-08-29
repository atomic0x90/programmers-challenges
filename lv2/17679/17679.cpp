#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool flag = true;
    while(flag){
        flag = false;
        vector<vector<int> > v(m,vector<int>(n,1));
        
        for(int i = 0;i < m-1;i++){
            for(int j = 0;j < n-1;j++){
                if(board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j] && board[i][j] == board[i+1][j+1] && board[i][j] != ' '){
                    v[i][j] = 0;
                    v[i][j+1] = 0;
                    v[i+1][j] = 0;
                    v[i+1][j+1] = 0;
                    flag = true;
                }
            }
        }
        
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(v[i][j] == 0) board[i][j] = ' ';
            }
        }
        
        for(int i = 0;i < n;i++){
            for(int j = m-1;j > 0;j--){
                if(board[j][i] == ' '){
                    for(int k = j-1;k >= 0;k--){
                        if(board[k][i] != ' '){
                            board[j][i] = board[k][i];
                            board[k][i] = ' ';
                            break;
                        }
                    }
                }
            }
        }
        
    }
    
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            if(board[i][j] == ' ') answer++;
        }
    }
    
    return answer;
}
