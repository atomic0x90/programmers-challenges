#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    for(int i = 0;i < photo.size();i++){
        int sum = 0;
        for(int j = 0;j < photo[i].size();j++){
            auto iter = find(name.begin(),name.end(),photo[i][j]);
            if(iter != name.end()){
                int index = iter - name.begin();
                sum += yearning[index];
            }
        }
        answer.push_back(sum);
    }
    return answer;
}
