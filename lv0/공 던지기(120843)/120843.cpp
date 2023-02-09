#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 1;
    
    while(--k) answer + 2 > numbers.size() ? answer = answer - numbers.size()+2 : answer += 2;
    
    return numbers[answer-1];
}
