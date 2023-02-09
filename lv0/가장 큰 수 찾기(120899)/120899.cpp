#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    auto iter = max_element(array.begin(),array.end());
    answer.push_back(*iter);
    answer.push_back(iter-array.begin());
    return answer;
}
