#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const int &a,const int &b){
    return a > b;
}

long long solution(long long n) {
    long long answer = 0;
    vector <int> tmp;
    while(n > 0){
        tmp.push_back(n%10);
        n /= 10;
    }
    sort(tmp.begin(),tmp.end(),compare);
    for(int i = 0;i < tmp.size();i++)
        answer = answer*10 + tmp[i];
    return answer;
}
