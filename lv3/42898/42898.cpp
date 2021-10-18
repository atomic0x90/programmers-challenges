#include <string>
#include <vector>
#include <utility>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles){
    vector<vector<int> > v(n+1,vector<int>(m+1,0));
    vector<vector<pair<int,int> > > result(n+1,vector<pair<int,int> >(m+1));
    
    result[1][1].first = 1;
    result[1][1].second = 1;

    for(int i = 0;i < puddles.size();i++) v[puddles[i][1]][puddles[i][0]] = -1;
    
    for(int i = 2;i <= n;i++){
        if(v[i-1][1] == -1){
            v[i][1] = -1;
            result[i][1].first = -1;
            result[i][1].second = 0;
        }
    }
    for(int i = 2;i <= m;i++){
        if(v[1][i-1] == -1){
            v[1][i] = -1;
            result[1][i].first = -1;
            result[1][i].second = 0;
        }
    }
    

    for(int i = 1;i <= m;i++){
        if(v[1][i] == 0){
            v[1][i] = i;
            result[1][i].first = i;
            result[1][i].second = 1;
        }
    }
    for(int i = 1;i <= n;i++){
        if(v[i][1] == 0){
            v[i][1] = i;
            result[i][1].first = i;
            result[i][1].second = 1;
        }
    }
    
    for(int i = 2;i <= n;i++){
        for(int j = 2;j <= m;j++){
            if(v[i][j] == -1) continue;
            
            if(v[i-1][j] == -1 && v[i][j-1] == -1){
                v[i][j] = -1;
                result[i][j].first = -1;
                result[i][j].second = 0;
            }
            else if(v[i-1][j] != -1 && v[i][j-1] == -1){
                v[i][j] = v[i-1][j]+1;
                result[i][j].first = result[i-1][j].first+1;
                result[i][j].second = result[i-1][j].second;
            }
            else if(v[i-1][j] == -1 && v[i][j-1] != -1){
                v[i][j] = v[i][j-1]+1;
                result[i][j].first = result[i][j-1].first+1;
                result[i][j].second = result[i][j-1].second;
            }
            else if(v[i-1][j] != -1 && v[i][j-1] != -1){
                if(result[i][j-1].first < result[i-1][j].first){
                    v[i][j] = v[i][j-1]+1;
                    result[i][j].first = result[i][j-1].first+1;
                    result[i][j].second = result[i][j-1].second;
                }
                else if(result[i][j-1].first > result[i-1][j].first){
                    v[i][j] = v[i-1][j]+1;
                    result[i][j].first = result[i-1][j].first+1;
                    result[i][j].second = result[i-1][j].second;
                }
                else if(result[i][j-1].first == result[i-1][j].first){
                    v[i][j] = v[i-1][j]+1;
                    result[i][j].first = result[i-1][j].first+1;
                    result[i][j].second = (result[i-1][j].second + result[i][j-1].second)%1000000007;
                }
            }
            
        }
    }
    
    return result[n][m].second;
}
