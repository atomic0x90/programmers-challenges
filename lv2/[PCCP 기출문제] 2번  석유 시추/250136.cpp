#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land) {
    vector<int> landValue(land[0].size(),0);
    
    for(int i = 0;i < land.size();i++){
        for(int j = 0;j < land[i].size();j++){
            if(land[i][j] == 0 || land[i][j] == 2) continue;
            int minNum = j;
            int maxNum = j;
            int amount = 0;
            queue<pair<int,int>> q;
            q.push(make_pair(i,j));
            while(!q.empty()){
                int ti = q.front().first;
                int tj = q.front().second;
                q.pop();
                
                if(land[ti][tj] == 2) continue;
                
                minNum = minNum > tj ? tj : minNum;
                maxNum = maxNum < tj ? tj : maxNum;
                
                amount++;
                land[ti][tj] = 2;
                
                if(ti != 0 && land[ti-1][tj] == 1) q.push(make_pair(ti-1,tj));
                if(ti != land.size()-1 && land[ti+1][tj] == 1) q.push(make_pair(ti+1,tj));
                if(tj != 0 && land[ti][tj-1] == 1) q.push(make_pair(ti,tj-1));
                if(tj != land[i].size()-1 && land[ti][tj+1] == 1) q.push(make_pair(ti,tj+1));
            }
            
            for(int k = minNum;k <= maxNum;k++) landValue[k] += amount;
            
        }
    }
    
    return *max_element(landValue.begin(),landValue.end());
}
