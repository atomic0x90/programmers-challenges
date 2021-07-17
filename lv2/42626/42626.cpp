#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int m1,m2;
    priority_queue<int,vector<int>,greater<int> >q;
    for(int i = 0;i < scoville.size();i++)
        q.push(scoville[i]);
    while(K > q.top()){
        if(q.size() == 1) return -1;
        m1 = q.top();
        q.pop();
        m2 = q.top();
        q.pop();
        q.push(m1+m2*2);
        
        answer++;
    }
    return answer;
}
