#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int sum;
    int cisize = citations.size();
    map<int,int> m;
    
    for(int i = 0;i < cisize;i++){
        if(m.find(citations[i]) == m.end()) m.insert(make_pair(citations[i],1));
        else m.find(citations[i])->second++;
    }
    
   for(int i = 10000;i != -1;i--){
       sum = 0;
       for(auto iter = m.begin();iter != m.end();iter++){
           if(iter->first >= i) sum += iter->second;
       }
       
       if(i <= sum && cisize-sum <= i){
           answer = i;
           break;
       }
   }
    
    return answer;
}
