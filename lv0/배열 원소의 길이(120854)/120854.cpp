#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> answer(strlist.size());
    for(int i = 0;i < answer.size();i++)
        answer[i] = strlist[i].size();
    return answer;
}
