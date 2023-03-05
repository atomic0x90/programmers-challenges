#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int box = 1;
    vector<int> belt;
    
    for(int i = 0;i < order.size();){
        if(order[i] == box){
            answer++;
            box++;
            i++;
            continue;
        }
        if(belt.size() != 0){
            if(belt.back() == order[i]){
                answer++;
                belt.pop_back();
                i++;
                continue;
            }
            
            if(find(belt.begin(),belt.end(),order[i]) != belt.end()) break;
            else{
                while(box != order[i]) belt.push_back(box++);
            }
        }
        else while(box != order[i]) belt.push_back(box++);
    }
    
    return answer;
}
