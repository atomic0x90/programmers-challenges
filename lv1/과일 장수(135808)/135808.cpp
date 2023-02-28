#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(),score.end());
    while(score.size() >= m){
        vector<int> v;
        for(int i = 0;i < m;i++){
            v.push_back(score.back());
            score.pop_back();
        }
        answer += v.back()*m;
    }
    return answer;
}
