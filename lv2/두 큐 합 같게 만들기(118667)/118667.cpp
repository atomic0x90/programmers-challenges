#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int qSize = queue1.size()*2;
    int f1 = 0,f2 = 0;
    long long sum,sum1 = 0,sum2 = 0;
    
    for(int i = 0;i < queue1.size();i++) sum1 += queue1[i];
    for(int i = 0;i < queue2.size();i++) sum2 += queue2[i];
    
    sum = (sum1 + sum2)/2;
    
    if((sum1+sum2)%2 == 1) return -1;
    
    while(f1 != qSize && f2 != qSize && sum != sum1){
        if(sum1 < sum2){
            sum1 += queue2[f2];
            sum2 -= queue2[f2];
            queue1.push_back(queue2[f2]);
            f2++;
        }
        else{
            sum1 -= queue1[f1];
            sum2 += queue1[f1];
            queue2.push_back(queue1[f1]);
            f1++; 
        }
        answer++;
    }
    
    return f1 != qSize && f2 != qSize ? answer : -1;
}
