#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    while(age){
        char ch = 'a'+age%10;
        answer = ch+answer;
        age /= 10;
    }
    return answer;
}
