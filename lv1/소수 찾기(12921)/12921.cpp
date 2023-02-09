#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    vector <int> check(n+1);
    int answer = 0;
    for(int i = 2;i <= sqrt(n);i++){
        if(check[i] == 0){
            for(int j = 2;j*i <= n;j++)
                check[j*i] = 1;
        }
    }
    for(int i = 2;i <= n;i++)
        if(check[i] == 0) answer++;
    
    return answer;
}
