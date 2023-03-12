#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<bool>> visit;

int algo(int a,int b,vector<string> m){
    if(a < 0 || b < 0 || a >= visit.size() || b >= visit[0].size()) return 0;
    if(visit[a][b] == true || m[a][b] == 'X') return 0;
    visit[a][b] = true;
    return (m[a][b]-'0') + algo(a-1,b,m) + algo(a+1,b,m) + algo(a,b-1,m) + algo(a,b+1,m);
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    visit.resize(maps.size(),vector<bool>(maps[0].size(),false));
    
    for(int i = 0;i < maps.size();i++){
        for(int j = 0;j < maps[i].size();j++){
            if(visit[i][j] == false && maps[i][j] != 'X') answer.push_back(algo(i,j,maps));
        }
    }
    
    sort(answer.begin(),answer.end());
    
    if(answer.size() == 0) answer.push_back(-1);
    
    return answer;
}
