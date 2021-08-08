#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int n = maps.size(),m = maps[0].size();
    int answer = 0;
    vector <vector<int> > visit(maps.size(),(vector<int>(maps[0].size(),INT_MAX)));
    
    queue <pair<int,int> > q;
    q.push(make_pair(0,0));
    visit[0][0] = 1;
    
    while(!q.empty()){
        int qf = q.front().first, qs = q.front().second;
        if(qf - 1 >= 0){//up
            if(maps[qf-1][qs] == 1){
                if(visit[qf-1][qs] > visit[qf][qs] + 1){
                    visit[qf-1][qs] = visit[qf][qs] + 1;
                    q.push(make_pair(qf-1,qs));
                }
            }
        }
        if(qf + 1 < n){//down
            if(maps[qf+1][qs] == 1){
                if(visit[qf+1][qs] > visit[qf][qs] + 1){
                    visit[qf+1][qs] = visit[qf][qs] + 1;
                    q.push(make_pair(qf+1,qs));
                }
            }
        }
        if(qs - 1 >= 0){//left
            if(maps[qf][qs-1] == 1){
                if(visit[qf][qs-1] > visit[qf][qs] + 1){
                    visit[qf][qs-1] = visit[qf][qs] + 1;
                    q.push(make_pair(qf,qs-1));
                }
            }
        }
        if(qs + 1 < m){//right
            if(maps[qf][qs+1] == 1){
                if(visit[qf][qs+1] > visit[qf][qs] + 1){
                    visit[qf][qs+1] = visit[qf][qs] + 1;
                    q.push(make_pair(qf,qs+1));
                }
            }
        }
        q.pop();
    }
    
    visit[n-1][m-1] == INT_MAX ? answer = -1 : answer = visit[n-1][m-1];
    
    return answer;
}
