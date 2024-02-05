#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    vector<vector<int>> v(friends.size(),vector<int>(friends.size(),0));
    vector<vector<int>> result(friends.size(),vector<int>(3,0));
    vector<int> answer(friends.size(),0);
    
    for(int i = 0;i < gifts.size();i++){
        stringstream ss(gifts[i]);
        string giver, receiver;
        ss>>giver>>receiver;
        
        int giverIndex = find(friends.begin(),friends.end(),giver)-friends.begin();
        int receiverIndex = find(friends.begin(),friends.end(),receiver)-friends.begin();
        
        v[giverIndex][receiverIndex]++;
        
        result[giverIndex][0]++;
        result[receiverIndex][1]++;
        result[giverIndex][2]++;
        result[receiverIndex][2]--;
    }
    
    for(int i = 0;i < v.size();i++){
        for(int j = 0;j < v[i].size();j++){
          if(i == j) continue;
            //선물을 주고받은 기록이 있다면
          if((v[i][j] != 0 || v[j][i] != 0) && v[i][j] != v[j][i]){
              if(v[i][j] > v[j][i]) answer[i]++;
            }
            //선물을 주고받은 기록이 없다면, 같다면
          else{
              if(result[i][2] > result[j][2]) answer[i]++;
            }
        }
    }
    
    return *max_element(answer.begin(),answer.end());
}
