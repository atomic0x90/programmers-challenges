#include <vector>
using namespace std;

int solution(vector<vector<int> > land){
    int answer = 0;
    vector<vector<int> > v(land.size(),vector<int>(4,0));
    for(int i = 0;i < 4;i++) v[land.size()-1][i] = land[land.size()-1][i];
    
    //bottom up
    for(int i = land.size()-2;i > -1;i--){
        for(int j = 0;j < 4;j++){
            for(int l = 0;l < 4;l++){
                if(j != l){
                    if(v[i][j] < v[i+1][l] + land[i][j]) v[i][j] = v[i+1][l] + land[i][j];
                }
            }
        }
    }
    for(int i = 0;i < 4;i++){
        if(v[0][i] > answer) answer = v[0][i];
    }

    return answer;
}
