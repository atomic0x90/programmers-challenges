#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector <int> notation;
    int check = 1;
    while(true){
        if(n == 0) break;
        notation.push_back(n % 3);
        n = n / 3;
    }
    while(!notation.empty()){
        answer += check * notation.back();
        notation.pop_back();
        check *= 3;
    }
    
    return answer;
}
