#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    int X,Y,Z;
    char pm,eq;
    
    for(int i = 0;i < quiz.size();i++){
        stringstream ss(quiz[i]);
        ss>>X;
        ss>>pm;
        ss>>Y;
        ss>>eq;
        ss>>Z;
        if(pm == '+') X+Y == Z ? answer.push_back("O") : answer.push_back("X");
        if(pm == '-') X-Y == Z ? answer.push_back("O") : answer.push_back("X");
    }
    
    return answer;
}
