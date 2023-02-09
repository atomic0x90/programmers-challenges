#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer = {0,0};
    int maxX = board[0]/2;
    int maxY = board[1]/2;
    for(int i = 0;i < keyinput.size();i++){
        if(keyinput[i] == "up" && answer[1] < maxY) answer[1]++;
        else if(keyinput[i] == "down" && answer[1] > -maxY) answer[1]--;
        else if(keyinput[i] == "left" && answer[0] > -maxX) answer[0]--;
        else if(keyinput[i] == "right" && answer[0] < maxX) answer[0]++;
    }
    return answer;
}
