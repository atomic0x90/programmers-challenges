#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i = 0;i < skill_trees.size();i++){
        int flag = 0;
        vector<int> num(skill.size(),-1);
        
        for(int j = 0;j < skill.size();j++){
            int check = -1;
            
            for(int k = 0;k < skill_trees[i].size();k++){
                if(skill[j] == skill_trees[i][k]){
                    check = k;
                    break;
                }
            }
            num[j] = check;
        }
        
        if(num.size() == 1) answer++;
        else{
            for(int j = 1;j < num.size();j++){
                if(num[j-1] != -1 && num[j-1] < num[j] || num[j] == -1) continue;
                else{
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) answer++;
        }
    }
    return answer;
}
