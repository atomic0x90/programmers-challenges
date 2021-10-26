#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int r = s%n;
    int num = s/n;
    if(num == 0) answer.push_back(-1);
    else{
        for(int i = 0;i < n;i++) answer.push_back(num);
        if(r){
            int check = answer.size()-1;
            while(r){
                answer[check--]++;
                r--;
            }
        }
    }
    return answer;
}
