#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector <int> basket;
    int N = board[0].size();
    int check_grap;
    
    for(int i = 0;i < moves.size();i++){
        check_grap = 0;
        for(int j = 0;j < N;j++){
            if(board[j][moves[i]-1] != 0){
                check_grap = board[j][moves[i]-1];
                board[j][moves[i]-1] = 0;
                break;
            }
        }
        if(check_grap != 0){
            if(basket.back() == check_grap && !basket.empty()){
                answer += 2;
                basket.pop_back();
            }
            else{
                basket.push_back(check_grap);
            }
        
        }
    }
    return answer;
}
