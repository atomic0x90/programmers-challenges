#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    vector<int> visit(N+1,0);
    set<int> s;
    queue<pair<int,int> > q;
    vector<vector<pair<int,int> > > v(N+1);
    
    for(int i = 0;i < road.size();i++){
        v[road[i][0]].push_back(make_pair(road[i][1],road[i][2]));
        v[road[i][1]].push_back(make_pair(road[i][0],road[i][2]));
    }
    
    q.push(make_pair(1,0));
    visit[1] = 0;
    while(!q.empty()){
        int qff = q.front().first;
        int qfs = q.front().second;
        s.insert(qff);
        for(int i = 0;i < v[qff].size();i++){
            if(v[qff][i].second + qfs <= K && (v[qff][i].second + qfs < visit[v[qff][i].first] || visit[v[qff][i].first] == 0) ){
                q.push(make_pair(v[qff][i].first,v[qff][i].second + qfs));
                visit[v[qff][i].first] = v[qff][i].second + qfs;
            }
        }
        q.pop();
    }
    return s.size();
}
