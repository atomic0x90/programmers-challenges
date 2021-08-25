#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int result = 1;
    map <string,int> m;
    
    for(int i = 0;i < clothes.size();i++){
        if(m.find(clothes[i][1]) == m.end()) m.insert(make_pair(clothes[i][1],1));
        else m.find(clothes[i][1])->second++;
    }
    
    for(auto iter = m.begin();iter != m.end();iter++) result *= iter->second + 1;
    
    return result-1;
}
