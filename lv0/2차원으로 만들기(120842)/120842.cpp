#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer(num_list.size()/n + (num_list.size()%n != 0 ? 1 : 0),vector<int>(n,0));
    int check = 0;
    for(int i = 0;i < answer.size();i++){
        for(int j = 0;j < answer[i].size();j++)
            answer[i][j] = num_list[check++];
    }
    return answer;
}
