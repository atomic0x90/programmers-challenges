#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> visit(n,0);
    visit[0] = 1;
    
    vector<vector<int> >v(n,vector<int>(n,0));
    
    for(int i = 0;i < costs.size();i++){
        v[costs[i][0]][costs[i][1]] = costs[i][2];
        v[costs[i][1]][costs[i][0]] = costs[i][2];
    }
    
    while(find(visit.begin(),visit.end(),0) != visit.end()){
        int x,y;
        int num = INT_MAX;
        for(int i = 0;i < visit.size();i++){
            if(visit[i] == 1){
                for(int j = 0;j < v[i].size();j++){
                    if(visit[j] == 0 && v[i][j] <= num && v[i][j] != 0){
                        num = v[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        visit[y] = 1;
        answer += v[x][y];
    }
    
    return answer;
}
