#include <string>
#include <vector>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    string s = "";
    for(int i = 0;i < ingredient.size();i++){
        s += (ingredient[i] == 1 ? '1' : (ingredient[i] == 2 ? '2' : '3'));
        
        if(s.size() < 4) continue;
        if(s.substr(s.size()-4) == "1231"){
            answer++;
            s = s.substr(0,s.size()-4);
        }
    }
    return answer;
}
