#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int c1,c2;
    c1 = c2 = 0;
    for(int i = 0;i < goal.size();i++){
        if(goal[i] == cards1[c1]){
            c1++;
            continue;
        }
        else if(goal[i] == cards2[c2]){
            c2++;
            continue;
        }
        else return "No";
    }
    return "Yes";
}
