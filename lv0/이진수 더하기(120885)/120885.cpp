#include <string>
#include <vector>
#include <math.h>

using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    int b1,b2;
    b1 = b2 = 0;

    for(int i = 0;i < bin1.size();i++)
        if(bin1[i] == '1') b1 += pow(2,bin1.size()-i-1);
    
    for(int i = 0;i < bin2.size();i++)
        if(bin2[i] == '1') b2 += pow(2,bin2.size()-i-1);
    
    int sum = b1+b2;
    if(sum == 0) return "0";
    
    while(sum > 0){
        answer = to_string(sum%2) + answer;
        sum /= 2;
    }
    
    return answer;
}
