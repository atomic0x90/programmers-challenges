#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(),routes.end());
    
    int check = routes[0][1];
    
    for(int i = 0;i < routes.size();i++){
        if(routes[i][0] > check){
            answer++;
            check = routes[i][1];
            continue;
        }
        
        if(check > routes[i][1]) check = routes[i][1];
    }
    return answer;
}
