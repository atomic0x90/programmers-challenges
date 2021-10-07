#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> visit(computers.size(),0);
    queue<int> q;
    
    for(int i = 0;i < computers.size();i++){
        if(visit[i] == 1) continue;
        
        q.push(i);
        while(!q.empty()){
            int f = q.front();
            for(int j = 0;j < computers.size();j++){
                if(f == j) continue;
                
                if(computers[f][j] && visit[j] == 0){
                    q.push(j);
                    visit[j] = 1;
                }
            }
            q.pop();
        }
        answer++;
    }
    return answer;
}
