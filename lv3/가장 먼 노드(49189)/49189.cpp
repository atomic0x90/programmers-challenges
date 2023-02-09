#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> visit(20001,0);
vector<vector<int>> v;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    v.resize(20001);
    for(int i = 0;i < edge.size();i++){
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    
    visit[1] = 1;
    queue <int> q;
    q.push(1);
    int now;
    
    while(!q.empty()){
        now = q.front();
        for(int i = 0;i < v[now].size();i++){
            if(visit[v[now][i]] == 0){
                visit[v[now][i]] = visit[now] + 1;
                q.push(v[now][i]);
            }
        }
        q.pop();
    }
    
    sort(visit.begin(),visit.end(),greater<int>());
    
    for(int i = 0;i < visit.size();i++){
        if(visit[0] == visit[i]) answer++;
        else break;
    }
    
    return answer;
}
