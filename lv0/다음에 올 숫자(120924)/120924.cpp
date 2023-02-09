#include <vector>
#include <math.h>
using namespace std;

int solution(vector<int> common) {
    if(abs(common[0]-common[1]) == abs(common[1]-common[2])) return common.back() + common[1] - common[0];

    return common.back() * (common[1]/common[0]);
}
