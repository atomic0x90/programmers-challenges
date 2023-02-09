#include <vector>
#include <math.h>

using namespace std;

int solution(vector<vector<int>> dots) {
    return abs(max(abs(dots[0][0]-dots[1][0]),abs(dots[0][0]-dots[2][0]))) * abs(max(abs(dots[0][1]-dots[1][1]),abs(dots[0][1]-dots[2][1])));
}
