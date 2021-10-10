#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> v;
    for(int i = 0;i < operations.size();i++){
        if(operations[i][0] == 'I'){
            operations[i][0] = ' ';
            v.push_back(stoi(operations[i]));
            sort(v.begin(),v.end());
        }
        else{
            if(operations[i][2] == '1'){
                if(v.size() != 0) v.pop_back();
            }
            else{
                if(v.size() != 0) v.erase(v.begin(),v.begin()+1);
            }
        }
    }
    if(v.size() == 0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(v.back());
        answer.push_back(v.front());
    }
    return answer;
}
