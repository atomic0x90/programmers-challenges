#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
    int x = 0, o = 0;
    bool Xend = false, Oend = false;
    char what = ' ';
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            if(board[i][j] == 'X') x++;
            else if(board[i][j] == 'O') o++;
        }
    }
    
    if(board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][0] != '.'){
        what = board[0][0];
        if(what == 'X') Xend = true;
        else Oend = true;
    }
    if(board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0] != '.'){
        what = board[1][0];
        if(what == 'X') Xend = true;
        else Oend = true;
    }
    if(board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] != '.'){
        what = board[2][0];
        if(what == 'X') Xend = true;
        else Oend = true;
    }
    if(board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[0][0] != '.'){
        what = board[0][0];
        if(what == 'X') Xend = true;
        else Oend = true;
    }
    if(board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1] != '.'){
        what = board[0][1];
        if(what == 'X') Xend = true;
        else Oend = true;
    }
    if(board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2] != '.'){
        what = board[0][2];
        if(what == 'X') Xend = true;
        else Oend = true;
    }
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != '.'){
        what = board[0][0];
        if(what == 'X') Xend = true;
        else Oend = true;
    }
    if(board[0][2] == board[1][1] && board[0][2] == board[0][2] && board[0][2] != '.'){
        what = board[0][2];
        if(what == 'X') Xend = true;
        else Oend = true;
    }
    
    if(Xend && Oend) return 0;
    if(Xend || Oend){
        if(what == 'X'){
            if(o == x) return 1;
            else return 0;
        }
        else{
            if(o == x+1) return 1;
            else return 0;
        }
    }
    else{
        if(o == x || o == x+1) return 1;
        else return 0;
    }
}
