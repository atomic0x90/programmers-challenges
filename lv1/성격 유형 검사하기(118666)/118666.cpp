#include <string>
#include <vector>

using namespace std;

int R = 0;
int T = 0;
int C = 0;
int F = 0;
int J = 0;
int M = 0;
int A = 0;
int N = 0;

void algo(char c,int val){
    if(c == 'R') R += val;
    else if(c == 'T') T += val;
    else if(c == 'C') C += val;
    else if(c == 'F') F += val;
    else if(c == 'J') J += val;
    else if(c == 'M') M += val;
    else if(c == 'A') A += val;
    else if(c == 'N') N += val;
    
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    for(int i = 0;i < survey.size();i++){
        if(choices[i] < 4){
            algo(survey[i][0],abs(4-choices[i]));
        }
        else{
            algo(survey[i][1],abs(4-choices[i]));
        }
    }
    
    if(R >= T) answer += "R";
    else answer += "T";
    
    if(C >= F) answer += "C";
    else answer += "F";
    
    if(J >= M) answer += "J";
    else answer += "M";
    
    if(A >= N) answer += "A";
    else answer += "N";
    
    return answer;
}
