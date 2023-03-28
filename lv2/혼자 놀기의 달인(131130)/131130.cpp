#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    vector<int> group;
    vector<bool> visit(cards.size(),false);

    while(true){
        int check = 0;
        bool flag = true;
    
        for(int i = 0;i < cards.size();i++){
            if(!visit[i]){
                flag = false;
                int index = i;
                while(!visit[index]){
                    check++;
                    visit[index] = true;
                    index = cards[index] - 1;            
                }
                break;
            }
        }
        
        if(flag) break;
        group.push_back(check);
    }
    
    sort(group.begin(),group.end(),greater<int>());
    
    return group.size() == 1 ? 0 : group[0]*group[1];
}
