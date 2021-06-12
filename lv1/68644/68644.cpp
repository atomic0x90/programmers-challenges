#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<int> add;
    
    sort(numbers.begin(),numbers.end());
    
    for(int i = 0;i < numbers.size();i++){
        for(int j = i+1;j < numbers.size();j++)
            add.push_back(numbers[i]+numbers[j]);
    }
    
    sort(add.begin(),add.end());
    
    for(int i = 0;i < add.size();i++){
        if(answer.empty()) answer.push_back(add[i]);
        else{
            if(answer.back() != add[i])
                answer.push_back(add[i]);
        }
    }
    
    return answer;
}
