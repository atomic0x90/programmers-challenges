#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    sort(lottos.begin(),lottos.end());
    sort(win_nums.begin(),win_nums.end());
    
    int checkZero = 0;
    int checkWin = 0;
    int Max,Min;
    for(int i = 0;i < lottos.size();i++){
        if(lottos[i] == 0) checkZero++;
        else break;
    }
    for(int i = 0;i < lottos.size();i++){
        if(lottos[i] != 0){
            for(int j = 0;j < win_nums.size();j++){
                if(lottos[i] == win_nums[j]){
                    checkWin++;
                    break;
                }
            }
        }
    }
    
    if(checkWin == 6) Min = 1;
    else if(checkWin == 5) Min = 2;
    else if(checkWin == 4) Min = 3;
    else if(checkWin == 3) Min = 4;
    else if(checkWin == 2) Min = 5;
    else Min = 6;
    
    int check = checkWin + checkZero;
    
    if(check == 6) Max = 1;
    else if(check == 5) Max = 2;
    else if(check == 4) Max = 3;
    else if(check == 3) Max = 4;
    else if(check == 2) Max = 5;
    else Max = 6;
    
    answer.push_back(Max);
    answer.push_back(Min);
    
    return answer;
}
