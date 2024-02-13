#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(vector<string> board) {
    int answer = 0;
    queue <pair<int,int>> q;
    pair<int,int> start,end;
    vector<vector<bool>> visit(board.size(),vector<bool>(board[0].size(),false));
    
    for(int i = 0;i < board.size();i++){
        for(int j = 0;j < board[i].size();j++){
            if(board[i][j] == 'R') start = make_pair(i,j);
            if(board[i][j] == 'G'){
                end = make_pair(i,j);
                
                if(!(i == 0 || j == 0) && !(i == board.size()-1 || j == board[i].size()-1)){
                    if(board[i-1][j] != 'D' && board[i+1][j] != 'D' && board[i][j-1] != 'D' && board[i][j+1] != 'D') return -1;
                }
            }
        }
    }
    
    q.push(start);
    
    while(true){
        answer++;
        queue <pair<int,int>> tq;
        while(!q.empty()){
            pair<int,int> now = q.front();
            visit[now.first][now.second] = true;
            
            //상
            for(int i = now.first;i >= 0;i--){
                if(board[i][now.second] == 'D'){
                    now.first++;
                    break;
                }
                else{
                    if(i != 0) now.first--;
                }
            }
            if(now.first != q.front().first || now.second != q.front().second){
                if(!visit[now.first][now.second]) tq.push(make_pair(now.first,now.second));
            }
            if(now.first == end.first && now.second == end.second) return answer;
            
            //하
            now = q.front();
            for(int i = now.first;i < board.size();i++){
                if(board[i][now.second] == 'D'){
                    now.first--;
                    break;
                }
                else{
                    if(i != board.size()-1) now.first++;
                }
            }
            if(now.first != q.front().first || now.second != q.front().second){
                if(!visit[now.first][now.second]) tq.push(make_pair(now.first,now.second));
            }
            if(now.first == end.first && now.second == end.second) return answer;
            
            //좌
            now = q.front();
            for(int i = now.second;i >= 0;i--){
                if(board[now.first][i] == 'D'){
                    now.second++;
                    break;
                }
                else{
                    if(i != 0) now.second--;
                }
            }
            if(now.first != q.front().first || now.second != q.front().second){
                if(!visit[now.first][now.second]) tq.push(make_pair(now.first,now.second));
            }
            if(now.first == end.first && now.second == end.second) return answer;
            
            //우
            now = q.front();
            for(int i = now.second;i < board[now.first].size();i++){
                if(board[now.first][i] == 'D'){
                    now.second--;
                    break;
                }
                else{
                    if(i != board[now.first].size()-1) now.second++;
                }
            }
            if(now.first != q.front().first || now.second != q.front().second){
                if(!visit[now.first][now.second]) tq.push(make_pair(now.first,now.second));
            }
            if(now.first == end.first && now.second == end.second) return answer;
            
            q.pop();
        }
        q = tq;
        if(tq.empty()) return -1;
    }
}
