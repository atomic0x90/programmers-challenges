#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    vector<int> per(number.size(),0);
    per[per.size()-1] = per[per.size()-2] = per[per.size()-3] = 1;
    
    do{
        int sum = 0;
        
        for(int i = 0;i < per.size();i++)
            if(per[i] == 1) sum += number[i];
        
        if(sum == 0) answer++;
    
    }while(next_permutation(per.begin(),per.end()));
    
    return answer;
}
