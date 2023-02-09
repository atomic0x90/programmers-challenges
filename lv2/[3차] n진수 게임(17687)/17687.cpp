#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    string s = "0";
    for(int i = 1;i <= t*m;i++){
        int j = i;
        string tmp = "";
        while(j != 0){
            if(j%n < 10) tmp = to_string(j%n)+tmp;
            else{
                int rem = j%n;
                if(rem == 10) tmp = "A"+tmp;
                else if(rem == 11) tmp = "B"+tmp;
                else if(rem == 12) tmp = "C"+tmp;
                else if(rem == 13) tmp = "D"+tmp;
                else if(rem == 14) tmp = "E"+tmp;
                else if(rem == 15) tmp = "F"+tmp;
            }
            j /= n;
        }
        s += tmp;
    }
    
    int check = 0;
    while(answer.size() != t){
        answer += s[check+p-1];
        check += m;
    }
    
    return answer;
}
