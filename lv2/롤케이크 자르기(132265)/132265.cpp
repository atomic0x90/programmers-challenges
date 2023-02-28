#include <vector>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    vector<int> v1(10001,0),v2(10001,0);
    int num1 = 0,num2 = 0;
    
    for(int i = 0;i < topping.size();i++){
        if(v2[topping[i]] == 0) num2++;
        
        v2[topping[i]]++;
    }
    
    for(int i = 0;i < topping.size()-1;i++){
        if(v1[topping[i]] == 0) num1++;
        if(v2[topping[i]] == 1) num2--;
        
        v1[topping[i]]++;
        v2[topping[i]]--;
        
        if(num1 == num2) answer++;
    }
    
    return answer;
}
