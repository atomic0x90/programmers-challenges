#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    stack<int> s;
    s.push(numbers.back());
    answer.back() = -1;
    
    for(int i = numbers.size()-2;i >= 0;i--){
        if(s.top() > numbers[i]){
            answer[i] = s.top();
            s.push(numbers[i]);
        }
        else{
            while(!s.empty()){
                if(s.top() <= numbers[i]) s.pop();
                else break;
            }
            if(s.empty()) answer[i] = -1;
            else answer[i] = s.top();
            
            s.push(numbers[i]);
        }
    }
    return answer;
}
