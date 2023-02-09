#include <vector>

using namespace std;

vector<int> answer(2);

vector<int> solution(vector<int> num_list) {
    for(int i = 0;i < num_list.size();i++)
        num_list[i]%2 == 0 ? answer[0]++ : answer[1]++;
    return answer;
}
