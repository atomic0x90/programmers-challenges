#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min = *min_element(arr.begin(),arr.end());
    if(arr.size() != 1){
        for(int i = 0;i < arr.size();i++){
            if(arr[i] != min) answer.push_back(arr[i]);
        }
    }
    else answer.push_back(-1);
    return answer;
}
