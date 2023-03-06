#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> v(101);
set<int> s;
vector<int> visit;

void algo(int a,int b){
    visit[a] = 1;
    
    for(int i = 0;i < v[a].size();i++){
        if(visit[v[a][i]] == 0 && v[a][i] != b){
            s.insert(v[a][i]);
            algo(v[a][i],b);
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1000;
    
    for(int i = 0;i < wires.size();i++){
        v[wires[i][0]].push_back(wires[i][1]);
        v[wires[i][1]].push_back(wires[i][0]);
    }
    
    for(int i = 0;i < wires.size();i++){
        visit.clear();
        visit.resize(n+1,0);
        s.insert(wires[i][0]);
        algo(wires[i][0],wires[i][1]);
        
        int s1 = s.size();
        s.clear();

        visit.clear();
        visit.resize(n+1,0);
        s.insert(wires[i][1]);
        algo(wires[i][1],wires[i][0]);

        int s2 = s.size();
        s.clear();
        
        answer = min(answer,abs(s1-s2));
    }
    
    return answer;
}
