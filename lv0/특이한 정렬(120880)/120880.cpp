#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int N;

bool compare(const int &a, const int &b){
    if(abs(a-N) == abs(b-N)) return a > b;
    else return abs(a-N) < abs(b-N);
}

vector<int> solution(vector<int> numlist, int n) {
    N = n;
    sort(numlist.begin(),numlist.end(),compare);
    return numlist;
}
