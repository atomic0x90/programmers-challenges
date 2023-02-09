#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    vector<int> v(201,0);
    
    for(int i = 0;i < lines.size();i++){
        lines[i][0] += 100;
        lines[i][1] += 100;
        for(int j = lines[i][0];j < lines[i][1];j++) v[j]++;
    }
    for(int i = 0;i < v.size();i++){
        if(v[i] >= 2) answer++;
    }
    
    return answer;
}
