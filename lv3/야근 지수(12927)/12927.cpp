#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    sort(works.begin(),works.end(),greater<int>());
    
    while(n){
        if(works.front() == 0) break;
        
        int check = works.front();
        
        for(int i = 0;i < works.size();i++){
            if(!n) break;
            if(check == works[i]){
                works[i]--;
                n--;
            }
            else{
                if(i != works.size()-1){
                    if(works[i] < works[i+1]) sort(works.begin(),works.end(),greater<int>());
                }
                break;
            }
        }
    }
    
    for(int i = 0;i < works.size();i++) answer += pow(works[i],2);

    return answer;
}
