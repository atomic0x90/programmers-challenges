#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    int check = 0;
    for(int i = 0;i < seoul.size();i++){
        if(seoul[i] == "Kim"){
            check = i;
            break;
        }
    }
    string c = to_string(check);
    string answer = "김서방은 "+c+"에 있다";
    return answer;
}
