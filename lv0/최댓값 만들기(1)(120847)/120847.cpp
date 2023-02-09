#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    auto iter = max_element(numbers.begin(),numbers.end());
    int answer = *iter;
    *iter = 0;
    
    return answer*(*max_element(numbers.begin(),numbers.end()));
}
