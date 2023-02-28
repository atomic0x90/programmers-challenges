#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> x(10,0);
    vector<int> y(10,0);
    for(int i = 0;i < X.size();i++) x[X[i]-'0']++;

    for(int i = 0;i < Y.size();i++){
        if(x[Y[i]-'0'] > 0){
            answer += Y[i];
            x[Y[i]-'0']--;
        }
    }
    
    sort(answer.begin(),answer.end(),greater<char>());
    if(answer.size() == 0) return "-1";
    else if(answer[0] == '0') return "0";
    else return answer;
}
