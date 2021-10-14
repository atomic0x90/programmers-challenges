#include <string>
#include <vector>

using namespace std;

int solution(int n){
    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;
    for(int j = 3;j <= n;j++){
        dp[j] = dp[j-1] + dp[j-2];
        dp[j] %= 1000000007;
    }
    return dp.back();
}
