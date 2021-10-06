#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int> > win(n+1);  //내가 이김 a,b
    vector<vector<int> > lose(n+1); //상대가 짐 b,a
    for(int i = 0;i < results.size();i++){
        if(find(win[results[i][0]].begin(),win[results[i][0]].end(),results[i][1]) == win[results[i][0]].end())
            win[results[i][0]].push_back(results[i][1]);
        if(find(lose[results[i][1]].begin(),lose[results[i][1]].end(),results[i][0]) == lose[results[i][1]].end())
            lose[results[i][1]].push_back(results[i][0]);
    }
    for(int l = 0;l < n;l++){
        for(int i = 0;i < results.size();i++){
            for(int j = 0;j < win[results[i][1]].size();j++){
                if(find(win[results[i][0]].begin(),win[results[i][0]].end(),win[results[i][1]][j]) == win[results[i][0]].end())
                    win[results[i][0]].push_back(win[results[i][1]][j]);
            }

            for(int j = 0;j < lose[results[i][0]].size();j++){
                 if(find(lose[results[i][1]].begin(),lose[results[i][1]].end(),lose[results[i][0]][j]) == lose[results[i][1]].end())
                    lose[results[i][1]].push_back(lose[results[i][0]][j]);
            }
        }
    }
    
    for(int i = 1;i <= n;i++){
        if(win[i].size() + lose[i].size() == n-1) answer++;
    }
    
    
    return answer;
}
