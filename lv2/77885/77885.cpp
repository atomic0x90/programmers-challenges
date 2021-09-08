#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(int i = 0;i < numbers.size();i++){
        if(numbers[i] % 2 == 0) answer.push_back(numbers[i]+1);
        else{
            long long n = numbers[i];
            int bit = 0;
            while(true){
                if(n & 1) bit++;
                else break;
                n = n >> 1;
            }
            answer.push_back(numbers[i] + pow(2,bit) - pow(2,bit-1));
        }
    }
    
    return answer;
}
