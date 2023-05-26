#include <vector>
#include <climits>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(INT_MAX);
    
    long long all = 0;
    for(int i = 0;i < sequence.size();i++) all += sequence[i];
    
    int sum = 0;
    int start = 0;
    int end = -1;
    while(answer[1]-answer[0] != 0 && all >= k){
        if(sum < k){
            sum += sequence[++end];
        }
        else if(sum == k){
            if(answer[1] - answer[0] > end - start){
                answer[0] = start;
                answer[1] = end;
            }
            sum -= sequence[start];
            all -= sequence[start];
            start++;
            sum -= sequence[end];
            end--;
        }
        else{
            sum -= sequence[start];
            all -= sequence[start];
            start++;
            sum -= sequence[end];
            end--;
        }
    }
    return answer;
}
