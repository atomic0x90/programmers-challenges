#include <string>
#include <vector>
#include <cmath>

using namespace std;

int answer = 0;
int N;

void algo(vector<int> &v,int now,int check){
    if(check == N){
        answer++;
        return;
    }
    
    for(int i = 1;i <= N;i++){
        int flag = 1;
        for(int j = 1;j < now;j++){
            if(v[j] == i || abs(v[j]-i) == abs(j-now) ){
                flag = 0;
                break;
            }
        }
        if(flag){
            v[now] = i;
            algo(v,now+1,check+1);
            v[now] = 0;
        }
    }
    return;
}

int solution(int n) {
    N = n;
    vector<int> v(n+1,0);
    algo(v,1,0);
    return answer;
}
