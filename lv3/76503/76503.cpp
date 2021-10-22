#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
long long result = 0;

void algo(vector<vector<int> > &line,vector<long long> &a,int node,int par){
    for(int i = 0;i < line[node].size();i++){
        if(line[node][i] == par) continue;
        algo(line,a,line[node][i],node);
    }
    
    result += abs(a[node]);
    a[par] += a[node];
    
    return;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    if(*max_element(a.begin(),a.end()) == 0) return 0;
    long long answer = 0;
    
    vector<long long> la(a.begin(),a.end());
    
    vector<vector<int> > line(a.size());
    
    for(int i = 0;i < edges.size();i++){
        line[edges[i][0]].push_back(edges[i][1]);
        line[edges[i][1]].push_back(edges[i][0]);
    }
    
    algo(line,la,0,0);
    
    return la[0] == 0 ? result : -1;
}
