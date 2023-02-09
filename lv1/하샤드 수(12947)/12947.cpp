#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int h = 0,tx = x;
    while(tx != 0){
        h += tx % 10;
        tx /= 10;
    }
    return (x % h == 0) ? answer : !answer;
}
