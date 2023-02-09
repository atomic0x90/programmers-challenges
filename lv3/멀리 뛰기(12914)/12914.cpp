#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    if(n == 1) return 1;
    else if(n == 2) return 2;
    
    vector<long long> v(n+1,0);
    v[1] = 1;
    v[2] = 2;
    
    for(int i = 3;i <= n;i++) v[i] = (v[i-2] + v[i-1])%1234567;
    
    return v.back();
}
