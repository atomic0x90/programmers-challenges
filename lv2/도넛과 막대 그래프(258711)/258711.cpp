#include <string>
#include <vector>

using namespace std;

vector<vector<int>> v(1000002,vector<int>(0));
vector<int> in(1000002,0);

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4,0);
    int maxNum = 0;
    
    for(int i = 0;i < edges.size();i++){
        if(maxNum < edges[i][0]) maxNum = edges[i][0];
        if(maxNum < edges[i][1]) maxNum = edges[i][1];
        in[edges[i][1]]++;
        
        v[edges[i][0]].push_back(edges[i][1]);
    }
    
    for(int i = 1;i <= maxNum;i++){
        if(in[i] == 0 && v[i].size() >= 2) answer[0] = i;
    }
    
    for(int i = 0;i < v[answer[0]].size();i++){
        int start = v[answer[0]][i];
        
        while(true){
            if(v[start].size() == 0){
                answer[2]++;
                break;
            }
            if(v[start].size() >= 2){
                answer[3]++;
                break;
            }
            start = v[start][0];
            if(start == v[answer[0]][i]){
                answer[1]++;
                break;
            }
        }
    }
    
    return answer;
}
