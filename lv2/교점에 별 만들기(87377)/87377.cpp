#include <string>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<pair<long long,long long>> value;
    long long top = LLONG_MIN, bottom = LLONG_MAX, left = LLONG_MAX, right = LLONG_MIN;
    long long A,B,C,D,E,F;
    
    for(int i = 0;i < line.size();i++){
        for(int j = i+1;j < line.size();j++){
            A = (long long)(line[i][0]);
            B = (long long)(line[i][1]);
            C = (long long)(line[j][0]);
            D = (long long)(line[j][1]);
            E = (long long)(line[i][2]);
            F = (long long)(line[j][2]);
            if((A*D) - (B*C) == 0) continue;
            
            double x = (double)((B*F) - (E*D))/(double)((A*D) - (B*C));
            double y = (double)((E*C) - (A*F))/(double)((A*D) - (B*C));
            if( !(x - (long long)(x)) && !(y - (long long)(y)) ){
                if(top < (long long)(y)) top = (long long)(y);
                if(bottom > (long long)(y)) bottom = (long long)(y);
                if(left > (long long)(x)) left = (long long)(x);
                if(right < (long long)(x)) right = (long long)(x);

                value.push_back(make_pair(x,y));
            }
        }
    }
    
    if(top == LLONG_MIN) top = bottom;
    if(bottom == LLONG_MAX) bottom = top;
    if(left == LLONG_MAX) left = right;
    if(right == LLONG_MIN) right = left;
    
    for(long long i = bottom;i <= top;i++){
        string s = "";
        for(long long j = left;j <= right;j++) s += ".";
        
        answer.push_back(s);
    }
    
    for(long long i = 0;i < value.size();i++){
        long long tx,ty;
        tx = value[i].first - left;
        ty = value[i].second - bottom;
        
        answer[ty][tx] = '*';
    }
    reverse(answer.begin(),answer.end());
    return answer;
}
