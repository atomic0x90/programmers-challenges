#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    reverse(section.begin(),section.end());
    
    while(section.size()){
        answer++;
        int start = section.back();
        while(section.size() && start+m > section.back()) section.pop_back();
    }
    return answer;
}
