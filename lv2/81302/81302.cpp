#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> v;
vector<vector<int> > visit;

int algo(int a,int b,int dis){
    if(visit[a][b] == 1) return 1;
    if(dis > 2) return 1;
    if(v[a][b] == 'X') return 1;
    if(v[a][b] == 'P' && dis != 0) return 0;
    
    visit[a][b] = 1;
    int check;
    
    if(a-1 >= 0){
        check = algo(a-1,b,dis+1);
        if(check == 0) return 0;
    }
    if(a+1 < 5){
        check = algo(a+1,b,dis+1);
        if(check == 0) return 0;
    }
    if(b-1 >= 0){
        check = algo(a,b-1,dis+1);
        if(check == 0) return 0;
    }
    if(b+1 < 5){
        check = algo(a,b+1,dis+1);
        if(check == 0) return 0;
    }
    
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for(int i = 0;i < places.size();i++){
        v = places[i];
        int flag = 1;
        for(int j = 0;j < 5;j++){
            for(int k = 0;k < 5;k++){
                if(v[j][k] == 'P'){
                    vector<vector<int> > tmp(5,vector<int>(5,0));
                    visit = tmp;
                    flag = algo(j,k,0);
                    if(flag == 0) break;
                }
            }
            if(flag == 0) break;
        }
        if(flag == 0) answer.push_back(0);
        else answer.push_back(1);
    }
    return answer;
}
