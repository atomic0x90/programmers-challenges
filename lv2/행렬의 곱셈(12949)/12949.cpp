#include <string>
#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(),vector<int>(arr2[0].size(),0));

    for(int i = 0;i < answer.size();i++){
        for(int j = 0;j < answer[i].size();j++){
            int sum = 0;
            
            for(int k = 0;k < arr1[i].size();k++){
                for(int l = 0;l < arr2.size();l++){
                    if(k == l) sum += arr1[i][k] * arr2[l][j];
                }
            }
            answer[i][j] = sum;
        }
    }
    return answer;
}
