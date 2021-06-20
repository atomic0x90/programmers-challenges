#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
bool compare(const string &a,const string &b){
    if(a[N] < b[N]) return true;
    else if(a[N] > b[N]) return false;
    else return a < b;
}

vector<string> solution(vector<string> strings, int n) {
    N = n;
    sort(strings.begin(),strings.end(),compare);
    vector<string> answer = strings;
    return answer;
}
