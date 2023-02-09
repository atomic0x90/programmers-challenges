#include <string>
#include <sstream>

using namespace std;

int solution(string s) {
    int answer = 0;
    stringstream ss(s);
    int num;
    
    ss>>num;
    while(ss>>s){
        if(s == "Z") num = 0;
        else{
            answer += num;
            num = stoi(s);
        }
    }
    
    return answer+num;
}
