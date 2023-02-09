#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    int maxValue = max(sides[0],sides[1]);
    int minValue = min(sides[0],sides[1]);
    for(int i = 1;i < 2001;i++){
        if(maxValue >= i && minValue + i > maxValue) answer++;
        if(maxValue < i && maxValue + minValue > i) answer++;
    }
    
    return answer;
}
