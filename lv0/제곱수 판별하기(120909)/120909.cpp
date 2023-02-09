#include <math.h>

using namespace std;

int solution(int n) {
    int answer = sqrt(n);
    return pow(answer,2) == n ? 1 : 2;
}
