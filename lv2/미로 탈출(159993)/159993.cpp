#include <string>
#include <vector>
#include <utility>
#include <limits.h>
#include <queue>

using namespace std;

queue<pair<int,int>> q;

int answer = 0;

pair<int,int> findEnd(vector<string> maps, char findWhat){
    pair<int,int> a;
    for(int i = 0;i < maps.size();i++){
        for(int j = 0;j < maps[0].size();j++){
            if(maps[i][j] == findWhat){
                a.first = i;
                a.second = j;
                return a;
            }
        }
    }
}

bool bfs(vector<string> map, queue<pair<int,int>> q, pair<int,int> end){
    queue<pair<int,int>> sq;
    do{
        while(!sq.empty()) sq.pop();
        while(!q.empty()){
            pair<int,int> tq = q.front();
            q.pop();
            map[tq.first][tq.second] = 'X';
            if(tq.first == end.first && tq.second == end.second) return false;
            if(tq.first != 0 && map[tq.first-1][tq.second] != 'X'){
                //top
                sq.push(make_pair(tq.first-1,tq.second));
                map[tq.first-1][tq.second] = 'X';
            }

            if(tq.first != map.size()-1 && map[tq.first+1][tq.second] != 'X'){
                //bottom
                sq.push(make_pair(tq.first+1,tq.second));
                map[tq.first+1][tq.second] = 'X';
            }

            if(tq.second != 0 && map[tq.first][tq.second-1] != 'X'){
                //left
                sq.push(make_pair(tq.first,tq.second-1));
                map[tq.first][tq.second-1] = 'X';
            }

            if(tq.second != map[0].size()-1 && map[tq.first][tq.second+1] != 'X'){
                //right
                sq.push(make_pair(tq.first,tq.second+1));
                map[tq.first][tq.second+1] = 'X';
            }
        }
        q = sq;
        answer++;
    } while(!sq.empty());
    
    return true;
}

int solution(vector<string> maps) {
    pair<int,int> startPoint = findEnd(maps,'S');
    pair<int,int> endPoint = findEnd(maps,'L');
    
    q.push(startPoint);
    if(bfs(maps,q,endPoint)) return -1;
    
    while(!q.empty()) q.pop();
    
    startPoint = findEnd(maps,'L');
    endPoint = findEnd(maps,'E');
    
    q.push(startPoint);
    if(bfs(maps,q,endPoint)) return -1;
    else return answer;
}
