#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    for(int i = 0;i < targets.size();i++){
        int sum = 0;
        bool flag = false;
        
        for(int j = 0;j < targets[i].size();j++){   
            int tmp = 1000;
        
            for(int k = 0;k < keymap.size();k++){
                if(keymap[k].find(targets[i][j]) != string::npos){
                    if(tmp > keymap[k].find(targets[i][j])+1) tmp = keymap[k].find(targets[i][j])+1;
                }
            }
            
            if(tmp == 1000){
                flag = true;
                break;
            }
            else sum += tmp;
        }
        if(flag) answer.push_back(-1);
        else answer.push_back(sum);
    }
    return answer;
}
