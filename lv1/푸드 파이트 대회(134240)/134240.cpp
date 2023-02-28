#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string back = "";
    for(int i = 1;i < food.size();i++){
        int num = food[i]/2;
        for(int j = 0;j < num;j++){
            answer += to_string(i);
            back = to_string(i) + back;
        }
    }
    return answer+'0'+back;
}
